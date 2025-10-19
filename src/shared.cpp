//
// Created by niko on 17.10.2025.
//

#include <headers/shared.h>

auto settingsValues = SettingsValues();
SettingsValues& settingsValuesRef = settingsValues;

auto sharedValues = SharedValues();
SharedValues& sharedValuesRef = sharedValues;

SettingsValues::SettingsValues()
{
    // TODO: Firstly we need to request values from server

    Data data = JsonIO::readValuesFromJson();

    if (data.success)
    {
        token = data.token;
        first = data.first;
        second = data.second;
        third = data.third;
    } else // If there is no saved values we just initialize blank var's
    {
        token = "";
        first = "";
        second = "";
        third = "";
    }
}

void SettingsValues::setValues(const std::string& tokenInput, const std::string& firstInput, const std::string& secondInput, const std::string& thirdInput)
{
    Data data;

    token = tokenInput;
    first = firstInput;
    second = secondInput;
    third = thirdInput;

    data.success = true; // This actually doesn't mead anything, just initializing it
    data.token = tokenInput;
    data.first = firstInput;
    data.second = secondInput;
    data.third = thirdInput;

    JsonIO::saveValuesAsJson(data);
}

SharedValues::SharedValues()
{
    isOnline = false;
}
