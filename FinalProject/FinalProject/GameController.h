#ifndef _GAMECONTROLLER_
#define _GAMECONTROLLER_

#include "Screen.h"
#include <fstream>
#include <string>
using namespace std;

class GameController
{
private:
	Screen screen;

public:
	void readFile();

};

#endif _GAMECONTROLLER_