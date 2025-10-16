//
// Created by niko on 16.10.2025.
//

#include "headers/pageSettings.h"
#include <gtkmm.h>

PageSettings::PageSettings() {
    set_label("Settings");

    box.set_orientation(Gtk::Orientation::VERTICAL);

    labelEntryToken.set_label("Enter bot Token:");
    labelEntryToken.set_margin_top(10);
    labelEntryToken.set_margin_bottom(10);
    box.append(labelEntryToken);

    entryToken.set_placeholder_text("Example: 123456789:ABCdefGhIJKlmNoPQRstuVWXyz1234567890");
    entryToken.set_margin_end(10);
    entryToken.set_margin_start(10);
    entryToken.set_margin_bottom(50);
    box.append(entryToken);

    set_child(box);
}

PageSettings::~PageSettings() {
    // Destructor
}
