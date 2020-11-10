#ifndef __ORDER_H
#define __ORDER_H

#include "customer.h"
#include "item.h"
#include <iostream>
#include <vector>

class Order {
	private:
		std::vector<Item> _items;
		//Customer customer;
	public:
		//Order(Customer& customer);
		Order(std::istream ist);
		void save(std::ostream ost);
		void add_item(const Item& item);
		double total();
};

#endif
