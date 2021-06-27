#include "Game.h"

using namespace std;

void Game :: play_game()
{
	display_intro();
	display_dialouge1();
	input_player_name();
	display_dialouge2();
	char choice = play_or_surrender();
	if(choice == '2')
	{
		player_accepts_defeat();
		return;
	}
	display_dialouge3();
	choice = present_options();
	while(choice != '4')
	{
		if(choice == '1')
		{
			play_practice_match();
		}
		else if(choice == '2')
		{
			play_challege_match();
		}
		else
		{
			play_ultimate_match();
		}
		choice = present_options();
	}
	game_exit();
}

void Game :: display_intro()
{
	cout<<endl<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<"\t     Welcome"<<endl;
	cout<<"\t\tTo"<<endl;
	cout<<"\t    Tic-Tac-Toe"<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<endl<<endl;
}

void Game :: display_dialouge1()
{
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"Hello human!!!"<<endl;
	cout<<"It seems you have come here to challenge the almighty computer."<<endl;
	cout<<"Well your will to face a shameful defeat shall be answered."<<endl;
	cout<<"But before we begin, declare your identity!"<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<endl<<endl;
}

void Game :: input_player_name()
{
	cout<<"Enter your player name:"<<endl;
	getline(cin,player.name);
	cout<<endl<<endl;
}

void Game :: display_dialouge2()
{
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"Very well "<<player.name<<" prepare yourself for my VICTORY!!!"<<endl;
	cout<<"Being the kind hearted soul, I give you a chance to accept defeat"<<endl;
	cout<<"and save yourself from the embarrassment you are going to face."<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<endl<<endl;
}

char Game :: play_or_surrender()
{
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"Select '1' to begin the game."<<endl;
	cout<<"Select '2' to accept defeat."<<endl;
	char choice = input_choice(2);
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<endl<<endl;
	return choice;
}

char Game::input_choice(int limit)
{
	char choice;
	cout<<endl<<"Input your choice:"<<endl;
	cin>>choice;
	if(is_input_integer_of_range(choice,limit))
	{
			return choice;
	}
	else
	{
		cout<<"Select a valid input!!"<<endl;
		cout<<endl;
		return input_choice(limit);
	}
}

bool Game :: is_input_integer_of_range(char x , int limit)
{
	bool num_check = true;

	if(!(x >= '1' && x <= (char)(limit+48)))
	{
		num_check = false;
	}

	return num_check;
}

void Game :: player_accepts_defeat()
{
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"Ha ha ha, smart choice human."<<endl;
	cout<<"Go back and live your life of a coward happily cause you have saved"<<endl;
	cout<<"yourself from being defeated by the almighty computer.!!!"<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<endl<<endl;
}

void Game :: display_dialouge3()
{
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"So you have decided to play against me."<<endl;
	cout<<"Very well so shall it be. I appreciate your courage."<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<endl<<endl;
}

char Game :: present_options()
{
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"Select '1' to practice."<<endl;
	cout<<"Select '2' to play against the Almighty Computer"<<endl;
	cout<<"Select '3' to play ultimate level."<<endl;
	cout<<"Select '4' to exit."<<endl;
	char choice = input_choice(4);
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<endl<<endl;
	return choice;
}

void Game :: play_practice_match()
{
	practice.practice_match();
	practice.display_instructions();
	board.generate_board();
	player.player_symbol = select_player_symbol();
	if(player.player_symbol == 'O')
	{
		player.computer_symbol = 'X';
	}
	else
	{
		player.computer_symbol = 'O';
	}

	player.moves_played = 0;
	player.win = false;
	player.lose = false;
	board.display_board();

	while(!player.win && !player.lose && player.moves_played != 5)
	{
		int move = practice.player_move();
		while(!board.player_move_valid(move))
		{
			move = practice.player_move();
		}

		board.game_board[move-1] = player.player_symbol;
		cout<<"Your move!"<<endl;
		board.display_board();
		player.moves_played++;
		player.win = board.board_state_win();
		if(player.moves_played == 5 || player.win)
		{
			break;
		}

		move = practice.computer_move();
		while(!board.computer_move_valid(move))
		{
			move = practice.computer_move();
		}

		board.game_board[move-1] = player.computer_symbol;
		cout<<"Computers move!"<<endl;
		board.display_board();
		player.lose = board.board_state_win();
	}

	if(player.win)
	{
		player.match_win++;
		practice.victory();
	}
	else
	{
		practice.defeat();
	}
	player.match_played++;
}

