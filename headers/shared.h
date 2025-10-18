//
// Created by niko on 17.10.2025.
//

#ifndef BOTINTERFACE_SHARED_H
#define BOTINTERFACE_SHARED_H

#include <string>
#include <sigc++/sigc++.h>
#include <nlohmann/json.hpp>

// TODO: Remove hardcode

class SettingsValues {
    public:
        SettingsValues();

        void setValues(const std::string& tokenInput, const std::string& channelInput, const std::string& adminChannelInput = {}, const std::string& adminsInput = {});
        bool readValuesFromJson();
        nlohmann::json getValuesAsJson();

        std::string token;
        std::string channel;
        std::string adminChannel;
        std::string admins;
    private:
        static bool getValue(const nlohmann::json& json, const std::string& key, std::string& value);
};

class SharedValues
{
    public:
        SharedValues();
        bool isOnline;

        sigc::signal<void()> signal_online_changed;

        void set_is_online() const
        {
            signal_online_changed.emit();
        }
};

extern SettingsValues& settingsValuesRef;
extern SharedValues& sharedValuesRef;

#endif //BOTINTERFACE_SHARED_H