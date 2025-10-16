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

    pageControl.set_size_request(400, 200);
    grid.attach(pageControl, 1, 0);

    pageSettings.set_size_request(400, 200);
    grid.attach(pageSettings, 0, 0);

    pageStats.set_size_request(400, 200);
    grid.attach(pageStats, 2, 0);

    set_child(grid);
}
