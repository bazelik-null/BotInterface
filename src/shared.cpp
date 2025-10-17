//
// Created by niko on 17.10.2025.
//

#include <headers/shared.h>
#include <headers/ui/pageSettings.h>

auto settingsValues = SettingsValues();
SettingsValues& settingsValuesRef = settingsValues;

auto sharedValues = SharedValues();
SharedValues& sharedValuesRef = sharedValues;

SettingsValues::SettingsValues()
{
    // Placeholder, we need to actually load values
    token = "1234567890:ASDFGHJKLzxcvbnm";
    channel = "123456";
    adminChannel = "67890";
    admins = "12345 67890";
}

void SettingsValues::setValues(const std::string& tokenInput, const std::string& channelInput, const std::string& adminChannelInput, const std::string& adminsInput)
{
    // Placeholder, we need to actually save values
    token = tokenInput;
    channel = channelInput;
    adminChannel = adminChannelInput;
    admins = adminsInput;
}

SharedValues::SharedValues()
{
    isOnline = false;
}
