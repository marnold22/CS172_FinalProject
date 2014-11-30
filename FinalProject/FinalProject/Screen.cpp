#include "Screen.h"
#include <iostream>
using namespace std;

void Screen::setUp()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			coord[i][j] = ' ';
		}
	}
	dog.setXPos(4);
	dog.setYPos(5);
	ball.setXPos(6);
	ball.setYPos(5);
}

void Screen::update()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			coord[i][j] = ' ';
		}
	}
	
	coord[dog.getXPos()][dog.getYPos()] = 'D';
	coord[ball.getXPos()][ball.getYPos()] = 'O';
	
	cout << "   ___________________________________________________________" << endl;
	cout << "  |     |     |     |     |     |     |     |     |     |     |" << endl;
	cout << "9 |  " << coord[0][9] << "  |  " << coord[1][9] << "  |  " << coord[2][9] << "  |  " << coord[3][9] << "  |  " << coord[4][9] << "  |  " << coord[5][9] << "  |  " << coord[6][9] << "  |  " << coord[7][9] << "  |  " << coord[8][9] << "  |  " << coord[9][9] << "  |" << endl;
	cout << "  |_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;
	cout << "  |     |     |     |     |     |     |     |     |     |     |" << endl;
	cout << "8 |  " << coord[0][8] << "  |  " << coord[1][8] << "  |  " << coord[2][8] << "  |  " << coord[3][8] << "  |  " << coord[4][8] << "  |  " << coord[5][8] << "  |  " << coord[6][8] << "  |  " << coord[7][8] << "  |  " << coord[8][8] << "  |  " << coord[9][8] << "  |" << endl;
	cout << "  |_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;
	cout << "  |     |     |     |     |     |     |     |     |     |     |" << endl;
	cout << "7 |  " << coord[0][7] << "  |  " << coord[1][7] << "  |  " << coord[2][7] << "  |  " << coord[3][7] << "  |  " << coord[4][7] << "  |  " << coord[5][7] << "  |  " << coord[6][7] << "  |  " << coord[7][7] << "  |  " << coord[8][7] << "  |  " << coord[9][7] << "  |" << endl;
	cout << "  |_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;
	cout << "  |     |     |     |     |     |     |     |     |     |     |" << endl;
	cout << "6 |  " << coord[0][6] << "  |  " << coord[1][6] << "  |  " << coord[2][6] << "  |  " << coord[3][6] << "  |  " << coord[4][6] << "  |  " << coord[5][6] << "  |  " << coord[6][6] << "  |  " << coord[7][6] << "  |  " << coord[8][6] << "  |  " << coord[9][6] << "  |" << endl;
	cout << "  |_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;
	cout << "  |     |     |     |     |     |     |     |     |     |     |" << endl;
	cout << "5 |  " << coord[0][5] << "  |  " << coord[1][5] << "  |  " << coord[2][5] << "  |  " << coord[3][5] << "  |  " << coord[4][5] << "  |  " << coord[5][5] << "  |  " << coord[6][5] << "  |  " << coord[7][5] << "  |  " << coord[8][5] << "  |  " << coord[9][5] << "  |" << endl;
	cout << "  |_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;
	cout << "  |     |     |     |     |     |     |     |     |     |     |" << endl;
	cout << "4 |  " << coord[0][4] << "  |  " << coord[1][4] << "  |  " << coord[2][4] << "  |  " << coord[3][4] << "  |  " << coord[4][4] << "  |  " << coord[5][4] << "  |  " << coord[6][4] << "  |  " << coord[7][4] << "  |  " << coord[8][4] << "  |  " << coord[9][4] << "  |" << endl;
	cout << "  |_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;
	cout << "  |     |     |     |     |     |     |     |     |     |     |" << endl;
	cout << "3 |  " << coord[0][3] << "  |  " << coord[1][3] << "  |  " << coord[2][3] << "  |  " << coord[3][3] << "  |  " << coord[4][3] << "  |  " << coord[5][3] << "  |  " << coord[6][3] << "  |  " << coord[7][3] << "  |  " << coord[8][3] << "  |  " << coord[9][3] << "  |" << endl;
	cout << "  |_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;
	cout << "  |     |     |     |     |     |     |     |     |     |     |" << endl;
	cout << "2 |  " << coord[0][2] << "  |  " << coord[1][2] << "  |  " << coord[2][2] << "  |  " << coord[3][2] << "  |  " << coord[4][2] << "  |  " << coord[5][2] << "  |  " << coord[6][2] << "  |  " << coord[7][2] << "  |  " << coord[8][2] << "  |  " << coord[9][2] << "  |" << endl;
	cout << "  |_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;
	cout << "  |     |     |     |     |     |     |     |     |     |     |" << endl;
	cout << "1 |  " << coord[0][1] << "  |  " << coord[1][1] << "  |  " << coord[2][1] << "  |  " << coord[3][1] << "  |  " << coord[4][1] << "  |  " << coord[5][1] << "  |  " << coord[6][1] << "  |  " << coord[7][1] << "  |  " << coord[8][1] << "  |  " << coord[9][1] << "  |" << endl;
	cout << "  |_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;
	cout << "  |     |     |     |     |     |     |     |     |     |     |" << endl;
	cout << "0 |  " << coord[0][0] << "  |  " << coord[1][0] << "  |  " << coord[2][0] << "  |  " << coord[3][0] << "  |  " << coord[4][0] << "  |  " << coord[5][0] << "  |  " << coord[6][0] << "  |  " << coord[7][0] << "  |  " << coord[8][0] << "  |  " << coord[9][0] << "  |" << endl;
	cout << "  |_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;
	cout << "     0     1     2     3     4     5     6     7     8     9  " << endl;
}

bool Screen::isOverlap(int x1, int y1, int x2, int y2)
{
	if (x1 == x2 && y1 == y2)
		return true;
	return false;
}

bool Screen::isOutside(int x1, int y1)
{
	if (x1 < 0 || x1 > 9 || y1 < 0 || y1 > 9)
		return true;
	return false;
}