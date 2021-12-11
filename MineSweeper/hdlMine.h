#pragma once
#include "framework.h"
#include "minesweeper.h"

class hdlMine
{
private:
	int level = 0;
	minesweeper mineGame;
	int x = 0; //Player가 선택할 좌표
	int y = 0;
	int select = 0; //cin용 변수
	vector<pair<string, float>> rankEasy; //Easy 난이도 기록
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

