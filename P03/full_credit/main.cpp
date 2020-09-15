#include <iostream>
#include <ctime>
#include <vector>
#include "board.h"
int main()
{
	int num;
	std::cout << "Number of tiles? ";
	std::cin >> num;
	Board{num};
}
