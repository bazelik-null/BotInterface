//
// Created by niko on 17.10.2025.
//

#ifndef BOTINTERFACE_SHARED_H
#define BOTINTERFACE_SHARED_H

#include <string>
#include <sigc++/sigc++.h>
#include <headers/io/jsonio.h>

class SettingsValues {
    public:
        SettingsValues();

        void setValues(const std::string& tokenInput, const std::string& firstInput, const std::string& secondInput , const std::string& thirdInput);

        std::string token;
        std::string first;
        std::string second;
        std::string third;

    private:
        JsonIO jsonIO;
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