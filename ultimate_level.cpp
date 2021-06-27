#include "Ultimate_level.h"

using namespace std;

void Ultimate_level :: ultimate_match()
{
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"\t\tUltimate Level Match"<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<endl<<endl;
}

void Ultimate_level :: display_instructions()
{
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"Tic-Tac-Toe is played by filling X or O in a 3*3 grid one by one."<<endl;
	cout<<"Ultimate level takes the game a level up where you play simultaneously on 9 boards"<<endl;
	cout<<"In Ultimate level Player makes the first move."<<endl;
	cout<<"The board looks something like this:"<<endl<<endl;
	cout<<"|| B1 C1 | B1 C2 | B1 C3 || B2 C1 | B2 C2 | B2 C3 || B3 C1 | B3 C2 | B3 C3 ||"<<endl;
	cout<<"|| B1 C4 | B1 C5 | B1 C6 || B2 C4 | B2 C5 | B2 C6 || B3 C4 | B3 C5 | B3 C6 ||"<<endl;
	cout<<"|| B1 C7 | B1 C8 | B1 C9 || B2 C7 | B2 C8 | B2 C9 || B3 C7 | B3 C8 | B3 C9 ||"<<endl;
	cout<<"============================================================================="<<endl;
	cout<<"|| B4 C1 | B4 C2 | B4 C3 || B5 C1 | B5 C2 | B5 C3 || B6 C1 | B6 C2 | B6 C3 ||"<<endl;
	cout<<"|| B4 C4 | B4 C5 | B4 C6 || B5 C4 | B5 C5 | B5 C6 || B6 C4 | B6 C5 | B6 C6 ||"<<endl;
	cout<<"|| B4 C7 | B4 C8 | B4 C9 || B5 C7 | B5 C8 | B5 C9 || B6 C7 | B6 C8 | B6 C9 ||"<<endl;
	cout<<"============================================================================="<<endl;
	cout<<"|| B7 C1 | B7 C2 | B7 C3 || B8 C1 | B8 C2 | B8 C3 || B9 C1 | B9 C2 | B9 C3 ||"<<endl;
	cout<<"|| B7 C4 | B7 C5 | B7 C6 || B8 C4 | B8 C5 | B8 C6 || B9 C4 | B9 C5 | B9 C6 ||"<<endl;
	cout<<"|| B7 C7 | B7 C8 | B7 C9 || B8 C7 | B8 C8 | B8 C9 || B9 C7 | B9 C8 | B9 C9 ||"<<endl;
	cout<<endl;
	cout<<"B stands for Board and C stands for Cell"<<endl;
	cout<<"The rules for playing the game are:"<<endl;
	cout<<"In each turn player gets to mark one single cell in any one board."<<endl;
	cout<<"The twist is that the you don't get to decide the board you play on."<<endl;
	cout<<"It is decided by the move of the previous player."<<endl;
	cout<<"Suppose the previous player marked in the cell 6 of a board then the "<<endl;
	cout<<"next player can make a move only in board 6."<<endl;
	cout<<"If you are the player starting the game or the previous players move sends you "<<endl;
	cout<<"to a board which has already been won by one of the players then you get a wildcard."<<endl;
	cout<<"In such a situation you can choose whichever board you want to play on."<<endl;
	cout<<"The winner is decided when one player wins three boards in a row/column/diagonal"<<endl;
	cout<<"The game ends when either of the player has won or game reached a state of tie."<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;

}
