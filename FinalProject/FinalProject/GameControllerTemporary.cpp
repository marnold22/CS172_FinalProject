

if (words[i + 1] == "ball")
{
	if (words[i + 2] == "up")
	{
		if (screen.ball.getYPos() != 9 && !screen.isOverlap(screen.ball.getXPos(), screen.ball.getYPos() + 1, screen.dog.getXPos(), screen.dog.getYPos()))
			screen.ball.setYPos(screen.ball.getYPos() + 1);
		i += 3;
		screen.update();
		cout << "move ball up" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(waitTime)); // pause for program
	}
	else if (words[i + 2] == "down")
	{
		if (screen.ball.getYpos() != 0 && !screen.isOverlap(screen.ball.getXpos(), screen.ball.getYPos() - 1, screen.dog.getXPos(), screen.dog.getYPos()))
			screen.ball.setYPos(screen.ball.getYPos() - 1);
		i += 3;
		screen.update();
		cout << "move ball down" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(waitTime)); // pause for program
	}
	else if (words[i + 2] == "left")
	{
		if (screen.ball.getXPos() != 0 && !screen.isOverlap(screen.ball.getXPos() - 1, screen.ball.getYPos(), screen.dog.getXPos(), screen.dog.getYPos()))
			screen.ball.setXPos(screen.ball.getXPos() - 1);
		i += 3;
		screen.update();
		cout << "move ball left" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(waitTime)); // pause for program
	}
	else if (words[i + 2] == "right")
	{
		if (screen.ball.getXPos() != 9 && !screen.isOverlap(screen.ball.getXPos() + 1, screen.ball.getYPos(), screen.dog.getXPos(), screen.dog.getYPos()))
			screen.ball.setXPos(screen.ball.getXPos() + 1);
		i += 3;
		screen.update();
		cout << "move ball right" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(waitTime)); // pause for program
	}
	else
	{
		cout << "Couldn't understand command." << endl;
		i++;
	}