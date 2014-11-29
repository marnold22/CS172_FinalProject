#ifndef _SCREEN_
#define _SCREEN_

#include "Dog.h"
#include "Ball.h"
#include <iostream>
using namespace std;

class Screen
{
private:
	Dog dog;
	Ball ball;
	char coord[10][10];

public:
	void setUp();
	void update();
};

#endif _SCREEN_