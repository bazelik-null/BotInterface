//
// Created by niko on 17.10.2025.
//

#ifndef BOTINTERFACE_SHARED_H
#define BOTINTERFACE_SHARED_H

#include <string>
#include <sigc++/sigc++.h>

class SettingsValues {
    public:
        SettingsValues();

        void setValues(const std::string& tokenInput, const std::string& channelInput, const std::string& adminChannelInput = {}, const std::string& adminsInput = {});

        std::string token;
        std::string channel;
        std::string adminChannel;
        std::string admins;
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