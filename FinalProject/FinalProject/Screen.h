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

public:
	void update();
};

#endif _SCREEN_