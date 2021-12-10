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
			if (board[j][i].second == true) //VISIBLE�� TRUE���
			{
				if (board[j][i].first == 0)
					cout << "   ";
				else if (board[j][i].first <= 9) //���ڴ� ���
					cout << " " << board[j][i].first << " ";
				else if (board[j][i].first <= 100)
					cout << board[j][i].first << " ";
				else if (board[j][i].first > 100)//����� *�� ǥ��
					cout << "�� ";
			}
			else
			{
				cout << "�� ";
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
			if (board[j][i].first == -1) //���� ��ã�� ���ڴ�
			{
				cout << "�� ";
				continue;
			}
			if (board[j][i].first < -5) //��Ƽ� ���� ���ڴ�
			{
				cout << "�� ";
				continue;
			}

			if (board[j][i].second == true) //VISIBLE�� TRUE���
			{
				if (board[j][i].first == 0) // 0�� ��������.
				{
					cout << "   ";
					continue;
				}
				else if (board[j][i].first <= 9) //���ڴ� ���
				{
					cout << " " << board[j][i].first << " ";
					continue;
				}
				else if (board[j][i].first <= 100)
				{
					cout << board[j][i].first << " ";				
					continue;
				}
				else if (board[j][i].first > 100)//����� *�� ǥ��
				{
					if (board[j][i].first - 110 == -1)
						cout << "�� ";
					else if (board[j][i].first - 110 >= 0)
						cout << "�� ";
				}
			}
			else
			{
				cout << "�� ";
			}
		}
		cout << endl;
	}
}

void minesweeper::layMine() //�������� ���� ��ġ ����
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
		//cout << i << "��° ���� : " << y << " " << x << endl;
		
		//���ڸ� ���� ���Ŀ� ���� ������ ���ڵ��� +=1�� ���ش�.
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
		if (board[x][y].first == -1) //-1�̶��
		{
			cout << "BOOM" << endl; //���ڰ� ������.
			board[x][y].first = -10;
			return false;
		}
		else if (board[x][y].first == 0) //������ ���ڰ� ���ٸ�
		{
			for (int j = x - 1; j <= x + 1; j++)
				for (int k = y - 1; k <= y + 1; k++)
				{
					if(board[x][y].second == false)
						numDig -= 1;
					board[x][y].second = true; // ������ 0���� �����
					dig(k, j); //������ �ٽ� Ž��
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
		cout << "���� ��� ���� ��� ���Ծ�" << endl;
		return true;
	}
	return true;
}

void minesweeper::flag(int y, int x)
{
	if (board[x][y].first <= 10) //����� �ƴ϶��
	{
		if (board[x][y].second == true) //�̹� ������ ���ڶ��
		{
			cout << "Wrong Number." << endl;
			return;
		}

		board[x][y].second = true;
		board[x][y].first += 110; //��� �ɱ�
		numFlag += 1;

		return;
	}
	else //����̶��
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