char Game :: select_player_symbol()
{
	char choice;
	cout<<endl<<"-----------------------------------------------------------------"<<endl;
	cout<<"Select X or O as your symbol to play the game.";
	cin>>choice;
	if(choice == 'X' || choice == 'O')
	{
		return choice;
	}
	else
	{
		cout<<"Select a valid input!!"<<endl;
		return select_player_symbol();
	}
}

void Game :: game_exit()
{
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"Player Name:\t\t"<<player.name<<endl;
	cout<<"Matches Played:\t\t"<<player.match_played<<endl;
	cout<<"Matches win:\t\t"<<player.match_win<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
}

void Game :: play_challege_match()
{
	challenge.challenge_match();
	challenge.display_instructions();
	board.generate_board();
	player.player_symbol = select_player_symbol();
	int first_player = coin_toss();
	if(player.player_symbol == 'O')
	{
		player.computer_symbol = 'X';
	}
	else
	{
		player.computer_symbol = 'O';
	}

	player.moves_played = 0;
	player.win = false;
	player.lose = false;
	board.display_board();

	if(first_player)
	{
		while(!player.win && !player.lose)
		{
			int move = challenge.player_move();
			while(!board.player_move_valid(move))
			{
				move = challenge.player_move();
			}

			board.game_board[move-1] = player.player_symbol;
			cout<<"Your move!"<<endl;
			board.display_board();
			player.moves_played++;
			player.win = board.board_state_win();
			if(player.moves_played == 5 || player.win)
			{
				break;
			}

			move = challenge.computer_move(board , player);
			board.game_board[move-1] = player.computer_symbol;
			cout<<"Computers move!"<<endl;
			board.display_board();
			player.lose = board.board_state_win();
		}
	}	//player plays first
	else
	{
		while(!player.win && !player.lose)
		{
			int move = challenge.computer_move(board, player);
			board.game_board[move-1] = player.computer_symbol;
			cout<<"Computers move!"<<endl;
			board.display_board();
			player.lose = board.board_state_win();
			if(player.moves_played == 4 || player.lose)
			{
				break;
			}

			move = challenge.player_move();
			while(!board.player_move_valid(move))
			{
				move = challenge.player_move();
			}
			board.game_board[move-1] = player.player_symbol;
			cout<<"Your move!"<<endl;
			board.display_board();
			player.moves_played++;
			player.win = board.board_state_win();
		}
	}	//computer plays first
	if(player.win)
	{
		player.match_win++;
		challenge.victory();
	}
	else
	{
		challenge.defeat();
	}
	player.match_played++;
}

int Game :: coin_toss()
{
	cout<<endl<<"Enter 1 if you bet Heads."<<endl;
	cout<<"Enter 2 if you bet Tails."<<endl;
	int bet;
	cin>>bet;
	if(bet == 1 || bet == 2)
	{
		srand(time(0));
		int coin = rand()%2 + 1;
		if(coin == 1)
		{
			cout<<"Coin toss result -> Heads"<<endl;
		}
		else
		{
			cout<<"Coin toss result -> Tails"<<endl;
		}
		if(bet == coin)
		{
			cout<<"You get to play first!!"<<endl;
			return 1;
		}
		else
		{
			cout<<"Computer plays first!!"<<endl;
			return 0;
		}
	}
	else
	{
		cout<<"Select a valid choice!"<<endl;
		return coin_toss();
	}
}

void Game :: play_ultimate_match()
{
	ultimate.ultimate_match();
	ultimate.display_instructions();
}
