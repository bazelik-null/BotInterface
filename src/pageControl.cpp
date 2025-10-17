//
// Created by niko on 16.10.2025.
//

#include "headers/pageControl.h"
#include "headers/shared.h"
#include <gtkmm.h>

PageControl::PageControl() {
    set_label("Control Menu");

    box.set_orientation(Gtk::Orientation::VERTICAL);

    updateLabel();
    labelBotStatus.set_margin_top(150);
    box.append(labelBotStatus);

    updateButton();
    buttonStart.signal_clicked().connect(sigc::mem_fun(*this, &PageControl::on_button_clicked));
    buttonStart.set_margin_top(150);
    buttonStart.set_margin_bottom(50);
    buttonStart.set_margin_start(50);
    buttonStart.set_margin_end(50);
    box.append(buttonStart);

    set_child(box);
}

PageControl::~PageControl() {
    // Destructor
}

void PageControl::on_button_clicked() {
    sharedValuesRef.isOnline = !sharedValuesRef.isOnline;
    sharedValuesRef.set_is_online();
    updateLabel();
    updateButton();
}

void PageControl::updateLabel()
{
    if (sharedValuesRef.isOnline)
    {
        labelBotStatus.set_markup(R"(<span foreground="green" size="x-large">Bot online</span>)");
    }
    else
    {
        labelBotStatus.set_markup(R"(<span foreground="red" size="x-large">Bot offline</span>)");
    }
}

void PageControl::updateButton()
{
    if (sharedValuesRef.isOnline)
    {
        buttonStart.set_label("Stop bot");
    }
    else
    {
        buttonStart.set_label("Start bot");
    }
}