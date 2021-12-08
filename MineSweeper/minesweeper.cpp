#include "minesweeper.h"

minesweeper::minesweeper(int level)
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

		board[x][y].first = -1;
		i++;
		if (x == 1)
		{
			if (y == 1)
			{
				for (int j = x; j <= x + 1; j++)
				{
					for (int k = y; y <= y + 1; k++)
					{
						if (board[j][k].first == -1)
							continue;
						board[j][k].first += 1;
					}
				}
			}
			else
			{
				for (int j = x; j <= x + 1; j++)
				{
					for (int k = y - 1; y <= y + 1; k++)
					{
						if (board[j][k].first == -1)
							continue;
						board[j][k].first += 1;
					}
				}
			}
		}
		else if (y == 1)
		{
			for (int j = x - 1; j <= x + 1; j++)
			{
				for (int k = y; y <= y + 1; k++)
				{
					if (board[j][k].first == -1)
						continue;
					board[j][k].first += 1;
				}
			}
		}
		else
		{
			for (int j = x - 1; j <= X + 1; j++)
			{
				for (int k = y - 1; y <= y + 1; k++)
				{
					if (board[j][k].first == -1)
						continue;
					board[j][k].first += 1;
				}
			}
		}
	}
}

void minesweeper::dig(int x, int y)
{
	if (board[x][y].first <= 10)
	{
		if (board[x][y].first == -1)
		{
			cout << "BOOM" << endl;
			return;
		}
		else
		{
			board[x][y].second = true;

			return;
		}
	}
	else if (board[x][y].first >= 100)
	{
		cout << "FLAG" << endl;
	}
	else
	{
		cout << "뭐야 당신 여기 어떻게 들어왔어" << endl;
	}
}

void minesweeper::flag(int x, int y)
{
	if (board[x][y].first <= 10) //깃발이 아니라면
	{
		board[x][y].second = true;
		board[x][y].first += 110; //깃발 심기

		return;
	}
	else //깃발이라면
	{
		board[x][y].second = false;
		board[x][y].first -= 110;

		return;
	}
}

