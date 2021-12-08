#pragma once
#include "framework.h"
#include "minesweeper.h"

class hdlMine
{
private:
	int level;
	minesweeper mineGame;
public:
	int getLevel();
	void askLevel();
	void startMine();
};

