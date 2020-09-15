#include <iostream>
#include <ctime>
#include <vector>
#include "board.h"
#include "tile.h"
int main()
{
	int num;
	std::cout << "Number of tiles? ";
	std::cin >> num;
	Board{num};

	int NumGuesses=1, tile1, tile2;
	std::cout << "Guess " << NumGuesses << ", " << "select 2 unmatched tiles: ";
	std::cin >> tile1;
	std::cin >> tile2;
}
