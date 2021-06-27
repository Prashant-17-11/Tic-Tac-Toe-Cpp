#include "Board.h"

using namespace std;


void Board :: generate_board()
{
	game_board.clear();

	for(int i = 1 ; i <= 9 ; i++)
	{
		game_board.push_back(' ');
	}
}

void Board :: display_board()
{
	cout<<"-----------------------------------------------------------------"<<endl<<endl;
	for(int i = 0 ; i < 9 ; i++)
	{
		cout<<"| "<<game_board[i]<<" ";
		if((i+1)% 3 == 0)
		{
			cout<<"|\n";
		}
	}
	cout<<endl<<"-----------------------------------------------------------------"<<endl;
	cout<<endl<<endl;
}

bool Board :: player_move_valid(int move)
{
	if(game_board[move-1] != ' ')
	{
		cout<<"Selected cell is already filled!!\nTry  again!!"<<endl;
		return false;
	}
	return true;
}

bool Board :: computer_move_valid(int move)
{
	if(game_board[move-1] != ' ')
	{
		return false;
	}
	return true;
}


bool Board :: board_state_win()
{
	bool win = false;
	if(row() || column() || diagonal())
	{
		win = true;
	}
	return win;
}

bool Board :: row()
{
	if(game_board[0] == game_board[1] && game_board[0] == game_board[2] && game_board[0] != ' ')
	{
		return true;
	}
	if(game_board[3] == game_board[4] && game_board[3] == game_board[5] && game_board[3] != ' ')
	{
		return true;
	}
	if(game_board[6] == game_board[7] && game_board[6] == game_board[8] && game_board[6] != ' ')
	{
		return true;
	}
	return false;
}

bool Board :: column()
{
	if(game_board[0] == game_board[3] && game_board[0] == game_board[6] && game_board[0] != ' ')
	{
		return true;
	}
	if(game_board[1] == game_board[4] && game_board[1] == game_board[7] && game_board[1] != ' ')
	{
		return true;
	}
	if(game_board[2] == game_board[5] && game_board[2] == game_board[8] && game_board[2] != ' ')
	{
		return true;
	}
	return false;
}

bool Board :: diagonal()
{
	if(game_board[0] == game_board[4] && game_board[0] == game_board[8] && game_board[0] != ' ')
	{
		return true;
	}
	if(game_board[2] == game_board[4] && game_board[2] == game_board[6] && game_board[2] != ' ')
	{
		return true;
	}
	return false;
}
