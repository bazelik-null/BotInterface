//
// Created by niko on 16.10.2025.
//

#ifndef BOTINTERFACEGTK_PAGESTATS_H
#define BOTINTERFACEGTK_PAGESTATS_H

#include <gtkmm.h>

class PageStats : public Gtk::Frame {
public:
    PageStats();
    virtual ~PageStats();

private:
    Gtk::Box box;
};

#endif //BOTINTERFACEGTK_PAGESTATS_H
