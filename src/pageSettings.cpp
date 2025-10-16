//
// Created by niko on 16.10.2025.
//

#include "headers/pageSettings.h"
#include <gtkmm.h>

SettingsValues settingsValues;

PageSettings::PageSettings() {
    set_label("Settings");

    box.set_orientation(Gtk::Orientation::VERTICAL);

    settingsValues = SettingsValues();

    updateEntryToken();
    updateEntryChannel();
    updateEntryAdminChannel();
    updateEntryAdmins();
    updateButtonSave();

    set_child(box);
}

PageSettings::~PageSettings() {
    // Destructor
}

void PageSettings::updateEntryToken()
{
    labelEntryToken.set_margin_top(25);
    labelEntryToken.set_label("Enter bot Token:");
    labelEntryToken.set_margin_bottom(10);
    box.append(labelEntryToken);

    entryToken.set_text(settingsValues.token);
    entryToken.set_margin_end(10);
    entryToken.set_margin_start(10);
    entryToken.set_margin_bottom(50);
    box.append(entryToken);
}

void PageSettings::updateEntryChannel()
{
    labelEntryChannel.set_label("Enter channel ID for approved forms:");
    labelEntryChannel.set_margin_bottom(10);
    box.append(labelEntryChannel);

    entryChannel.set_text(settingsValues.channel);
    entryChannel.set_margin_end(10);
    entryChannel.set_margin_start(10);
    entryChannel.set_margin_bottom(50);
    box.append(entryChannel);
}

void PageSettings::updateEntryAdminChannel()
{
    labelEntryAdminChannel.set_label("Enter channel ID for pending forms:");
    labelEntryAdminChannel.set_margin_bottom(10);
    box.append(labelEntryAdminChannel);

    entryAdminChannel.set_text(settingsValues.adminChannel);
    entryAdminChannel.set_margin_end(10);
    entryAdminChannel.set_margin_start(10);
    entryAdminChannel.set_margin_bottom(50);
    box.append(entryAdminChannel);
}

void PageSettings::updateEntryAdmins()
{
    labelEntryAdmins.set_label("Enter admins IDs:");
    labelEntryAdmins.set_margin_bottom(10);
    box.append(labelEntryAdmins);

    entryAdmins.set_text(settingsValues.admins);
    entryAdmins.set_margin_end(10);
    entryAdmins.set_margin_start(10);
    entryAdmins.set_margin_bottom(50);
    box.append(entryAdmins);
}

void PageSettings::updateButtonSave()
{
    buttonSave.set_label("Save settings");
    buttonSave.signal_clicked().connect(sigc::mem_fun(*this, &PageSettings::on_button_clicked));
    buttonSave.set_margin_top(150);
    buttonSave.set_margin_bottom(50);
    buttonSave.set_margin_start(50);
    buttonSave.set_margin_end(50);
    box.append(buttonSave);
}

void PageSettings::on_button_clicked()
{
    const std::string tokenInput = entryToken.get_text();
    const std::string channelInput = entryChannel.get_text();
    const std::string adminChannelInput = entryAdminChannel.get_text();
    const std::string adminsInput = entryAdmins.get_text();

    settingsValues.saveValues(tokenInput, channelInput, adminChannelInput, adminsInput);
}

SettingsValues::SettingsValues()
{
    // Placeholder, we need to actually load values
    token = "123";
    channel = "";
    adminChannel = "";
    admins = "";
}

void SettingsValues::saveValues(const std::string& tokenInput, const std::string& channelInput, const std::string& adminChannelInput, const std::string& adminsInput)
{
    // Placeholder, we need to actually save values
    this->token = tokenInput;
    this->channel = channelInput;
    this->adminChannel = adminChannelInput;
    this->admins = adminsInput;
}
