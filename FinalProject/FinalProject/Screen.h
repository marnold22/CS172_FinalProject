#ifndef _SCREEN_
#define _SCREEN_

#include "Dog.h"
#include "Ball.h"
#include <iostream>
using namespace std;

class Screen
{
private:
	char coord[10][10];

public:
	Dog dog;
	Ball ball;
	void setUp();
	void update();
	bool isOverlap(int x1, int y1, int x2, int y2);
};

#endif _SCREEN_