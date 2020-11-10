#include "mainwin.h"
#include "entrydialog.h"
#include <fstream>

Mainwin::Mainwin() : store{nullptr}, display{new Gtk::Label{}}, filename{"untitled.manga"} {
	
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

	//CUSTOMER
	//Append CUSTOMER to the Insert menu
	Gtk::MenuItem *menuitem_customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
	menuitem_customer->signal_activate().connect([this] {this->on_new_customer_click();});
	insertmenu->append(*menuitem_customer);

	//ORDER
	//Append Order to the insert menu
	Gtk::MenuItem *menuitem_order = Gtk::manage(new Gtk::MenuItem("_order", true));
	menuitem_order->signal_activate().connect([this] {this->on_new_order_click();});
	insertmenu->append(*menuitem_order);

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
	
	//ADDING View TO MENUBAR
	Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
	menubar->append(*menuitem_view);
	Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
	menuitem_view->set_submenu(*viewmenu);

	//CUSTOMERS
	//Append Customers to the Insert menu
	Gtk::MenuItem *menuitem_customers = Gtk::manage(new Gtk::MenuItem("_Customers", true));
	menuitem_customers->signal_activate().connect([this] {this->on_view_customers_click();});
	viewmenu->append(*menuitem_customers);

	//ORDERS
	//Append Orders to the Insert menu
	Gtk::MenuItem *menuitem_orders = Gtk::manage(new Gtk::MenuItem("_Orders", true));
	menuitem_orders->signal_activate().connect([this] {this->on_view_orders_click();});
	viewmenu->append(*menuitem_orders);

	//PRODUCTS
	Gtk::MenuItem *menuitem_product = Gtk::manage(new Gtk::MenuItem("_Products", true));
	menuitem_product->signal_activate().connect([this] {this->on_view_products_click();});
	viewmenu->append(*menuitem_product);	

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

	//TOOLBAR
	Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);

	Gtk::ToolButton *new_store_click = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    new_store_click->set_tooltip_markup("Create a new store");
    new_store_click->signal_clicked().connect([this] {this->on_new_store_click();});
    toolbar->append(*new_store_click);

	Gtk::ToolButton *new_open_click = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::OPEN));
    new_open_click->set_tooltip_markup("Open");
    new_open_click->signal_clicked().connect([this] {this->on_open_click();});
    toolbar->append(*new_open_click);

	Gtk::ToolButton *new_save_click = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE));
    new_save_click->set_tooltip_markup("Save");
    new_save_click->signal_clicked().connect([this] {this->on_save_click();});
    toolbar->append(*new_save_click);

	Gtk::ToolButton *new_saveas_click = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE));
    new_saveas_click->set_tooltip_markup("Save As");
    new_saveas_click->signal_clicked().connect([this] {this->on_save_as_click();});
    toolbar->append(*new_saveas_click);

    Gtk::ToolButton *button1 = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    button1->set_tooltip_markup("Insert Customer");
    button1->signal_clicked().connect([this] {this->on_new_customer_click();});
    toolbar->append(*button1);

	Gtk::ToolButton *button2;
	//Gtk::Image* button2_image = Gtk::manage(new Gtk::Image{"shopping-bag.png"});
    button2 = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    button2->set_tooltip_markup("Insert Order");
    button2->signal_clicked().connect([this] {this->on_new_order_click();});
    toolbar->append(*button2);

	Gtk::ToolButton *button3;
	//Gtk::Image* button3_image = Gtk::manage(new Gtk::Image{"technics.png"});
    button3 = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    button3->set_tooltip_markup("Insert Tool");
    button3->signal_clicked().connect([this] {this->on_new_tool_click();});
    toolbar->append(*button3);

	Gtk::ToolButton *button4;
	//Gtk::Image* button4_image = Gtk::manage(new Gtk::Image{"plant.png"});
    button4 = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    button4->set_tooltip_markup("Insert Plant");
    button4->signal_clicked().connect([this] {this->on_new_plant_click();});
    toolbar->append(*button4);

	Gtk::ToolButton *button5;
	//Gtk::Image* button5_image = Gtk::manage(new Gtk::Image{"shovel.png"});
    button5 = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    button5->set_tooltip_markup("Insert Mulch");
    button5->signal_clicked().connect([this] {this->on_new_mulch_click();});
    toolbar->append(*button5);

	Gtk::ToolButton *button7;
    button7 = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::INFO));
    button7->set_tooltip_markup("View Customers");
    button7->signal_clicked().connect([this] {this->on_view_customers_click();});
    toolbar->append(*button7);

	Gtk::ToolButton *button8;
    button8 = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::INFO));
    button8->set_tooltip_markup("View Orders");
    button8->signal_clicked().connect([this] {this->on_view_orders_click();});
    toolbar->append(*button8);

	Gtk::ToolButton *button9;
	//Gtk::Image* button9_image = Gtk::manage(new Gtk::Image{"box.png"});
    button9 = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::INFO));
    button9->set_tooltip_markup("View Products");
    button9->signal_clicked().connect([this] {this->on_view_products_click();});
    toolbar->append(*button9);

	display = Gtk::manage(new Gtk::Label());
	display->set_hexpand(true);
	display->set_vexpand(true);
	//vbox->pack_start(*display, Gtk::PACK_SHRINK, 0);
	vbox->add(*display);

	vbox->show_all();

	on_new_store_click(true);
}

