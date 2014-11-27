#include "GameController.h"
#include <vector>
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
				cout << "Moved dog. " << endl;
				i += 3;
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