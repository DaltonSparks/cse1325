#include <iostream> 
#include "gate.h"

int main()
{
	std::cout << "A B C D  Q" << std::endl;
	std::cout << "= = = =  =" << std::endl;
	And gate1;
	Or gate2;
	gate1.connect(gate2, 1);
	gate1.input(1,0);
	gate1.input(0,0);
	int Num1 = gate1.output();
	gate1.input(1,0);
	gate1.input(0,0);
	bool Num2 = gate1.output();
	//gate2.input(1,Num1);
	//gate2.input(0,Num2);
	//std::cout << gate2.output() << std::endl;
} 
