#include "Challenge_level.h"

using namespace std;

void Challenge_level :: challenge_match()
{
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"\t\tChallenge Match"<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<endl<<endl;
}

void Challenge_level :: display_instructions()
{
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"Tic-Tac-Toe is played by filling X or O in a 3*3 grid one by one."<<endl;
	cout<<"In Challenge level Player to make first move is decided by a toss."<<endl;
	cout<<"Winner is decided when either of the players complete a row or column"<<endl;
	cout<<"or diagonal with either X/O (Players choice of symbol)."<<endl;
	cout<<"In case of tie You will loose!."<<endl;
	cout<<"To fill a cell with the symbol of your choice input its cell no."<<endl;
	cout<<"Board layout is like this:"<<endl;
	cout<<"| 1 | 2 | 3 |\n| 4 | 5 | 6 |\n| 7 | 8 | 9 |"<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
}

int Challenge_level :: player_move()
{
	cout<<"Enter the cell no you want to fill:"<<endl;
	int cell;
	cin>>cell;
	return cell;
}

int Challenge_level :: computer_move(Board board , Player player)
{
	int cell = find_best_move(board,player);
	return cell;
}

int Challenge_level :: find_best_move(Board board , Player player)
{
	int bestMove;
	int bestVal = -1000;
	for(int i = 0 ; i < 9 ; i++)
	{
		if(board.game_board[i] == ' ')
		{
			board.game_board[i] = player.computer_symbol;
			int moveVal= minimax(board,0,false,player);
			board.game_board[i] = ' ';
			if(moveVal > bestVal)
			{
				bestMove = i;
				bestVal = moveVal;
			}
		}
	}
	return bestMove+1;
}

int Challenge_level :: minimax(Board board , int depth , bool is_comp , Player player)
{
	int score = evaluate(board , !is_comp);	//since we have to check if their is winner from last move
	if(score == 10)	//computer wins
	{
		return (score-depth);
	}
	if(score == -10)	//player wins
	{
		return (score+depth);
	}
	if(is_moves_left(board) == false)
	{
		return 0;
	}

	if(is_comp)	//Computer's Turn
	{
		int best = -1000;
		for(int i = 0 ; i < 9 ; i++)
		{
			if(board.game_board[i] == ' ')
			{
				board.game_board[i] = player.computer_symbol;
				best = max(best,minimax(board,depth+1,!is_comp,player));
				board.game_board[i] = ' ';
			}
		}
		return best;
	}
	else	//Player's Turn
	{
		int best = 1000;
		for(int i = 0 ; i < 9 ; i++)
		{
			if(board.game_board[i] == ' ')
			{
				board.game_board[i] = player.player_symbol;
				best = min(best,minimax(board,depth+1,!is_comp,player));
				board.game_board[i] = ' ';
			}
		}
		return best;
	}

}

int Challenge_level :: evaluate(Board board,bool is_comp)
{
	if(!is_comp && board.board_state_win())
	{
		return -10;
	}
	if(is_comp && board.board_state_win())
	{
		return 10;
	}
	else
	{
		return 0;
	}
}

int Challenge_level :: is_moves_left(Board board)
{
	for(int i = 0 ; i < 9 ; i++)
	{
		if(board.game_board[i] == ' ')
		{
			return true;
		}
	}
	return false;
}


void Challenge_level :: victory()
{
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"Congrats!! You Win!!"<<endl;
	cout<<"It seems like you are a worthy to be considered and challenger!!"<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<endl<<endl;
}

void Challenge_level :: defeat()
{
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"You lost!!"<<endl;
	cout<<"It seems like you overestimated yourself human!!"<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<endl<<endl;
}
