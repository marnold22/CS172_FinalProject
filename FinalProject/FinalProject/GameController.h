#ifndef _GAMECONTROLLER_
#define _GAMECONTROLLER_

#include "Screen.h"
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class GameController
{
public:
	Screen screen;
	void readFile();
	void runInstructions(const vector<string>& words);
};

#endif _GAMECONTROLLER_