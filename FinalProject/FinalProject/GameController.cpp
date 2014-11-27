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
					cout << "Moved dog up!" << endl;
					i += 3;
					std::this_thread::sleep_for(std::chrono::seconds(2)); //wait 2 seconds
				}
				else if (words[i + 2] == "down")
				{
					cout << "Moved dog down!" << endl;
					i += 3;
					std::this_thread::sleep_for(std::chrono::seconds(2)); //wait 2 seconds
				}
				else if (words[i + 2] == "left")
				{
					cout << "Moved dog left!" << endl;
					i += 3;
					std::this_thread::sleep_for(std::chrono::seconds(2)); //wait 2 seconds
				}
				else if (words[i + 2] == "right")
				{
					cout << "Moved dog right!" << endl;
					i += 3;
					std::this_thread::sleep_for(std::chrono::seconds(2)); //wait 2 seconds
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