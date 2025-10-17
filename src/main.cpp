#include <gtkmm.h>
#include "../headers/mainWindow.h"

int main(const int argc, char* argv[]) {
    // Create GTK app
    const auto app = Gtk::Application::create("org.gtkmm.botInterface", Gio::Application::Flags::NONE);

    // Create the main window
    MainWindow window;

    // Connect startup signal to add the window to the app
    app->signal_startup().connect([&] {
        app->add_window(window);
    });

    // Run app
    return app->run(argc, argv);
}
