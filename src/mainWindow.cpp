#include "headers/mainWindow.h"
#include <gtkmm.h>

MainWindow::MainWindow() {
    set_title("Bot Interface");
    set_default_size(400, 200);

    setupLayout();

    set_visible(true);
}

MainWindow::~MainWindow() {
    // Destructor
}

void MainWindow::setupLayout() {
    grid.set_column_homogeneous(true);
    grid.set_row_homogeneous(true);
    grid.set_halign(Gtk::Align::CENTER);
    grid.set_valign(Gtk::Align::CENTER);
    grid.set_row_spacing(100);
    grid.set_column_spacing(100);

    pageControl.set_size_request(400, 300);
    grid.attach(pageControl, 1, 1, 1);

    pageSettings.set_size_request(300, 500);
    grid.attach(pageSettings, 0, 1, 1);

    pageStats.set_size_request(300, 500);
    grid.attach(pageStats, 2, 1, 1);

    set_child(grid);
}
