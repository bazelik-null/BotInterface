#include <gtkmm.h>
#include "../headers/mainWindow.h"

bool isBotOnline = true;

void placeholder()
{
    isBotOnline = !isBotOnline;
}

MainWindow::MainWindow() {
    // Set the title and size of the window
    set_title("Bot Interface");
    set_default_size(400, 200);

    // Set up grid
    createGrid();

    // Set up boxes
    createBoxControl();
    createBoxSettings();
    createBoxStats();

    // Set up the frames
    createFrameControl();
    createFrameSettings();
    createFrameStats();

    // Create buttons
    createButtonStart();

    // Check is bot online
    placeholder();

    // Set up bot status label
    createLabelBotStatus();

    // Set up entries
    createEntryToken();

    // Add the grid to the window
    set_child(grid);

    set_visible(true);
}

MainWindow::~MainWindow() {
    // Destructor
}

void MainWindow::on_button_clicked() {
    placeholder();
    createLabelBotStatus();
    buttonStart.set_label("Stop bot");
}

void MainWindow::createButtonStart()
{
    buttonStart.set_label("Start bot");
    buttonStart.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_button_clicked));
    buttonStart.set_margin_top(150);
    buttonStart.set_margin_bottom(50);
    buttonStart.set_margin_start(50);
    buttonStart.set_margin_end(50);
}



void MainWindow::createFrameSettings()
{
    frameSettings.set_label("Settings");
    frameSettings.set_child(boxSettings);
    frameSettings.set_size_request(300, 500);

    // Attach the frame to the grid
    grid.attach(frameSettings, 0, 1, 1);
}

void MainWindow::createFrameControl()
{
    frameControl.set_label("Control Menu");
    frameControl.set_child(boxControl);
    frameControl.set_size_request(400, 300);

    // Attach the frame to the grid
    grid.attach(frameControl, 1, 1, 1);
}

void MainWindow::createFrameStats()
{
    frameStats.set_label("Statistics");
    frameStats.set_child(boxStats);
    frameStats.set_size_request(300, 500);

    // Attach the frame to the grid
    grid.attach(frameStats, 2, 1, 1);
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




void MainWindow::createLabelBotStatus()
{
    labelBotStatus.set_margin_top(150);
    if (isBotOnline)
    {
        labelBotStatus.set_markup(R"(<span foreground="green" size="x-large">Bot online</span>)");
    }
    else
    {
        labelBotStatus.set_markup(R"(<span foreground="red" size="x-large">Bot offline</span>)");
    }

}



void MainWindow::createBoxControl()
{
    boxControl.set_orientation(Gtk::Orientation::VERTICAL);

    boxControl.append(labelBotStatus);
    boxControl.append(buttonStart);
}

void MainWindow::createBoxSettings()
{
    boxSettings.set_orientation(Gtk::Orientation::VERTICAL);

    boxSettings.append(labelEntryToken);
    boxSettings.append(entryToken);
}

void MainWindow::createBoxStats()
{
    boxStats.set_orientation(Gtk::Orientation::VERTICAL);
}



void MainWindow::createEntryToken()
{
    labelEntryToken.set_label("Enter bot Token:");
    labelEntryToken.set_margin_top(10);
    labelEntryToken.set_margin_bottom(10);

    entryToken.set_placeholder_text("Example: 123456789:ABCdefGhIJKlmNoPQRstuVWXyz1234567890");

    entryToken.set_margin_bottom(50);

    entryToken.set_margin_end(10);
    entryToken.set_margin_start(10);
}
