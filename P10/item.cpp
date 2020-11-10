#include "item.h"
#include <iostream>

Item::Item(Product& product, int _quanity){}

Item::Item(std::istream ist){
}
void Item::save(std::ostream ost){
	//ost << _quanity << '\n';
}
double Item::subtotal() {return 0;}
