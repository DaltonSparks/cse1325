#include <iostream>
#include <ctime>
#include <vector>
#include "board.h"
//#include "tile.h"
int main()
{
	int num;
	std::cout << "Number of tiles? ";
	std::cin >> num;
	Board board{num};

	int NumGuesses=0, tile1, tile2;

	while(!board.solved())
	{
		std::cout << board.to_string() << "Guess " << ++NumGuesses << ", " << "select 2 unmatched tiles: ";
		std::cin >> tile1 >> tile2;
		std::cout << board.attempt(tile1, tile2) << std::endl;
	}

	std::cout << "\nWINNER after " << NumGuesses << " guesses\n\n" << board.to_string() << std::endl;
}
