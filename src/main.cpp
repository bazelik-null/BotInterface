#include <gtkmm.h>
#include "../headers/mainWindow.h"

int main(int argc, char* argv[]) {
    // Create GTK app
    const auto app = Gtk::Application::create("org.gtkmm.botInterface", Gio::Application::Flags::NONE);

    // Create new CSS provider and set path to CSS file
    const auto css_provider = Gtk::CssProvider::create();
    const std::string css_file = "../resources/gtk.css";

    // Load CSS theme
    css_provider->load_from_path(css_file);

    // Set CSS theme
    Gtk::StyleContext::add_provider_for_display(
        Gdk::Display::get_default(),
        css_provider,
        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    // Create the main window
    MainWindow window;

    // Connect startup signal to add the window to the app
    app->signal_startup().connect([&]() {
        app->add_window(window);
    });

    // Run app
    return app->run(argc, argv);
}
