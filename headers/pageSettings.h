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

private:
    Gtk::Box box;
    Gtk::Label labelEntryToken;
    Gtk::Entry entryToken;
};

#endif //BOTINTERFACEGTK_PAGESETTINGS_H
