#ifndef BOARD_H_
#define BOARD_H_

#include <bits/stdc++.h>
#include <vector>

class Board
{
	public:
		std::vector<char> game_board;

		void generate_board();
		void display_board();
		bool player_move_valid(int);
		bool computer_move_valid(int);
		bool board_state_win();
		bool row();
		bool column();
		bool diagonal();

};

#endif
