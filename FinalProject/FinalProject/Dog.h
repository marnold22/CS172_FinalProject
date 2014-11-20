#ifndef _DOG_
#define _DOG_

#include <iostream>
using namespace std;

class Dog
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

#endif _DOG_