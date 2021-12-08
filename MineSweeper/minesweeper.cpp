#include "minesweeper.h"

void minesweeper::setLevel(int level)
{
	switch (level)
	{
	case Lev::EASY:
		X = 9;
		Y = 9;
		numMine = 10;
		break;
	case Lev::MIDIUM:
		X = 16;
		Y = 16;
		numMine = 40;
		break;
	case Lev::HARD:
		X = 30;
		Y = 16;
		numMine = 99;
		break;
	default:
		break;
	}
	for (int i = 1; i <= X; i++)
		for (int j = 1; j <= Y; j++)
			board[i][j] = { 0, false };

	for (int i = 1; i <= X; i++)
		board[i][0] = { i, true };
	for (int i = 1; i <= Y; i++)
		board[0][i] = { i, true };
}

void minesweeper::printBoard()
{
	for (int i = 0; i <= X; i++)
	{
		for (int j = 0; j <= Y; j++)
		{
			//cout << board[i][j].first << " ";
			if (board[i][j].second == true)
			{
				if (board[i][j].first <= 100)
					cout << board[i][j].first << " ";
				else
					cout << "* ";
			}
			else
			{
				cout << ". ";
			}
		}
		cout << endl;
	}
}

void minesweeper::layMine()
{
	int x = 0, y = 0;
	srand((unsigned int)time(NULL));
	for (int i = 1; i <= numMine; i)
	{
		x = rand() % X + 1;
		y = rand() % Y + 1;
		if (board[x][y].first == -1)
			continue;
		else
			board[x][y].first = -1;
		
		if (x == 1)
		{
			if (y == 1)
			{
				for (int j = x; j <= x + 1; j++)
				{
					for (int k = y; k <= y + 1; k++)
					{
						if (board[j][k].first == -1)
							continue;
						else
							board[j][k].first += 1;
					}
				}
			}
			else
			{
				for (int j = x; j <= x + 1; j++)
				{
					for (int k = y - 1; k <= y + 1; k++)
					{
						if (board[j][k].first == -1)
							continue;
						else
							board[j][k].first += 1;
					}
				}
			}
		}
		else if (y == 1)
		{
			for (int j = x - 1; j <= x + 1; j++)
			{
				for (int k = y; k <= y + 1; k++)
				{
					if (board[j][k].first == -1)
						continue;
					else
						board[j][k].first += 1;
				}
			}
		}
		else
		{
			for (int j = x - 1; j <= x + 1; j++)
			{
				for (int k = y - 1; k <= y + 1; k++)
				{
					if (board[j][k].first == -1)
						continue;
					else
						board[j][k].first += 1;
				}
			}
		}
		i++;
	}
}

bool minesweeper::dig(int x, int y)
{
	if (board[x][y].first <= 10)
	{
		if (board[x][y].first == -1)
		{
			cout << "BOOM" << endl;
			return false;
		}
		else
		{
			board[x][y].second = true;

			return true;
		}
	}
	else if (board[x][y].first >= 100)
	{
		cout << "FLAG" << endl;
	}
	else
	{
		cout << "���� ��� ���� ��� ���Ծ�" << endl;
	}
}

void minesweeper::flag(int x, int y)
{
	if (board[x][y].first <= 10) //����� �ƴ϶��
	{
		board[x][y].second = true;
		board[x][y].first += 110; //��� �ɱ�

		return;
	}
	else //����̶��
	{
		board[x][y].second = false;
		board[x][y].first -= 110;

		return;
	}
}
