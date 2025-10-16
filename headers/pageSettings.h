//
// Created by niko on 16.10.2025.
//

#ifndef BOTINTERFACEGTK_PAGESETTINGS_H
#define BOTINTERFACEGTK_PAGESETTINGS_H

#include <gtkmm.h>

class PageSettings : public Gtk::Frame {
public:
    PageSettings();
    virtual ~PageSettings();


protected:
    void on_button_clicked();
    void updateEntryToken();
    void updateEntryChannel();
    void updateEntryAdminChannel();
    void updateEntryAdmins();
    void updateButtonSave();

private:
    Gtk::Box box;

    Gtk::Button buttonSave;

    Gtk::Label labelEntryToken;
    Gtk::Label labelEntryChannel;
    Gtk::Label labelEntryAdminChannel;
    Gtk::Label labelEntryAdmins;

    Gtk::PasswordEntry entryToken;
    Gtk::Entry entryChannel;
    Gtk::Entry entryAdminChannel;
    Gtk::Entry entryAdmins;
};

class SettingsValues {
public:
    SettingsValues();

    void saveValues(const std::string& tokenInput, const std::string& channelInput, const std::string& adminChannelInput = {}, const std::string& adminsInput = {});

    std::string token;
    std::string channel;
    std::string adminChannel;
    std::string admins;
};

#endif //BOTINTERFACEGTK_PAGESETTINGS_H
