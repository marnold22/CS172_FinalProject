

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
	