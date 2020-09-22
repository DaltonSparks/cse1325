#include <iomanip>
#include <iostream>
#include "modulo.h"

Modulo::Modulo(int modulo, int value, int offset) 
			: _modulo{modulo}, _value{value}, _offset{offset} //directly initialize member variables
{
	//uhh nothing goes here that I know of
}

int Modulo::value()
{
	return _value;
}

void Modulo::set_nmsd(Modulo* nmsd)
{
	_nmsd=nmsd;
}

Modulo& Modulo::operator+=(int rhs)
{
	for( ; rhs>0; --rhs) ++(*this);
	return *this; _modulo++;
	
}

Modulo Modulo::operator+(int rhs)
{
	Modulo d{*this};
	d += rhs;
	return d;
}

Modulo& Modulo::operator++()
{
	if(_value >= 59)
	{
		_value = 0;
		_modulo++;
	}
	else
		++_value;

	return *this;
}

bool Modulo::operator==(int rhs) {return  _modulo == rhs ;}
bool Modulo::operator!=(int rhs) {return  _modulo != rhs;}
bool Modulo::operator<(int rhs) {return _modulo < rhs;}
bool Modulo::operator<=(int rhs) {return  _modulo <= rhs;}
bool Modulo::operator>(int rhs) {return  _modulo > rhs;}
bool Modulo::operator>=(int rhs) {return _modulo >= rhs;}




/*inline bool Modulo::operator==(int rhs)
{
	return _modulo == rhs;
}*/

std::ostream& operator<<(std::ostream& ost, Modulo& m)
{
	ost << m._value + m._offset;
	return ost;
}


