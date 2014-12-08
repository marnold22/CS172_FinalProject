#include "GameController.h"
#include <vector>
#include <thread>
#include <chrono>
#include <string>

//asks the user for a file and puts all the words in a vector<string>
void GameController::readFile()
{
	string userInput;
	cout << "Please enter a file name: ";
	getline(cin, userInput);

	fstream userFile(userInput, ios::in);

	if (!userFile)
	{
		cout << "Can't open file.\n";
	}
	else
	{
		string word;
		vector<string> words;
		while (userFile >> word)
		{
			words.push_back(word);
		}

		//use to display the vector words if troubleshooting
		/*
		for (int i = 0; i < words.size(); i++)
		{
		cout << i << ". " << words[i] << " ";
		}
		cout << endl;
		*/

		runInstructions(words);
	}
}

//takes in a vector<string> and runs commands based on the words
void GameController::runInstructions(const vector<string>& words)
{
	int i(0);
	
	//loop until we have read through all the words (and consequently all the commands)
	while (i < words.size())
	{
		////////////////////MOVE
		if (words[i] == "move")
		{
			/////////////////////DOG
			if (words[i + 1] == "dog")
			{
				if (words[i + 2] == "up") 
				{
					moveDogUp();
					i += 3;
				}
				else if (words[i + 2] == "down")
				{
					moveDogDown();
					i += 3;
				}
				else if (words[i + 2] == "left")
				{
					moveDogLeft();
					i += 3;
				}
				else if (words[i + 2] == "right")
				{
					moveDogRight();
					i += 3;
				}
				else if (words[i + 2] == "UpDiagRight")
				{
					moveDogUpDiagRight();
					i += 3;
				}
				else if (words[i + 2] == "UpDiagLeft")
				{
					moveDogUpDiagLeft();
					i += 3;
				}
				else if (words[i + 2] == "DownDiagRight")
				{
					moveDogDownDiagRight();
					i += 3;
				}
				else if (words[i + 2] == "DownDiagLeft")
				{
					moveDogDownDiagLeft();
					i += 3;
				}
				else
				{
					cout << "Could not understand command." << endl;
					i++;
				}
			}
			////////////////////////BALL
			else if (words[i + 1] == "ball")
			{
				if (words[i + 2] == "up")
				{
					moveBallUp();
					i += 3;
				}
				else if (words[i + 2] == "down")
				{
					moveBallDown();
					i += 3;	
				}
				else if (words[i + 2] == "left")
				{
					moveBallLeft();
					i += 3;
				}
				else if (words[i + 2] == "right")
				{
					moveBallRight();
					i += 3;				
				}

				else if (words[i + 2] == "UpDiagRight")
				{
					moveBallUpDiagLeft();
					i += 3;	
				}

				else if (words[i + 2] == "UpDiagLeft")
				{
					moveBallUpDiagLeft();
					i += 3;			
				}

				else if (words[i + 2] == "DownDiagRight")
				{
					moveBallDownDiagRight();
					i += 3;		
				}

				else if (words[i + 2] == "DownDiagLeft")
				{
					moveBallDownDiagLeft();
					i += 3;			
				}
				else
				{
					cout << "Couldn't understand command." << endl;
					i++;
				}
			}
			////////////////////ERROR
			else
			{
				cout << "Could not understand command." << endl;
				i++;
			}
		}
		/////////////////JUMP
		else if (words[i] == "jump")
		{
			if (words[i + 1] == "ball")
			{
				//check for ball to the right or left
				for (int j = -1; j < 2; j += 2)
				{
					if (screen.isOverlap(screen.dog.getXPos() + j, screen.dog.getYPos(), screen.ball.getXPos(), screen.ball.getYPos()) && !screen.isOutside(screen.dog.getXPos() + (j*2), screen.dog.getYPos()))
					{
						screen.dog.setXPos(screen.dog.getXPos() + (j*2));
						j += 1000;
					}
				}
				//check for ball above or below
				for (int j = -1; j < 2; j += 2)
				{
					if (screen.isOverlap(screen.dog.getXPos(), screen.dog.getYPos() + j, screen.ball.getXPos(), screen.ball.getYPos()) && !screen.isOutside(screen.dog.getXPos(), screen.dog.getYPos() + (j * 2)))
					{
						screen.dog.setYPos(screen.dog.getYPos() + (j * 2));
						j += 1000;
					}
				}
				i += 2;
				screen.update();
				cout << "jump ball" << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(waitTime)); //wait
			}
			//////////ERROR
			else
			{
				cout << "Could not understand command." << endl;
				i++;
			}
		}
		///////////ERROR
		else
		{
			cout << "Could not understand command. " << endl;
			i++;
		}
	}
}

