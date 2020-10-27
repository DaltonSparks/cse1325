#include "mainwin.h"
#include "entrydialog.h"
#include <fstream>

Mainwin::Mainwin() : store{nullptr}, display{new Gtk::Label{}}, filename{"untitled"} {
	
	// ///////// //
	// GUI SETUP //
	// ///////// //

	set_default_size(640,480);
	set_title("Manga Magic");

	Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);


	//MENU
	Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
	vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

	//ADDING FILE TO MENUBAR
	Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
	menubar->append(*menuitem_file);
	Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
	menuitem_file->set_submenu(*filemenu);

	//NEW STORE
	//Append New Store to the insert menu
	Gtk::MenuItem *menuitem_newstore = Gtk::manage(new Gtk::MenuItem("_New Store", true));
	menuitem_newstore->signal_activate().connect([this] {this->on_new_store_click();});
	filemenu->append(*menuitem_newstore);

	//SAVE
	//Append Save to the insert menu
	Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
	menuitem_save->signal_activate().connect([this] {this->on_save_click();});
	filemenu->append(*menuitem_save);

	//SAVE AS
	//Append Save As to the insert menu
	Gtk::MenuItem *menuitem_saveas = Gtk::manage(new Gtk::MenuItem("_Save As", true));
	menuitem_saveas->signal_activate().connect([this] {this->on_save_as_click();});
	filemenu->append(*menuitem_saveas);

	//OPEN
	//Append Open to the insert menu
	Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
	menuitem_open->signal_activate().connect([this] {this->on_open_click();});
	filemenu->append(*menuitem_open);

	//QUIT
	//Append Quit to the File menu
	Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
	menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
	filemenu->append(*menuitem_quit);

	///////////////////////////

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
	menuitem_mulch->signal_activate().connect([this] {this->on_new_mulch_click();});
	insertmenu->append(*menuitem_mulch);

	///////////////////////////

	//ADDING HELP TO MENUBAR
	Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
	menubar->append(*menuitem_help);
	Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
	menuitem_help->set_submenu(*helpmenu);

	//ABOUT
	//Append About to the Help menu
	Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
	menuitem_about->signal_activate().connect([this] {this->on_about_click();});
	helpmenu->append(*menuitem_about);

	display = Gtk::manage(new Gtk::Label());
	display->set_hexpand(true);
	display->set_vexpand(true);
	vbox->add(*display);

	vbox->show_all();

	//on_new_store_click();
}

Mainwin::~Mainwin() { }

	// ///////// //
	// CALLBACKS //
	// ///////// //

void Mainwin::on_save_click() {
    try {
        std::ofstream ofs{filename};
        store->save(ofs);
    } catch(std::exception e) {
        Gtk::MessageDialog{*this, "Unable to save data", false, Gtk::MESSAGE_ERROR}.run();
    }
}

