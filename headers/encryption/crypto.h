//
// Created by niko on 23.10.2025.
//

#ifndef BOTINTERFACE_CRYPT_H
#define BOTINTERFACE_CRYPT_H

#include <vector>
#include <string>

class Crypto
{
	public:
		static void createKey();
		static void encrypt(const std::string& filename);
		static void decrypt(const std::string& filename);
	private:
		static std::vector<unsigned char> readKey();
};

#endif //BOTINTERFACE_CRYPT_H
