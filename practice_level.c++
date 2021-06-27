#include "Practice_level.h"

using namespace std;

void Practice_level :: practice_match()
{
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"\t\tPractice Match"<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<endl<<endl;
}

void Practice_level :: display_instructions()
{
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"Tic-Tac-Toe is played by filling X or O in a 3*3 grid one by one."<<endl;
	cout<<"In practice level you get to make the first move."<<endl;
	cout<<"Winner is decided when either of the players complete a row or column"<<endl;
	cout<<"or diagonal with either X/O (Players choice of symbol)."<<endl;
	cout<<"To fill a cell with the symbol of your choice input its cell no."<<endl;
	cout<<"Board layout is like this:"<<endl;
	cout<<"| 1 | 2 | 3 |\n| 4 | 5 | 6 |\n| 7 | 8 | 9 |"<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
}

int Practice_level :: player_move()
{
	cout<<"Enter the cell the no you want to fill:"<<endl;
	int cell;
	cin>>cell;
	return cell;
}

int Practice_level :: computer_move()
{
	srand(time(0));
	int cell = rand()%9+1;
	return cell;
}

void Practice_level :: victory()
{
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"Congrats!! You Win!!"<<endl;
	cout<<"It seems like you are prepared to face the Almighty Computer!!"<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<endl<<endl;
}

void Practice_level :: defeat()
{
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"You lost!!"<<endl;
	cout<<"It seems like you are not worthy of facing the Almighty Computer!!"<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<endl<<endl;
}
