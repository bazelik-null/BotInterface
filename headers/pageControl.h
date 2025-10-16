//
// Created by niko on 16.10.2025.
//

#ifndef BOTINTERFACEGTK_PAGECONTROL_H
#define BOTINTERFACEGTK_PAGECONTROL_H

#include <gtkmm.h>

class PageControl : public Gtk::Frame {
public:
    PageControl();
    virtual ~PageControl();

protected:
    void on_button_clicked();
    void updateLabel();
    void updateButton();

private:
    Gtk::Box box;
    Gtk::Label labelBotStatus;
    Gtk::Button buttonStart;
};

#endif //BOTINTERFACEGTK_PAGECONTROL_H
