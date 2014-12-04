#ifndef _GAMECONTROLLER_
#define _GAMECONTROLLER_

#include "Screen.h"
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class GameController
{
private:
	int waitTime = 900;
public:
	Screen screen;
	void readFile();
	void runInstructions(const vector<string>& words);
	int actorGetXPos(Actor a);
	int dogGetYPos(Actor a);
	void dogSetXPos(Actor a, int newX);
	void dogSetYPos(Actor a, int newY);

	void moveDogLeft();
	void moveDogRight();
	void moveDogUp();
	void moveDogDown();

	void moveDogUpDiagLeft();
	void moveDogUpDiagRight();
	void moveDogDownDiagLeft();
	void moveDogDownDiagRight();

	void jumpBall();

	void moveBallLeft();
	void moveBallRight();
	void moveBallUp();
	void moveBallDown();
};

#endif _GAMECONTROLLER_