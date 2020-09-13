#ifndef __TILE_h
#define __TILE_H

#include "board.h"

class Tile
{
	public:
		Tile(std::string word);
		bool match(Tile& tile);
		std::string word();
		bool matched();
		static int width();
		std::string to_string();
	private:
		std::string _word;
		bool _matched;
		static int _width;
		static std::string _blank;
};

#endif
