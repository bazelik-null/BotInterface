//
// Created by niko on 16.10.2025.
//

#ifndef BOTINTERFACE_PAGECONTROL_H
#define BOTINTERFACE_PAGECONTROL_H

#include <gtkmm.h>

class PageControl final : public Gtk::Frame {
    public:
        PageControl();
        ~PageControl() override;

    protected:
        void on_button_clicked();

        void createLabel();
        void createButton();

        void updateLabel();
        void updateButton();

    private:
        Gtk::Box box;
        Gtk::Label labelBotStatus;
        Gtk::Button buttonStart;
};

#endif //BOTINTERFACE_PAGECONTROL_H
