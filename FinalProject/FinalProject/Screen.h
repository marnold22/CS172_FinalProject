#ifndef _SCREEN_
#define _SCREEN_

#include "Dog.h"
#include "Ball.h"
#include <iostream>
using namespace std;

//This is the board or "screen" used as a visual,
//it will be told to refresh every time a command is run,
//the GameController controls the screen
class Screen
{
private:
	char coord[10][10];

public:
	//the screen contains a "Dog" actor and a "Ball" actor
	Dog dog;
	Ball ball;

	//initial set up of board coordinates (coord[x][y])
	void setUp();
	//refreshes the screen with current Dog/Ball locations
	void update();

	//used to return facts about the locations of Dog and Ball
	bool isOverlap(int x1, int y1, int x2, int y2);
	bool isOutside(int x1, int y1);
};

#endif _SCREEN_