//---------------------------------------------
//functions for moving Dog standard directions
//---------------------------------------------

void GameController::moveDogLeft()
{
	if (screen.dog.getXPos() != 0 && !screen.isOverlap(screen.dog.getXPos() - 1, screen.dog.getYPos(), screen.ball.getXPos(), screen.ball.getYPos()))
		screen.dog.setXPos(screen.dog.getXPos() - 1);
	screen.update();
	cout << "move dog left" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(waitTime)); //wait
}

void GameController::moveDogRight()
{
	if (screen.dog.getXPos() != 9 && !screen.isOverlap(screen.dog.getXPos() + 1, screen.dog.getYPos(), screen.ball.getXPos(), screen.ball.getYPos()))
		screen.dog.setXPos(screen.dog.getXPos() + 1);
	screen.update();
	cout << "move dog right" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(waitTime)); //wait
}

void GameController::moveDogUp()
{
	if (screen.dog.getYPos() != 9 && !screen.isOverlap(screen.dog.getXPos(), screen.dog.getYPos() + 1, screen.ball.getXPos(), screen.ball.getYPos()))
		screen.dog.setYPos(screen.dog.getYPos() + 1);
	screen.update();
	cout << "move dog up" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(waitTime)); //wait
}

void GameController::moveDogDown()
{
	if (screen.dog.getYPos() != 0 && !screen.isOverlap(screen.dog.getXPos(), screen.dog.getYPos() - 1, screen.ball.getXPos(), screen.ball.getYPos()))
		screen.dog.setYPos(screen.dog.getYPos() - 1);
	screen.update();
	cout << "move dog down" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(waitTime)); //wait
}

//---------------------------------------------
//functions for moving Dog diagonal directions
//---------------------------------------------

void GameController::moveDogUpDiagLeft()
{
	if (screen.dog.getXPos() != 0 && screen.dog.getYPos() != 9 && !screen.isOverlap(screen.dog.getXPos() - 1, screen.dog.getYPos() + 1, screen.ball.getXPos(), screen.ball.getYPos()))
		screen.dog.setXPos(screen.dog.getXPos() - 1);
	screen.dog.setYPos(screen.dog.getYPos() + 1);
	screen.update();
	cout << "move dog UpDiagLeft" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(waitTime)); //wait
}

void GameController::moveDogUpDiagRight()
{
	if (screen.dog.getXPos() != 9 && screen.dog.getYPos() != 9 && !screen.isOverlap(screen.dog.getXPos() + 1, screen.dog.getYPos() + 1, screen.ball.getXPos(), screen.ball.getYPos()))
		screen.dog.setXPos(screen.dog.getXPos() + 1);
	screen.dog.setYPos(screen.dog.getYPos() + 1);
	screen.update();
	cout << "move dog UpDaigRight" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(waitTime)); //wait
}

void GameController::moveDogDownDiagLeft()
{
	if (screen.dog.getXPos() != 0 && screen.dog.getYPos() != 0 && !screen.isOverlap(screen.dog.getXPos() - 1, screen.dog.getYPos() - 1, screen.ball.getXPos(), screen.ball.getYPos()))
		screen.dog.setXPos(screen.dog.getXPos() - 1);
	screen.dog.setYPos(screen.dog.getYPos() - 1);
	screen.update();
	cout << "move dog DownDiagLeft" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(waitTime)); //wait
}

void GameController::moveDogDownDiagRight()
{
	if (screen.dog.getXPos() != 9 && screen.dog.getYPos() != 0 && !screen.isOverlap(screen.dog.getXPos() + 1, screen.dog.getYPos() - 1, screen.ball.getXPos(), screen.ball.getYPos()))
		screen.dog.setXPos(screen.dog.getXPos() + 1);
		screen.dog.setYPos(screen.dog.getYPos() - 1);
	screen.update();
	cout << "move dog DownDiagRight" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(waitTime)); //wait
}

