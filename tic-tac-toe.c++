#include "Game.h"

using namespace std;

void close()
{
	cout<<endl<<endl;
	cout<<"Press ENTER key to close the program!"<<endl;
	while(getchar() != '\n');
	getchar();
}

int main()
{
	Game game;

	game.play_game();
	close();
	return 0;
}
