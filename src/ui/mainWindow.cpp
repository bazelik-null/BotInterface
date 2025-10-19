#include <headers/ui/mainWindow.h>

MainWindow::MainWindow() {
    set_title("Bot Interface");
    set_default_size(400, 200);

    createGrid();

    setupLogin();

    set_visible(true);
}

MainWindow::~MainWindow() {
    // Destructor
}

void MainWindow::createGrid()
{
    grid.set_column_homogeneous(true);
    grid.set_row_homogeneous(true);
    grid.set_halign(Gtk::Align::CENTER);
    grid.set_valign(Gtk::Align::CENTER);
    grid.set_row_spacing(100);
    grid.set_column_spacing(100);
}

void MainWindow::setupMenu() {
    pageControl.set_size_request(400, 200);
    grid.attach(pageControl, 1, 0);

    pageSettings.set_size_request(400, 200);
    grid.attach(pageSettings, 0, 0);

    pageStats.set_size_request(400, 200);
    grid.attach(pageStats, 2, 0);

    set_child(grid);
}

void MainWindow::setupLogin()
{
    pageLogin.signal_switch_page.connect(sigc::mem_fun(*this, &MainWindow::on_switch_page));

    pageLogin.set_size_request(400, 200);
    grid.attach(pageLogin, 0, 0);

    set_child(grid);
}

void MainWindow::on_switch_page()
{
    grid.remove(pageLogin);

    setupMenu();
}
