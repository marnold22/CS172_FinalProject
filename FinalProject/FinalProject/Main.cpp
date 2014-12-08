#include <iostream>
#include "GameController.h"
using namespace std;

int main()
{
	//Let's create a GameController object that will set up a screen
	GameController gameController;
	gameController.screen.setUp();
	gameController.screen.update();

	//Now read in a file and run the commands
	gameController.readFile();

	return 0;
}