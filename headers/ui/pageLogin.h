//
// Created by niko on 19.10.2025.
//

#ifndef BOTINTERFACE_LOGIN_H
#define BOTINTERFACE_LOGIN_H

#include <gtkmm.h>

class PageLogin final : public Gtk::Frame {
	public:
		PageLogin();
		~PageLogin() override;

		sigc::signal<void()> signal_switch_page;

		void switch_page() const
		{
			signal_switch_page.emit();
		}

	protected:
		void on_button_clicked() const;

		void createButton();
		void createEntryKey();

	private:
		Gtk::Box box;

		Gtk::Button buttonLogin;

		Gtk::Label labelEntryKey;
		Gtk::PasswordEntry entryKey;
};



#endif //BOTINTERFACE_LOGIN_H