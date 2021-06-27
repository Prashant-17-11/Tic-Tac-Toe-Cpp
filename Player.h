#ifndef PLAYER_H_
#define PLAYER_H_
#include <bits/stdc++.h>

class Player
{
	public:
		std::string name;
		int match_played;
		int match_win;
		char player_symbol;
		char computer_symbol;
		int moves_played;
		bool win;
		bool lose;
		Player();
};

#endif
