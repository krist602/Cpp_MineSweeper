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
	case Lev::NORMAL:
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

	numFlag = 0;
	numDig = X * Y - numMine;

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
			if (board[j][i].second == true) //VISIBLE이 TRUE라면
			{
				if (board[j][i].first == 0)
					cout << "   ";
				else if (board[j][i].first <= 9) //숫자는 출력
					cout << " " << board[j][i].first << " ";
				else if (board[j][i].first <= 100)
					cout << board[j][i].first << " ";
				else if (board[j][i].first > 100)//깃발은 *로 표시
					cout << "▶ ";
			}
			else
			{
				cout << "□ ";
			}
		}
		cout << endl;
	}
}

void minesweeper::printMine()
{
	for (int i = 0; i <= X; i++)
	{
		for (int j = 0; j <= Y; j++)
		{
			if (board[j][i].first == -1) //아직 못찾은 지뢰는
			{
				cout << "☆ ";
				continue;
			}
			if (board[j][i].first < -5) //밟아서 터진 지뢰는
			{
				cout << "★ ";
				continue;
			}

			if (board[j][i].second == true) //VISIBLE이 TRUE라면
			{
				if (board[j][i].first == 0) // 0은 공란으로.
				{
					cout << "   ";
					continue;
				}
				else if (board[j][i].first <= 9) //숫자는 출력
				{
					cout << " " << board[j][i].first << " ";
					continue;
				}
				else if (board[j][i].first <= 100)
				{
					cout << board[j][i].first << " ";				
					continue;
				}
				else if (board[j][i].first > 100)//깃발은 *로 표시
				{
					if (board[j][i].first - 110 == -1)
						cout << "▶ ";
					else if (board[j][i].first - 110 >= 0)
						cout << "▷ ";
				}
			}
			else
			{
				cout << "□ ";
			}
		}
		cout << endl;
	}
}

void minesweeper::layMine() //랜덤으로 지뢰 위치 선정
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
		//cout << i << "번째 지뢰 : " << y << " " << x << endl;
		
		//지뢰를 심은 이후에 지뢰 주위에 숫자들을 +=1을 해준다.
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
	if (x <= 0 || x > X || y > Y || y <= 0) 
		return true;
	if (board[x][y].second == true)
		return true;

	if (board[x][y].first <= 10)
	{
		if (board[x][y].first == -1) //-1이라면
		{
			cout << "BOOM" << endl; //지뢰가 터진다.
			board[x][y].first = -10;
			return false;
		}
		else if (board[x][y].first == 0) //주위에 지뢰가 없다면
		{
			for (int j = x - 1; j <= x + 1; j++)
				for (int k = y - 1; k <= y + 1; k++)
				{
					if(board[x][y].second == false)
						numDig -= 1;
					board[x][y].second = true; // 본인을 0으로 만들고
					dig(k, j); //주위에 다시 탐색
				}
		}
		else //
		{
			board[x][y].second = true;
			numDig -= 1;
			return true;
		}
	}
	else if (board[x][y].first >= 100)
	{
		return true;
	}
	else
	{
		cout << "뭐야 당신 여기 어떻게 들어왔어" << endl;
		return true;
	}
	return true;
}

void minesweeper::flag(int y, int x)
{
	if (board[x][y].first <= 10) //깃발이 아니라면
	{
		if (board[x][y].second == true) //이미 밝혀진 숫자라면
		{
			cout << "Wrong Number." << endl;
			return;
		}

		board[x][y].second = true;
		board[x][y].first += 110; //깃발 심기
		numFlag += 1;

		return;
	}
	else //깃발이라면
	{
		board[x][y].second = false;
		board[x][y].first -= 110;
		numFlag -= 1;

		return;
	}
}

int minesweeper::getDig() const
{
	return numDig;
}

int minesweeper::getFlag() const
{
	return numFlag;
}

