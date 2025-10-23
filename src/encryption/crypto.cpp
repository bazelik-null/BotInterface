#include <headers/encryption/crypto.h>
#include <sodium.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

// comments? nah, im too tired. maybe later (sorry, future me)

const std::string keyFilename = "key.bin";

void Crypto::createKey()
{
    if (std::filesystem::exists("key.bin")) {
        std::cout << "[INFO]: Key file already exists. Skipping key creation." << std::endl;
        return;
    }

    unsigned char key[crypto_secretbox_KEYBYTES];
    randombytes_buf(key, sizeof(key));

    std::ofstream outputFile(keyFilename, std::ios::binary);
    if (!outputFile) {
        std::cerr << "[ERROR]: Unable to open key file for writing Path: " << keyFilename << std::endl;
        perror("File error");
        return;
    }

    outputFile.write(reinterpret_cast<char*>(key), sizeof(key));
    if (!outputFile) {
        std::cerr << "[ERROR]: Failed to write key to file" << std::endl;
        return;
    }

    outputFile.close();
}

std::vector<unsigned char> Crypto::readKey()
{
    std::vector<unsigned char> key(crypto_secretbox_KEYBYTES);
    std::ifstream keyFile(keyFilename, std::ios::binary);
    if (!keyFile) {
        std::cerr << "[ERROR]: Unable to open key file for reading" << std::endl;
        return {};
    }
    keyFile.read(reinterpret_cast<char*>(key.data()), key.size());
    if (!keyFile) {
        std::cerr << "[ERROR]: Failed to read key from file" << std::endl;
    }
    keyFile.close();
    return key;
}

void Crypto::encrypt(const std::string& filename)
{
    createKey();

    std::vector<unsigned char> key = readKey();
    if (key.empty()) {
        std::cerr << "[ERROR]: Key could not be read. Exiting encryption" << std::endl;
        return;
    }

    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "[ERROR]: Unable to open input file for encryption" << std::endl;
        return;
    }
    std::string jsonData((std::istreambuf_iterator<char>(inputFile)),
                          std::istreambuf_iterator<char>());
    inputFile.close();

    std::vector<unsigned char> cipher(crypto_secretbox_MACBYTES + jsonData.size());

    unsigned char nonce[crypto_secretbox_NONCEBYTES];
    randombytes_buf(nonce, sizeof(nonce));

    crypto_secretbox_easy(cipher.data(),
                          reinterpret_cast<const unsigned char*>(jsonData.c_str()),
                          jsonData.size(),
                          nonce,
                          key.data());

    std::ofstream outputFile(filename, std::ios::binary);
    if (!outputFile) {
        std::cerr << "[ERROR]: Unable to open output file for writing" << std::endl;
        return;
    }
    outputFile.write(reinterpret_cast<char*>(nonce), sizeof(nonce));
    outputFile.write(reinterpret_cast<char*>(cipher.data()), cipher.size());
    outputFile.close();
}

void Crypto::decrypt(const std::string& filename)
{
    if (!std::filesystem::exists(keyFilename)) {
        std::cout << "[INFO]: Key file doesn't exist. Skipping decryption." << std::endl;
        return;
    }

    std::vector<unsigned char> key = readKey();
    if (key.empty()) {
        std::cerr << "[ERROR]: Key could not be read. Exiting decryption." << std::endl;
        return;
    }

    std::ifstream inputFile(filename, std::ios::binary);
    if (!inputFile) {
        std::cerr << "[ERROR]: Unable to open input file for decryption." << std::endl;
        return;
    }

    std::vector<unsigned char> nonce(crypto_secretbox_NONCEBYTES);
    inputFile.read(reinterpret_cast<char*>(nonce.data()), nonce.size());

    if (inputFile.gcount() != crypto_secretbox_NONCEBYTES) {
        std::cerr << "[ERROR]: Failed to read nonce from the file." << std::endl;
        return;
    }

    std::vector<unsigned char> cipher((std::istreambuf_iterator<char>(inputFile)),
                                       std::istreambuf_iterator<char>());

    inputFile.close();

    if (cipher.size() < crypto_secretbox_MACBYTES) {
        std::cerr << "[ERROR]: Cipher size is too small." << std::endl;
        return;
    }

    std::vector<unsigned char> decrypted(cipher.size() - crypto_secretbox_MACBYTES);

    if (crypto_secretbox_open_easy(decrypted.data(),
                                    cipher.data(),
                                    cipher.size(),
                                    nonce.data(),
                                    key.data()) != 0) {
        std::cerr << "[ERROR]: Decryption failed." << std::endl;
        return;
    }

    std::ofstream outputFile(filename, std::ios::binary);
    if (!outputFile) {
        std::cerr << "[ERROR]: Unable to open output file for writing." << std::endl;
        return;
    }
    outputFile.write(reinterpret_cast<char*>(decrypted.data()), decrypted.size());
    outputFile.close();
}
