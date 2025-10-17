//
// Created by niko on 16.10.2025.
//

#include <headers/ui/pageSettings.h>
#include <headers/shared.h>

PageSettings::PageSettings() {
    set_label("Settings");

    box.set_orientation(Gtk::Orientation::VERTICAL);

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

    entryToken.set_text(settingsValuesRef.token);
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

    entryChannel.set_text(settingsValuesRef.channel);
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

    entryAdminChannel.set_text(settingsValuesRef.adminChannel);
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

    entryAdmins.set_text(settingsValuesRef.admins);
    entryAdmins.set_margin_end(10);
    entryAdmins.set_margin_start(10);
    entryAdmins.set_margin_bottom(50);
    box.append(entryAdmins);
}

void PageSettings::updateButtonSave()
{
    sharedValuesRef.signal_online_changed.connect(sigc::mem_fun(*this, &PageSettings::on_online_changed));
    buttonSave.set_label("Save settings");
    buttonSave.signal_clicked().connect(sigc::mem_fun(*this, &PageSettings::on_button_clicked));
    buttonSave.set_margin_top(150);
    buttonSave.set_margin_bottom(50);
    buttonSave.set_margin_start(50);
    buttonSave.set_margin_end(50);
    box.append(buttonSave);
}

void PageSettings::on_button_clicked() const
{
    const std::string tokenInput = entryToken.get_text();
    const std::string channelInput = entryChannel.get_text();
    const std::string adminChannelInput = entryAdminChannel.get_text();
    const std::string adminsInput = entryAdmins.get_text();

    settingsValuesRef.setValues(tokenInput, channelInput, adminChannelInput, adminsInput);
}

void PageSettings::on_online_changed() {
    buttonSave.set_sensitive(!sharedValuesRef.isOnline);
}