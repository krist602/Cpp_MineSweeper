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
		X = 16;
		Y = 30;
		numMine = 99;
		break;
	default:
		break;
	}
	for (int i = 1; i <= X; i++)
		for (int j = 1; j <= Y; j++)
			board[j][i] = { 0, false };

	for (int i = 1; i <= X; i++)
		board[0][i] = { i, true };
	for (int i = 1; i <= Y; i++)
		board[i][0] = { i, true };
}

void minesweeper::printBoard()
{
	for (int i = 0; i <= X; i++)
	{
		for (int j = 0; j <= Y; j++)
		{
			//cout << board[j][i].first << " ";
			if (board[j][i].second == true)
			{
				if (board[j][i].first <= 100)
					cout << board[j][i].first << " ";
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
		if (board[y][x].first == -1)
			continue;
		else
			board[y][x].first = -1;
		cout << i << "번째 지뢰 : " << x << " " << y << endl;
		if (x == 1)
		{
			if (y == 1)
			{
				for (int j = x; j <= x + 1; j++)
				{
					for (int k = y; k <= y + 1; k++)
					{
						if (board[k][j].first == -1)
							continue;
						else
							board[k][j].first += 1;
					}
				}
			}
			else
			{
				for (int j = x; j <= x + 1; j++)
				{
					for (int k = y - 1; k <= y + 1; k++)
					{
						if (board[k][j].first == -1)
							continue;
						else
							board[k][j].first += 1;
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
					if (board[k][j].first == -1)
						continue;
					else
						board[k][j].first += 1;
				}
			}
		}
		else
		{
			for (int j = x - 1; j <= x + 1; j++)
			{
				for (int k = y - 1; k <= y + 1; k++)
				{
					if (board[k][j].first == -1)
						continue;
					else
						board[k][j].first += 1;
				}
			}
		}
		i++;
	}
}

bool minesweeper::dig(int y, int x)
{
	if (x <= 0 || x>X || y > Y || y <= 0) 
		return false;
	if (board[x][y].second == true)
		return false;

	if (board[x][y].first <= 10)
	{
		if (board[x][y].first == -1)
		{
			cout << "BOOM" << endl;
			return false;
		}
		else if (board[x][y].first == 0)
		{
			for (int j = x - 1; j <= x + 1; j++)
				for (int k = y - 1; k <= y + 1; k++)
				{
					board[x][y].second = true;
					dig(k, j);
				}
			/*if (x == 1)
			{
				if (y == 1)
					for (int j = x; j <= x + 1; j++)
						for (int k = y; k <= y + 1; k++)
							dig(k, j);
				else
					for (int j = x; j <= x + 1; j++)
						for (int k = y - 1; k <= y + 1; k++)
							dig(k, j);
			}
			else if (y == 1)
			{
				for (int j = x - 1; j <= x + 1; j++)
					for (int k = y; k <= y + 1; k++)
						dig(k, j);
			}
			else
			{
				for (int j = x - 1; j <= x + 1; j++)
					for (int k = y - 1; k <= y + 1; k++)
						dig(k, j);
			}*/
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
		return false;
	}
	else
	{
		cout << "뭐야 당신 여기 어떻게 들어왔어" << endl;
	}
}

void minesweeper::flag(int y, int x)
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

