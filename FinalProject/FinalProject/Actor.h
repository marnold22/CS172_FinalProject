#ifndef _ACTOR_
#define _ACTOR_

#include <iostream>
using namespace std;

class Actor
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

#endif _ACTOR_