#ifndef __STORE_H
#define __STORE_H

#include "tool.h"
#include "plant.h"
#include "mulch.h"
#include "customer.h"
#include "order.h"

#include <vector>

class Store {
  public:
    Store(std::string name);
	Store(std::istream& ist);
	void save(std::ostream& ost);
    void add_product(const Tool& product);
    void add_product(const Plant& product);
    void add_product(const Mulch& product);
    int products();
    Product& product(int index);
	std::string name();
	void sort(std::vector<Customer*> &customer);

	void add_customer(const Customer& cutomer);
	int customers();
	const Customer& customer(int index);

	int add_order(const Customer& customer);
	void add_item(int order, Product& product, int quantity);
	int orders();
	const Order& order(int index);

	//typedef Orders::iterator iterator;
	//typedef Orders::const_iterator const_iterator;
	//iterator begin() {return orders.begin();}
	//iterator end() {return orders.end();}
	
  private:
    std::string _name;
    std::vector<Product*> _products;
	std::vector<Customer*> _customers;
	std::vector<Order*> _orders;

};

#endif
