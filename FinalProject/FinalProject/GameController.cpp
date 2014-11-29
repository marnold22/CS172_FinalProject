#include "GameController.h"
#include <vector>
#include <thread>
#include <chrono>
#include <string>

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

void GameController::runInstructions(const vector<string>& words)
{
	int i(0);
	while (i < words.size())
	{
		if (words[i] == "move")
		{
			if (words[i + 1] == "dog")
			{
				if (words[i + 2] == "up")
				{
					if (screen.dog.getYPos() != 9 && !screen.isOverlap(screen.dog.getXPos(), screen.dog.getYPos() + 1, screen.ball.getXPos(), screen.ball.getYPos()))
						screen.dog.setYPos(screen.dog.getYPos() + 1);
					i += 3;
					screen.update();
					cout << "move dog up" << endl;
					std::this_thread::sleep_for(std::chrono::milliseconds(waitTime)); //wait
				}
				else if (words[i + 2] == "down")
				{
					if (screen.dog.getYPos() != 0 && !screen.isOverlap(screen.dog.getXPos(), screen.dog.getYPos() - 1, screen.ball.getXPos(), screen.ball.getYPos()))
						screen.dog.setYPos(screen.dog.getYPos() - 1);
					i += 3;
					screen.update();
					cout << "move dog down" << endl;
					std::this_thread::sleep_for(std::chrono::milliseconds(waitTime)); //wait
				}
				else if (words[i + 2] == "left")
				{
					if (screen.dog.getXPos() != 0 && !screen.isOverlap(screen.dog.getXPos() - 1, screen.dog.getYPos(), screen.ball.getXPos(), screen.ball.getYPos()))
						screen.dog.setXPos(screen.dog.getXPos() - 1);
					i += 3;
					screen.update();
					cout << "move dog left" << endl;
					std::this_thread::sleep_for(std::chrono::milliseconds(waitTime)); //wait
				}
				else if (words[i + 2] == "right")
				{
					if (screen.dog.getXPos() != 9 && !screen.isOverlap(screen.dog.getXPos() + 1, screen.dog.getYPos(), screen.ball.getXPos(), screen.ball.getYPos()))
						screen.dog.setXPos(screen.dog.getXPos() + 1);
					i += 3;
					screen.update();
					cout << "move dog right" << endl;
					std::this_thread::sleep_for(std::chrono::milliseconds(waitTime)); //wait
				}
				else
				{
					cout << "Could not understand command." << endl;
					i++;
				}
			}
			else
			{
				cout << "Could not understand command." << endl;
				i++;
			}
		}
		else
		{
			cout << "Could not understand command. " << endl;
			i++;
		}
	}
}