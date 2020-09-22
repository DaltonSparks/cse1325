#ifndef _MODULO_H
#define _MODULO_H

#include <iomanip>
#include <iostream>

class Modulo
{
	private:
		int _value;
		int _modulo;
		int _offset;
		Modulo* _nmsd;
		int compare(const int rhs);
	public:
		Modulo(int modulo = 10, int value = 0, int offset = 0);
		void set_nmsd(Modulo* nmsd);
		int value();
		Modulo& operator+=(int rhs);
		Modulo operator+(int rhs);
		Modulo& operator++();
		bool operator==(int rhs);
		bool operator!=(int rhs);
		bool operator<(int rhs);
		bool operator<=(int rhs);
		bool operator>(int rhs);
		bool operator>=(int rhs);
		friend std::ostream& operator<<(std::ostream& ost, Modulo& m);
		friend std::ostream& operator>>(std::ostream& ost, Modulo& m);
		
};

#endif