void Mainwin::on_save_as_click(){

	Gtk::FileChooserDialog dialog("Please choose a file",
	Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
	dialog.set_transient_for(*this);

	auto filter_manga = Gtk::FileFilter::create();
	filter_manga->set_name("Manga files");
	filter_manga->add_pattern("*.manga");
	dialog.add_filter(filter_manga);
	 
	auto filter_any = Gtk::FileFilter::create();
	filter_any->set_name("Any files");
	filter_any->add_pattern("*");
	dialog.add_filter(filter_any);
	
	dialog.set_filename("untitled.manga");
	
	//Add response buttons the the dialog:
	dialog.add_button("_Cancel", 0);
	dialog.add_button("_Save", 1);
	
	int result = dialog.run();
	filename = dialog.get_filename();
	if (result == 1) {
		try {
			std::ofstream ofs{dialog.get_filename()};
			store->save(ofs);
			if(!ofs) throw std::runtime_error{"Error writing file"};
			} catch(std::exception& e) {
				Gtk::MessageDialog{*this, "Unable to save game"}.run();
		}
	}
}

void Mainwin::on_open_click(){
	Gtk::FileChooserDialog dialog("Please choose a file",
	Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
	dialog.set_transient_for(*this);

	auto filter_manga = Gtk::FileFilter::create();
	filter_manga->set_name("manga Files");
	filter_manga->add_pattern("*.manga");
	dialog.add_filter(filter_manga);
 
	auto filter_any = Gtk::FileFilter::create();
	filter_any->set_name("Any files");
	filter_any->add_pattern("*");
	dialog.add_filter(filter_any);

	dialog.set_filename("untitled.manga");

	//Add response buttons the the dialog:
	dialog.add_button("_Cancel", 0);
	dialog.add_button("_Open", 1);

	int result = dialog.run();

	if (result == 1) {
		try {
			delete store;
			//std::ifstream ifs{dialog.get_filename()};
			store = new Store{"ifs"};
			} catch (std::exception& e) {
				Gtk::MessageDialog{*this, "Unable to open game"}.run();
		}
	}
}

void Mainwin::on_about_click(){
	Gtk::MessageDialog{*this, "ABOUT\n\nVersion 0.1\n\nCopyright 2020\n\n This program comes with no warranty"}.run();  // Concise message dialog!
}

void Mainwin::on_new_store_click() {
	delete store;
	try {
		std::string storename = get_string("New store name?");
		store = new Store(storename);
		on_view_products_click();
	}catch(std::exception& e) {
	}
}



void Mainwin::on_new_tool_click() {
	try {
		std::string name = get_string("Name?");
		double price = get_double("Price?");
		std::string description = get_string("Description?");
		store->add_product(*(new Tool{name,price,description}));
		on_view_products_click();
	}catch(std::exception& e) {
	}
}

void Mainwin::on_new_plant_click() {
	try {
		std::string name = get_string("Name?");
		double price = get_double("Price?");
		std::string description = get_string("Description?");
		std::string species = get_string("Species?");
		int i = get_int("Exposure? (1) Shade (2) Part Sun (3) Sun");
		Exposure exposure;
		if(i==1)	exposure = Exposure::SHADE;
		else if(i==2)	exposure = Exposure::PARTSUN;
		else	exposure = Exposure::SUN;
		store->add_product(*(new Plant{name, price, description, species, exposure}));
		on_view_products_click();
	}catch(std::exception& e) {
	}
}

void Mainwin::on_new_mulch_click() {
	try {
		std::string name = get_string("Name?");
		double price = get_double("Price?");
		std::string description = get_string("Description?");
		int volume = get_int("Volume (ft³)?");
		int i = get_int("Material? (1) Rubber (2) Pine (3) Cedar (4) Hardwood");
		Material material;
		if(i==1)	material = Material::RUBBER;
		else if(i==2)	material = Material::PINE;
		else if(i==3)	material = Material::CEDAR;
		else	material = Material::HARDWOOD;
		store->add_product(*(new Mulch{name, price, description, volume, material}));
		on_view_products_click();
	}catch(std::exception& e) {
	}
}

void Mainwin::on_view_products_click() {
	std::string curr = "current Products\n---------------\n\n";
	for(int i=0; i<store->products(); i++)
	{
		std::ostringstream oss;
		oss << store->product(i) << '\n';
		curr += oss.str();
	}
	display->set_text(curr);
}

void Mainwin::on_quit_click() {
	close();
}

std::string Mainwin::get_string(std::string prompt) {
    EntryDialog edialog(*this, "<big>New Product</big>", true, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_OK_CANCEL);
    edialog.set_secondary_text(prompt, true);
    if(edialog.run() == Gtk::RESPONSE_CANCEL) throw std::runtime_error{"CANCEL"};
    return edialog.get_text();
}

double Mainwin::get_double(std::string prompt) {
    while(true) {
        try {
            return std::stod(get_string(prompt));
        } catch (std::invalid_argument& e) {
            prompt = "Invalid input try again:";
        }
    }
}

int Mainwin::get_int(std::string prompt) {
    while(true) {
        try {
            return std::stoi(get_string(prompt));
        } catch (std::invalid_argument& e) {
            prompt = "Invalid input try again:";
        }
    }
}
		