//----------------------------------------------
//functions for moving Ball standard directions
//----------------------------------------------

void GameController::moveBallLeft()
{
	if (screen.ball.getXPos() != 0 && !screen.isOverlap(screen.ball.getXPos() - 1, screen.ball.getYPos(), screen.dog.getXPos(), screen.dog.getYPos()))
		screen.ball.setXPos(screen.ball.getXPos() - 1);
	screen.update();
	cout << "move ball left" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(waitTime)); // pause for program
}

void GameController::moveBallRight()
{
	if (screen.ball.getXPos() != 9 && !screen.isOverlap(screen.ball.getXPos() + 1, screen.ball.getYPos(), screen.dog.getXPos(), screen.dog.getYPos()))
		screen.ball.setXPos(screen.ball.getXPos() + 1);
	screen.update();
	cout << "move ball right" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(waitTime)); // pause for program
}

void GameController::moveBallUp()
{
	if (screen.ball.getYPos() != 9 && !screen.isOverlap(screen.ball.getXPos(), screen.ball.getYPos() + 1, screen.dog.getXPos(), screen.dog.getYPos()))
		screen.ball.setYPos(screen.ball.getYPos() + 1);
	screen.update();
	cout << "move ball up" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(waitTime)); // pause for program
}

void GameController::moveBallDown()
{
	if (screen.ball.getYPos() != 0 && !screen.isOverlap(screen.ball.getXPos(), screen.ball.getYPos() - 1, screen.dog.getXPos(), screen.dog.getYPos()))
		screen.ball.setYPos(screen.ball.getYPos() - 1);
	screen.update();
	cout << "move ball down" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(waitTime)); // pause for program
}

//----------------------------------------------
//functions for moving Ball diagonal directions
//----------------------------------------------

void GameController::moveBallUpDiagRight()
{
	if (screen.ball.getXPos() != 9 && screen.ball.getYPos() != 9 && !screen.isOverlap(screen.ball.getXPos() + 1, screen.ball.getYPos() + 1, screen.dog.getXPos(), screen.dog.getYPos()))
		screen.ball.setXPos(screen.ball.getXPos() + 1);
	screen.ball.setYPos(screen.ball.getYPos() + 1);
	screen.update();
	cout << "move ball up-diagnol right" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(waitTime)); //wait
}

void GameController::moveBallUpDiagLeft()
{
	if (screen.ball.getXPos() != 0 && screen.ball.getYPos() != 9 && !screen.isOverlap(screen.ball.getXPos() - 1, screen.ball.getYPos() + 1, screen.dog.getXPos(), screen.dog.getYPos()))
		screen.ball.setXPos(screen.ball.getXPos() - 1);
	screen.ball.setYPos(screen.ball.getYPos() + 1);
	screen.update();
	cout << "move ball up-diagnol right" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(waitTime)); //wait
}

void GameController::moveBallDownDiagRight()
{
	if (screen.ball.getXPos() != 9 && screen.ball.getYPos() != 0 && !screen.isOverlap(screen.ball.getXPos() + 1, screen.ball.getYPos() - 1, screen.dog.getXPos(), screen.dog.getYPos()))
		screen.ball.setXPos(screen.ball.getXPos() + 1);
	screen.ball.setYPos(screen.ball.getYPos() - 1);
	screen.update();
	cout << "move ball up-diagnol right" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(waitTime)); //wait
}

void GameController::moveBallDownDiagLeft()
{
	if (screen.ball.getXPos() != 0 && screen.ball.getYPos() != 0 && !screen.isOverlap(screen.ball.getXPos() - 1, screen.ball.getYPos() - 1, screen.dog.getXPos(), screen.dog.getYPos()))
		screen.ball.setXPos(screen.ball.getXPos() - 1);
	screen.ball.setYPos(screen.ball.getYPos() - 1);
	screen.update();
	cout << "move ball up-diagnol right" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(waitTime)); //wait
}