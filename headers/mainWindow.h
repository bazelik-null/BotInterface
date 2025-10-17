//
// Created by niko on 14.10.2025.
//

#ifndef BOTINTERFACE_MAINWINDOW_H
#define BOTINTERFACE_MAINWINDOW_H

#include <gtkmm.h>
#include "pageControl.h"
#include "pageSettings.h"
#include "pageStats.h"

class MainWindow final : public Gtk::Window {
    public:
        MainWindow();
        ~MainWindow() override;

    private:
        Gtk::Grid grid;
        PageControl pageControl;
        PageSettings pageSettings;
        PageStats pageStats;

        void setupLayout();
};
#endif //BOTINTERFACE_MAINWINDOW_H
