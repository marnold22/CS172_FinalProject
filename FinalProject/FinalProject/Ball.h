#ifndef _BALL_
#define _BALL_

#include <iostream>
using namespace std;

class Ball
{
private:
	int xPos;
	int yPos;

public:
	int getXPos();
	int getYPos();
	int setXPos(int newX);
	int setYPos(int newY);

};

#endif _BALL_