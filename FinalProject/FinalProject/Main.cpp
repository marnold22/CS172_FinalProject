#include <iostream>
#include "GameController.h"
using namespace std;

int main()
{
	GameController gameController;
	gameController.screen.setUp();
	gameController.screen.update();
	gameController.readFile();

	return 0;
}