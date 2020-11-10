#ifndef __ITEM_H
#define __ITEM_H

#include "product.h"

class Item {
	public:
		Item(Product& product, int _quanity);
		Item(std::istream ist);
		void save(std::ostream ost);
		double subtotal();
	private:
		Product* _product;
		int _quantity;
};

#endif
