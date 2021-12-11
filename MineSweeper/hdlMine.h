#pragma once
#include "framework.h"
#include "minesweeper.h"

class hdlMine
{
private:
	int level = 0;
	minesweeper mineGame;
	int x = 0; //Player�� ������ ��ǥ
	int y = 0;
	int select = 0; //cin�� ����
	vector<pair<string, float>> rankEasy; //Easy ���̵� ���
	vector<pair<string, float>> rankNormal;
	vector<pair<string, float>> rankHard;

public:
	hdlMine();
	int getLevel() const;
	bool askLevel();
	void mainMenu();
	void startMine();
	void checkRecord();
	void writeRecord(vector<pair<string, float>> rank, float timer, int level);
};

