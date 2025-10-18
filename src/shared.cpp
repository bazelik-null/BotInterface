//
// Created by niko on 17.10.2025.
//

#include <headers/shared.h>
#include <fstream>
#include <iostream>

auto settingsValues = SettingsValues();
SettingsValues& settingsValuesRef = settingsValues;

auto sharedValues = SharedValues();
SharedValues& sharedValuesRef = sharedValues;

// TODO: Make ts secure :troll:

SettingsValues::SettingsValues()
{
    // TODO: Firstly we need to request values from server

    // If there is no saved values we just initialize blank var's
    if (!readValuesFromJson())
    {
        token = "";
        channel = "";
        adminChannel = "";
        admins = "";
    }
}

void SettingsValues::setValues(const std::string& tokenInput, const std::string& channelInput, const std::string& adminChannelInput, const std::string& adminsInput)
{
    token = tokenInput;
    channel = channelInput;
    adminChannel = adminChannelInput;
    admins = adminsInput;

    const nlohmann::json json = getValuesAsJson();

    std::ofstream outFile("settings.json");

    if (outFile.is_open()) {
        outFile << json.dump(-1);
        outFile.close();
    } else {
        std::cerr << "[ERROR]: Unable to open file for writing\n";
    }
}

bool SettingsValues::readValuesFromJson()
{
    std::ifstream inFile("settings.json");

    if (inFile.is_open())
    {
        nlohmann::json json;
        inFile >> json;

        if (
            !getValue(json, "token", token) ||
            !getValue(json, "channel", channel) ||
            !getValue(json, "adminChannel", adminChannel) ||
            !getValue(json, "admins", admins)
            )
        {
            std::cerr << "[ERROR]: Failed to read one or more values\n";
            return false;
        }

        inFile.close();

        return true;
    }
    std::cerr << "[ERROR]: File not found\n";
    return false;
}

bool SettingsValues::getValue(const nlohmann::json& json, const std::string& key, std::string& value) {
    if (json.contains(key) && json[key].is_string()) {
        value = json[key].get<std::string>();
        return true;
    }
    std::cerr << "[ERROR]: '" << key << "' key is missing or not a string\n";
    return false;
}

nlohmann::json SettingsValues::getValuesAsJson()
{
    nlohmann::json json;

    json["token"] = token;
    json["channel"] = channel;
    json["adminChannel"] = adminChannel;
    json["admins"] = admins;

    return json;
}

SharedValues::SharedValues()
{
    isOnline = false;
}
