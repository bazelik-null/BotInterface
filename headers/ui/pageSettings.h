//
// Created by niko on 16.10.2025.
//

#ifndef BOTINTERFACE_PAGESETTINGS_H
#define BOTINTERFACE_PAGESETTINGS_H

#include <gtkmm.h>
#include <headers/shared.h>

// TODO: Remove hardcode

extern void setupSettingsValues(SettingsValues* settingsValuesPtr);

class PageSettings final : public Gtk::Frame {
    public:
        PageSettings();
        ~PageSettings() override;

    protected:
        void on_button_clicked() const;
        void on_online_changed();
        void updateEntryToken();
        void updateEntryChannel();
        void updateEntryAdminChannel();
        void updateEntryAdmins();
        void updateButtonSave();
        void updateButtonPush();
        void updateButtonPull();

    private:
        Gtk::Box box;

        Gtk::Button buttonSave;
        Gtk::Button buttonPush;
        Gtk::Button buttonPull;

        Gtk::Label labelEntryToken;
        Gtk::Label labelEntryChannel;
        Gtk::Label labelEntryAdminChannel;
        Gtk::Label labelEntryAdmins;

        Gtk::PasswordEntry entryToken;
        Gtk::Entry entryChannel;
        Gtk::Entry entryAdminChannel;
        Gtk::Entry entryAdmins;
};
#endif //BOTINTERFACE_PAGESETTINGS_H
