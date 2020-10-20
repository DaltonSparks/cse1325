#include "mainwin.h"
#include "store.h"
#include "entrydialog.h"
#include <iostream>

Mainwin::Mainwin() : store{nullptr} {
	
	// ///////// //
	// GUI SETUP //
	// ///////// //

	set_default_size(400,400);
	set_title("Manga Magic");

	Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

	on_new_store_click();

	std::ostringstream oss;

	//MENU
	Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
	vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

	//ADDING FILE TO MENUBAR
	Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
	menubar->append(*menuitem_file);
	Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
	menuitem_file->set_submenu(*filemenu);

	//QUIT
	//Append Quit to the File menu
	Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
	menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
	filemenu->append(*menuitem_quit);

	//ADDING INSERT TO MENUBAR
	Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_insert", true));
	menubar->append(*menuitem_insert);
	Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
	menuitem_insert->set_submenu(*insertmenu);

	//TOOL
	//Append Tool to the Insert menu
	Gtk::MenuItem *menuitem_tool = Gtk::manage(new Gtk::MenuItem("_Tool", true));
	menuitem_tool->signal_activate().connect([this] {this->on_new_tool_click();});
	insertmenu->append(*menuitem_tool);

	//PLANT
	//Append Plant to the Insert menu
	Gtk::MenuItem *menuitem_plant = Gtk::manage(new Gtk::MenuItem("_Plant", true));
	menuitem_plant->signal_activate().connect([this] {this->on_new_plant_click();});
	insertmenu->append(*menuitem_plant);

	//MULCH
	//Append Mulch to the Insert menu
	Gtk::MenuItem *menuitem_mulch = Gtk::manage(new Gtk::MenuItem("_Mulch", true));
	menuitem_mulch->signal_activate().connect([this] {this->on_new_tool_click();});
	insertmenu->append(*menuitem_mulch);

	vbox->show_all();
}

Mainwin::~Mainwin() { }

	// ///////// //
	// CALLBACKS //
	// ///////// //

void Mainwin::on_new_store_click() {
	delete store;
	std::string S;
	store = new Store(S);
}


//I couldn't ever really get the entrydialog to work I tried to follow lecture 14 and it led me to this
//I am not sure where the return value is very confusing 
void Mainwin::on_new_tool_click() {

    EntryDialog ndialog{*this, "<big>New Product</big>", true};
    ndialog.set_secondary_text("Name?", true);
    ndialog.set_text("");
	ndialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
    ndialog.run();

	EntryDialog pdialog{*this, "<big>New Product</big>", true};
    pdialog.set_secondary_text("Price?", true);
    pdialog.set_text("");
	pdialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
    pdialog.run();

	EntryDialog ddialog{*this, "<big>New Product</big>", true};
    ddialog.set_secondary_text("Description?", true);
    ddialog.set_text("");
	ddialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
    ddialog.run();
	//Gtk::MessageDialog mdialog{*this, tdialog.get_text()};
    //mdialog.run();
}

void Mainwin::on_new_plant_click() {

	EntryDialog ndialog{*this, "<big>New Product</big>", true};
    ndialog.set_secondary_text("Name?", true);
    ndialog.set_text("");
	ndialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
    ndialog.run();

	EntryDialog pdialog{*this, "<big>New Product</big>", true};
    pdialog.set_secondary_text("Price?", true);
    pdialog.set_text("");
	pdialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
    pdialog.run();

	EntryDialog ddialog{*this, "<big>New Product</big>", true};
    ddialog.set_secondary_text("Description?", true);
    ddialog.set_text("");
	ddialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
    ddialog.run();

	EntryDialog sdialog{*this, "<big>New Product</big>", true};
    sdialog.set_secondary_text("Species?", true);
    sdialog.set_text("");
	sdialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
    sdialog.run();

	EntryDialog edialog{*this, "<big>New Product</big>", true};
    edialog.set_secondary_text("Select Exposure (1) Shade (2) Part Sun (3) Sun?", true);
    edialog.set_text("");
	edialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
    edialog.run();
}

void Mainwin::on_new_mulch_click() {

	EntryDialog ndialog{*this, "<big>New Product</big>", true};
    ndialog.set_secondary_text("Name?", true);
    ndialog.set_text("");
	ndialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
    ndialog.run();

	EntryDialog pdialog{*this, "<big>New Product</big>", true};
    pdialog.set_secondary_text("Price?", true);
    pdialog.set_text("");
	pdialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
    pdialog.run();

	EntryDialog ddialog{*this, "<big>New Product</big>", true};
    ddialog.set_secondary_text("Description?", true);
    ddialog.set_text("");
	ddialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
    ddialog.run();

	EntryDialog sdialog{*this, "<big>New Product</big>", true};
    sdialog.set_secondary_text("Volume?", true);
    sdialog.set_text("");
	sdialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
    sdialog.run();

	EntryDialog edialog{*this, "<big>New Product</big>", true};
    edialog.set_secondary_text("Material?(1)Rubber(2)Pine(3)Cedar(4)Hardwood?",true);
    edialog.set_text("");
	edialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
    edialog.run();
}

void Mainwin::on_view_products_click() {

}

void Mainwin::on_quit_click() {
	close();
}
		
