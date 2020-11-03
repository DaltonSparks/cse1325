#include <iomanip>
#include <iostream>
#include "modulo.h"

Modulo::Modulo(int modulo, int value, int offset) 
			: _modulo{modulo}, _value{value % modulo}, _offset{offset}, _nmsd{nullptr} //directly initialize member variables
{
	_value = (_value - offset) % _modulo;
}

int Modulo::value()
{
	return _value + _offset;
}

void Modulo::set_nmsd(Modulo* nmsd)
{
	_nmsd=nmsd;
}

Modulo& Modulo::operator+=(int rhs)
{
	int sum = _value + rhs;
	if((sum>= _modulo) && _nmsd) (*_nmsd) += (sum / _modulo);
	_value = sum % _modulo;
	return *this;
}

Modulo Modulo::operator+(int rhs)
{
	Modulo d{*this};
	d += rhs;
	return d;
}

Modulo& Modulo::operator++()
{
	*this += 1;
	return *this;
}

int Modulo::compare(const int rhs) 
{
    int i = _value + _offset; // compare what the caller sees, not internal value
    return (i > rhs) ? 1 : ((i < rhs) ? -1 : 0);
}  

std::ostream& operator<<(std::ostream& ost, Modulo& m)
{
	ost << m._value + m._offset;
	return ost;
}

std::istream& operator>>(std::istream& ist, Modulo& m)
{
    ist >> m._value;
    m._value = (m._value - m._offset) % m._modulo;
    return ist;
}
