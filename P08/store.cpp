#include "store.h"
#include <iostream>

Store::Store(std::string name) : _name{name} { }

void Store::save(std::ostream& ost) {
	ost << _name << std::endl;
	ost << _products.size() << std::endl;
	for(auto s : _products) {
		//ost << typeid(*s).name() << ' '; // Write the name of the actual type
		s->save(ost);
		ost << std::endl;  // new line
  	}
}

void Store::add_product(const Tool& product) {_products.push_back(new Tool{product});}
void Store::add_product(const Plant& product) {_products.push_back(new Plant{product});}
void Store::add_product(const Mulch& product) {_products.push_back(new Mulch{product});}
int Store::products() {return _products.size();}
const Product& Store:: product(int index) {return *_products.at(index);}

