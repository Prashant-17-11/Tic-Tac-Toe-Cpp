#ifndef ULTIMATE_LEVEL_H_
#define ULTIMATE_LEVEL_H_

#include <bits/stdc++.h>
#include "Board.h"
#include "Player.h"

class Ultimate_board
{
	public:
		std::vector<Board> board;	//creating the ultimate board
};

class Ultimate_level
{
	public:
		Ultimate_board game_board;

		void ultimate_match();
		void display_instructions();
};

#endif
