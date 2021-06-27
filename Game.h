#ifndef GAME_H_
#define GAME_H_

#include "Player.h"
#include "Board.h"
#include "Practice_level.h"
#include "Challenge_level.h"
#include "Ultimate_level.h"

class Game
{
	public:
	Player player;
	Board board;
	Practice_level practice;
	Challenge_level challenge;
	Ultimate_level ultimate;

	void play_game();
	void display_intro();
	void display_dialouge1();
	void input_player_name();
	void display_dialouge2();
	char play_or_surrender();
	char input_choice(int);
	bool is_input_integer_of_range(char,int);
	void player_accepts_defeat();
	void display_dialouge3();
	char present_options();
	void play_practice_match();
	char select_player_symbol();
	void game_exit();
	void play_challege_match();
	int coin_toss();
	void play_ultimate_match();
};

#endif
