#ifndef CHALLENGE_LEVEL_H_
#define CHALLENGE_LEVEL_H_

#include <bits/stdc++.h>
#include "Board.h"
#include "Player.h"

class Challenge_level
{
	public:

	void challenge_match();
	void display_instructions();
	int player_move();
	int computer_move(Board,Player);
	int find_best_move(Board,Player);
	int minimax(Board,int,bool,Player);
	int evaluate(Board,bool);
	int is_moves_left(Board);
	void victory();
	void defeat();
};

#endif
