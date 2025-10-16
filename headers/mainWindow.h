//
// Created by niko on 14.10.2025.
//

#ifndef BOTINTERFACEGTK_MAINWINDOW_H
#define BOTINTERFACEGTK_MAINWINDOW_H

#include <gtkmm.h>
#include "pageControl.h"
#include "pageSettings.h"
#include "pageStats.h"

class MainWindow : public Gtk::Window {
public:
    MainWindow();
    virtual ~MainWindow();

private:
    Gtk::Grid grid;
    PageControl pageControl;
    PageSettings pageSettings;
    PageStats pageStats;

    void setupLayout();
};
#endif //BOTINTERFACEGTK_MAINWINDOW_H
