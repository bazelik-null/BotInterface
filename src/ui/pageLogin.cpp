//
// Created by niko on 19.10.2025.
//

#include <headers/ui/pageLogin.h>

PageLogin::PageLogin() {
	set_label("Login");

	box.set_orientation(Gtk::Orientation::VERTICAL);

	createEntryKey();
	createButton();

	set_child(box);
}

PageLogin::~PageLogin() {
	// Destructor
}


void PageLogin::on_button_clicked()
{
	signal_switch_page();
}

void PageLogin::createButton()
{
	buttonLogin.set_label("Login");
	buttonLogin.signal_clicked().connect(sigc::mem_fun(*this, &PageLogin::on_button_clicked));
	buttonLogin.set_margin_top(50);
	buttonLogin.set_margin_bottom(25);
	buttonLogin.set_margin_start(10);
	buttonLogin.set_margin_end(10);

	box.append(buttonLogin);
}

void PageLogin::createEntryKey()
{
	labelEntryKey.set_margin_top(25);
	labelEntryKey.set_label("Enter key:");
	labelEntryKey.set_margin_bottom(10);

	entryKey.set_margin_end(10);
	entryKey.set_margin_start(10);

	box.append(labelEntryKey);
	box.append(entryKey);
}
