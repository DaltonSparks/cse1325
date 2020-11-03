 #ifndef __CUSTOMER_H
#define __CUSTOMER_H

#include <gtkmm.h>
#include "store.h"

class Customer {
	public:
		Customer(std::string name, std::string phone, std::string email);
		//Customer(std::istream& ist);
		//void save(std::ostream& ost);
	private:
		std::string name;
		std::string phone;
		std::string string;
}

#endif
