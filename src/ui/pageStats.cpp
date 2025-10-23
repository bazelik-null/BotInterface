//
// Created by niko on 16.10.2025.
//

#include <headers/ui/pageStats.h>

PageStats::PageStats() {
    set_label("Statistics");

    box.set_orientation(Gtk::Orientation::VERTICAL);

    set_child(box);
}

PageStats::~PageStats() = default;