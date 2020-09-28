#include <iostream>
#include <vector>
#include "gate.h"

int main()
{
	std::cout << "A B C D  Q" << std::endl;
	std::cout << "= = = =  =" << std::endl;
	And gate1;
	And gate;
	Or gate2;
	gate.connect(gate2, 1);
	gate1.connect(gate2, 2);
	std::vector<int> A {0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1};
	std::vector<int> B {0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1};
	std::vector<int> C {0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1};
	std::vector<int> D {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1};
	for(int i = 0; i < A.size(); i++)
	{
		std::cout << A.at(i) << " " << B.at(i) << " " << C.at(i) << " " << D.at(i);
		gate.input(1,A.at(i));
		gate.input(2,B.at(i));
		gate1.input(1,C.at(i));
		gate1.input(2,D.at(i));
		std::cout << "  " << gate2.output() << std::endl;
	}
} 
