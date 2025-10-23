//
// Created by niko on 17.10.2025.
//

#include <headers/shared.h>
#include <headers/encryption/crypto.h>

auto settingsValues = SettingsValues();
SettingsValues& settingsValuesRef = settingsValues;

auto sharedValues = SharedValues();
SharedValues& sharedValuesRef = sharedValues;

SettingsValues::SettingsValues()
{
    auto [successData, tokenData, firstData, secondData, thirdData] = JsonIO::readValuesFromJson();

    if (successData)
    {
        token = tokenData;
        first = firstData;
        second = secondData;
        third = thirdData;
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
