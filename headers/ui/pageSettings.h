//
// Created by niko on 16.10.2025.
//

#ifndef BOTINTERFACE_PAGESETTINGS_H
#define BOTINTERFACE_PAGESETTINGS_H

#include <gtkmm.h>

struct Entries
{
    void createEntryToken();
    void createEntry1();
    void createEntry2();
    void createEntry3();

    Gtk::Label labelEntryToken;
    Gtk::Label labelEntry1;
    Gtk::Label labelEntry2;
    Gtk::Label labelEntry3;

    Gtk::PasswordEntry entryToken;
    Gtk::Entry entry1;
    Gtk::Entry entry2;
    Gtk::Entry entry3;

    Glib::ustring textLabelEntryToken = "Enter bot Token:";
    Glib::ustring textLabelEntry1     = "Enter channel ID for approved forms:"; // Change this text for your bot
    Glib::ustring textLabelEntry2     = "Enter channel ID for pending forms:";  // And this
    Glib::ustring textLabelEntry3     = "Enter admins IDs:";                    // And even this
};

class PageSettings final : public Gtk::Frame {
    public:
        PageSettings();
        ~PageSettings() override;
        Gtk::Box box;

    protected:
        void on_button_clicked() const;
        void on_online_changed();

        void appendEntries();

        void createButtonSave();
        void createButtonPush();
        void createButtonPull();

    private:
        Gtk::Button buttonSave;
        Gtk::Button buttonPush;
        Gtk::Button buttonPull;

        Entries entries;
};

#endif //BOTINTERFACE_PAGESETTINGS_H
