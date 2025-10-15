//
// Created by niko on 14.10.2025.
//

#ifndef BOTINTERFACEGTK_MAINWINDOW_H
#define BOTINTERFACEGTK_MAINWINDOW_H

#include <gtkmm.h>

class MainWindow : public Gtk::Window {
    public:
        MainWindow();
        virtual ~MainWindow();

    protected:
        // Slots
        void on_button_clicked();

        // Grids
        void createGrid();

        // Boxes
        void createBoxControl();
        void createBoxSettings();
        void createBoxStats();

        // Frames
        void createFrameControl();
        void createFrameSettings();
        void createFrameStats();

        // Buttons
        void createButtonStart();

        // Labels
        void createLabelBotStatus();

        // Entries
        void createEntryToken();


    private:
        // Grids
        Gtk::Grid grid;

        // Boxes
        Gtk::Box boxControl;
        Gtk::Box boxSettings;
        Gtk::Box boxStats;

        // Frames
        Gtk::Frame frameControl;
        Gtk::Frame frameSettings;
        Gtk::Frame frameStats;

        // Buttons
        Gtk::Button buttonStart;

        // Labels
        Gtk::Label labelBotStatus;
        Gtk::Label labelEntryToken;

        // Entries
        Gtk::Entry entryToken;
};

#endif //BOTINTERFACEGTK_MAINWINDOW_H