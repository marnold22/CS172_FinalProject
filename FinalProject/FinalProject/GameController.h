#ifndef _GAMECONTROLLER_
#define _GAMECONTROLLER_

#include "Screen.h"
#include <fstream>
#include <string>
using namespace std;

class GameController
{
public:
	Screen screen;
	void readFile();
};

#endif _GAMECONTROLLER_