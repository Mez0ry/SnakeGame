#include "Game.h"
#include "data.h"


int main()
{
	Game* gm = new Game();

	gm->play();

	delete gm;
	return 0;
}
 