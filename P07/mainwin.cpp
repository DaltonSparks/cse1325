#include "mainwin.h"
#include "entrydialog.h"

Mainwin::Mainwin() : store{nullptr}, display{new Gtk::Label{}} {
	
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
	menuitem_mulch->signal_activate().connect([this] {this->on_new_mulch_click();});
	insertmenu->append(*menuitem_mulch);

	display = Gtk::manage(new Gtk::Label());
	display->set_hexpand(true);
	display->set_vexpand(true);
	vbox->add(*display);

	vbox->show_all();

	on_new_store_click();
}

Mainwin::~Mainwin() { }

	// ///////// //
	// CALLBACKS //
	// ///////// //

void Mainwin::on_new_store_click() {
	delete store;
	store = new Store("nothing");
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
            prompt = "Invalid value, please try again:";
        }
    }
}

int Mainwin::get_int(std::string prompt) {
    while(true) {
        try {
            return std::stoi(get_string(prompt));
        } catch (std::invalid_argument& e) {
            prompt = "Invalid value, please try again:";
        }
    }
}
		
