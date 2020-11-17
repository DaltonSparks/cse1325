#include "store.h"
#include <iostream>
#include <algorithm>

Store::Store(std::string name) : _name{name} { }

Store::Store(std::istream& ist) {
    std::getline(ist, _name);
	int size;
    std::string s;
	ist >> size; ist.ignore(32767, '\n');
    while(size-- > 0) {
        std::getline(ist, s);
        if(s == "tool") _products.push_back(new Tool(ist));
        else if(s == "plant") _products.push_back(new Plant(ist));
        else if(s == "mulch") _products.push_back(new Mulch(ist));
        else if(s.size()) throw std::runtime_error{"Invalid product type on input: " + s};
    }
	ist >> size; ist.ignore(32767, '\n');
	//std::sort(_customers.begin(), _customers.end());
	while(size-- > 0) {
		_customers.push_back(new Customer(ist));
		//std::sort(_customers.begin(), _customers.end());
		//std::sort(_customers.begin(), _customers.end());
		sort(_customers);
	}
	//std::sort(_customers.begin(), _customers.end());
	ist >> size; ist.ignore(32767, '\n');
	if(ist.eof()) return;
	while(size-- > 0) {
		_orders.push_back(new Order(ist));
	}
}

void Store::sort(std::vector<Customer*> &customer){
	std::sort(customer.begin(), customer.end(),[](Customer* &a, Customer* &b) -> bool{return a->getname() < b->getname();});
}

void Store::save(std::ostream& ost) {
	ost << _name << '\n';
	ost << _products.size() << std::endl;
	for(Product* p : _products) p->save(ost);
	/*ost << _products.size() << std::endl;
	for(auto s : _products) {
		//ost << typeid(*s).name() << ' '; // Write the name of the actual type
		s->save(ost);
		ost << std::endl;  // new line
  	}*/
	ost << _customers.size() << '\n';
	for(Customer* c : _customers) c->save(ost);
	ost << _orders.size() << '\n';
	for(Order* o : _orders) o->save(ost);
}
std::string Store::name() {return _name;}
void Store::add_product(const Tool& product) {_products.push_back(new Tool{product});}
void Store::add_product(const Plant& product) {_products.push_back(new Plant{product});}
void Store::add_product(const Mulch& product) {_products.push_back(new Mulch{product});}
int Store::products() {return _products.size();}
Product& Store:: product(int index) {return *_products.at(index);}
void Store::add_customer(const Customer& customer) {
	_customers.push_back(new Customer{customer});
	//std::sort(_customers.begin(), _customers.end());
	sort(_customers);
}
int Store::customers() {
	//std::sort(_customers.begin(), _customers.end());
	sort(_customers);
	return _customers.size();
}
const Customer& Store::customer(int index) {return *_customers.at(index);}

int Store::add_order(const Customer& customer){
	_orders.push_back(new Order{customer});
	return _orders.size() - 1;
}
void Store::add_item(int order, Product& product, int quantity){ _orders[order]->add_item(Item{product, quantity}); }
int Store::orders(){return _orders.size();}
const Order& Store::order(int index){return *_orders.at(index);}