Mainwin::~Mainwin() { }

	// ///////// //
	// CALLBACKS //
	// ///////// //

void Mainwin::on_new_store_click(bool untitled) {
    std::string name = "Untitled";
    try {
        if(!untitled) name = get_string("New store name?");
        filename = "untitled.manga";
    } catch (std::exception& e) {
    }
    delete store; store = nullptr;
    store = new Store{name};
    on_view_products_click();
}

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
            filename = dialog.get_filename();
            std::ifstream ifs{filename};
            delete store; store = nullptr;
            store = new Store{ifs};
            //if(!ifs.eof()) throw std::runtime_error{"Error reading file " + filename};
            on_view_products_click();
        } catch (std::exception& e) {
            Gtk::MessageDialog{*this, "Unable to open store: " + std::string{e.what()},
                false, Gtk::MESSAGE_WARNING}.run();
            on_new_store_click(true);
        }
	}
	on_view_products_click();
}

void Mainwin::on_about_click(){
	Gtk::MessageDialog{*this, "ABOUT\n\nVersion 0.1\n\nCopyright 2020\n\n This program comes with no warranty\nimages from https://support.flaticon.com"}.run();  // Concise message dialog!
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

void Mainwin::on_new_customer_click() {
	Gtk::Dialog dialog{"Insert Customer", *this};
	Gtk::Grid grid;

	Gtk::Label l_name{"Name"};
	Gtk::Entry e_name;
	grid.attach(l_name, 0, 0, 1, 1);
	grid.attach(e_name, 1, 0, 2, 1);

	Gtk::Label l_phone{"Phone"};
	Gtk::Entry e_phone;
	e_phone.set_placeholder_text("xxx-xxx-xxxx");
	grid.attach(l_phone, 0, 1, 1, 1);
	grid.attach(e_phone, 1, 1, 2, 1);

	Gtk::Label l_email{"Email"};
	Gtk::Entry e_email;
	e_email.set_placeholder_text("xxx@domain.com");
	grid.attach(l_email, 0, 2, 1, 1);
	grid.attach(e_email, 1, 2, 2, 1);

	dialog.get_content_area()->add(grid);
	dialog.add_button("Insert", Gtk::RESPONSE_OK);
	dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);

	dialog.show_all();
	std::string name;
	//dialog.run();
	while(dialog.run()) {
		try {
			name = e_name.get_text();
			if(name.empty()) {e_name.set_text("### Required ###"); continue;}
			Customer customer{name, e_phone.get_text(), e_email.get_text()};
			store->add_customer(customer);
			break;
		} catch(std::exception& e) {
			Gtk::MessageDialog{*this, "Unable to create new customer " + name + ": " + std::string{e.what()}, false, Gtk::MESSAGE_WARNING}.run();
		break;
		}
	}
	on_view_customers_click();

}

void Mainwin::on_new_order_click() {
	/*Gtk::Dialog dialog{"Order for which customer", *this};
	std::string s;
	Gtk::ComboBoxText c_type{true};
	for(int i=0; i<store->customers(); ++i) {
		s = store->customer(i);
		c_type.append(s);	
	}
	dialog.get_content_area()->pack_start(c_type, Gtk::PACK_SHRINK, 0);
	dialog.show_all();
	dialog.run();*/
}

void Mainwin::on_view_orders_click() {

}

void Mainwin::on_view_customers_click() {
	std::string s = "<tt><u>Current Customers</u>\n";
	for(int i=0; i<store->customers(); ++i) {
		std::ostringstream oss;
		oss << store->customer(i) << '\n';
		s += oss.str();
	}
	display->set_markup(s+"</tt>");
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
