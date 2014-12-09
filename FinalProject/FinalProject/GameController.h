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
	//determines length of pause between command
	int waitTime = 3000;
public:
	Screen screen;
	
	//asks the user for a file and puts all the words in a vector<string>
	void readFile();
	//takes in a vector<string> and runs commands based on the words
	void runInstructions(const vector<string>& words);

	//functions for moving Dog standard directions
	void moveDogLeft();
	void moveDogRight();
	void moveDogUp();
	void moveDogDown();

	//functions for moving Dog diagonal directions
	void moveDogUpDiagLeft();
	void moveDogUpDiagRight();
	void moveDogDownDiagLeft();
	void moveDogDownDiagRight();

	//if Dog is near ball, make Dog jump over the ball
	void jumpBall();

	//functions for moving Ball standard directions
	void moveBallLeft();
	void moveBallRight();
	void moveBallUp();
	void moveBallDown();

	//functions for moving Ball diagonal directions
	void moveBallUpDiagRight();
	void moveBallUpDiagLeft();
	void moveBallDownDiagRight();
	void moveBallDownDiagLeft();


};

#endif _GAMECONTROLLER_