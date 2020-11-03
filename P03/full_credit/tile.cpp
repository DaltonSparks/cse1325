#include <iostream>
#include <vector> 
#include "board.h"

int Tile::_width{-1};
std::string Tile::_blank;

Tile::Tile(std::string word) : _word{word}, _matched{false}
{
	if((int)word.size() > _width)
	{
		_width = word.size();
		_blank = "";
		for(int i=0; i <= word.size(); i++)
			_blank = _blank + "-";
	}
}

bool Tile::match(Tile& tile)
{
	if(_word==tile._word)
	{
		_matched=true;
		tile._matched = true;
	}
	return(Tile::_matched);
}

std::string Tile::word(){return _word;}

bool Tile::matched(){return _matched;}

int Tile::width(){return _width;}

std::string Tile::to_string()
{
	if(_matched==true)
		return _word;
	else
		return _blank;
}
