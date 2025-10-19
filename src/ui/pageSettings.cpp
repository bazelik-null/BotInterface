//
// Created by niko on 16.10.2025.
//

#include <headers/ui/pageSettings.h>
#include <headers/shared.h>

PageSettings::PageSettings() {
    set_label("Settings");

    box.set_orientation(Gtk::Orientation::VERTICAL);

    entries.createEntryToken();
    entries.createEntry1();
    entries.createEntry2();
    entries.createEntry3();
    appendEntries();
    createButtonSave();
    createButtonPush();
    createButtonPull();

    set_child(box);
}

PageSettings::~PageSettings() {
    // Destructor
}

void PageSettings::appendEntries()
{
    box.append(entries.labelEntryToken);
    box.append(entries.entryToken);

    box.append(entries.labelEntry1);
    box.append(entries.entry1);

    box.append(entries.labelEntry2);
    box.append(entries.entry2);

    box.append(entries.labelEntry3);
    box.append(entries.entry3);
}


void Entries::createEntryToken()
{
    labelEntryToken.set_margin_top(25);
    labelEntryToken.set_label(textLabelEntryToken);
    labelEntryToken.set_margin_bottom(10);

    entryToken.set_text(settingsValuesRef.token);
    entryToken.set_margin_end(10);
    entryToken.set_margin_start(10);
    entryToken.set_margin_bottom(50);
}

void Entries::createEntry1()
{
    labelEntry1.set_label(textLabelEntry1);
    labelEntry1.set_margin_bottom(10);


    entry1.set_text(settingsValuesRef.first);
    entry1.set_margin_end(10);
    entry1.set_margin_start(10);
    entry1.set_margin_bottom(50);
}

void Entries::createEntry2()
{
    labelEntry2.set_label(textLabelEntry2);
    labelEntry2.set_margin_bottom(10);

    entry2.set_text(settingsValuesRef.second);
    entry2.set_margin_end(10);
    entry2.set_margin_start(10);
    entry2.set_margin_bottom(50);
}

void Entries::createEntry3()
{
    labelEntry3.set_label(textLabelEntry3);
    labelEntry3.set_margin_bottom(10);

    entry3.set_text(settingsValuesRef.third);
    entry3.set_margin_end(10);
    entry3.set_margin_start(10);
    entry3.set_margin_bottom(50);
}

void PageSettings::createButtonSave()
{
    buttonSave.set_label("Save settings");

    buttonSave.signal_clicked().connect(sigc::mem_fun(*this, &PageSettings::on_button_clicked));

    buttonSave.set_margin_top(50);
    buttonSave.set_margin_bottom(25);
    buttonSave.set_margin_start(50);
    buttonSave.set_margin_end(50);
    box.append(buttonSave);
}

void PageSettings::createButtonPush()
{
    sharedValuesRef.signal_online_changed.connect(sigc::mem_fun(*this, &PageSettings::on_online_changed));

    buttonPush.set_label("Push settings");

    buttonPush.signal_clicked().connect(sigc::mem_fun(*this, &PageSettings::on_button_clicked));

    buttonPush.set_margin_bottom(25);
    buttonPush.set_margin_start(50);
    buttonPush.set_margin_end(50);

    box.append(buttonPush);
}

void PageSettings::createButtonPull()
{
    sharedValuesRef.signal_online_changed.connect(sigc::mem_fun(*this, &PageSettings::on_online_changed));

    buttonPull.set_label("Pull settings");

    buttonPull.signal_clicked().connect(sigc::mem_fun(*this, &PageSettings::on_button_clicked));

    buttonPull.set_margin_bottom(25);
    buttonPull.set_margin_start(50);
    buttonPull.set_margin_end(50);

    buttonPull.set_sensitive(false);

    box.append(buttonPull);
}

void PageSettings::on_button_clicked() const
{
    const std::string tokenInput = entries.entryToken.get_text();
    const std::string firstInput = entries.entry1.get_text();
    const std::string secondInput = entries.entry2.get_text();
    const std::string thirdInput = entries.entry3.get_text();

    settingsValuesRef.setValues(tokenInput, firstInput, secondInput, thirdInput);
}

void PageSettings::on_online_changed() {
    buttonPush.set_sensitive(!sharedValuesRef.isOnline);
    buttonPull.set_sensitive(sharedValuesRef.isOnline);
}