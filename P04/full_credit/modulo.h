#ifndef _MODULO_H
#define _MODULO_H

class Modulo
{
	int _value;
	int _modulo;
	int _offset
	Modulo* _nmsd
	public:
		int compare(const int rhs);
		Modulo(modulo : int = 10, value : int = 0, offset : int = 0);
		set_nmsd(Modulo* nmsd);
		int value();
		Modulo& operator+=(int rhs);
		Modulo operator+(int rhs);
		Modulo& operator++();
		inline bool operator==(int rhs);
		inline bool operator!=(int rhs);
		inline bool operator<(int rhs);
		inline bool operator<=(int rhs);
		inline bool operator>(int rhs);
		inline bool operator>=(int rhs);
		freind std::ostream& operator<<(std::ostream& ost, Modulo& m);
		freind std::ostream& operator>>(std::ostream& ost, Modulo& m);
		
};

#endif
