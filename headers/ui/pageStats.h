//
// Created by niko on 16.10.2025.
//

#ifndef BOTINTERFACE_PAGESTATS_H
#define BOTINTERFACE_PAGESTATS_H

#include <gtkmm.h>

class PageStats final : public Gtk::Frame {
    public:
        PageStats();
        ~PageStats() override;

    private:
        Gtk::Box box;
};

#endif //BOTINTERFACE_PAGESTATS_H
