// random_shuffle example
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include "board.h"
//#include "tile.h"
// random generator function:
int myrandom (int i) { return std::rand()%i;}

Board::Board(int tiles) {

  	std::srand ( unsigned ( std::time(0) ) );
	std::vector<std::string> w;
	std::vector<std::string> words {
	"bang", "beam", "bear", "cafe", "came",
	"cold", "come", "cool", "date", "diet",
	"door", "doth", "echo", "exes", "exit",
	"face", "fame", "feed", "fire", "five",
	"four", "free", "frog", "from", "game",
	"goes", "good", "grit", "have", "heal",
	"hear", "here", "hide", "hole", "home",
	"hope", "huge", "keep", "kill", "lace",
	"lame", "leek", "life", "live", "maps",
	"mass", "mate", "maze", "move", "near",
	"need", "nine", "once", "quit", "ques",
	"race", "read", "reed", "reef", "rice",
	"roof", "sins", "stay", "tame", "teen",
	"tens", "tide", "tied", "tree", "twin",
	"zero", "zips",
	};

	
  	// using built-in random generator:
  	std::random_shuffle ( words.begin(), words.end() );

  	// using myrandom:
  	std::random_shuffle ( words.begin(), words.end(), myrandom);

	//_tiles.at(0)="";
	
	for(int j = 0; j < tiles; j++)
	{
		_tiles.push_back(words[j]);
		_tiles.push_back(words[j]);
		
	}
	  	// using built-in random generator:
  	std::random_shuffle ( _tiles.begin(), _tiles.end() );

  	// using myrandom:
  	std::random_shuffle ( _tiles.begin(), _tiles.end(), myrandom);



} 

//std::string Board::attempt(int tile1, int tile2)
//{

//}

std::string Board::to_string(){ return  "i"; }

