#pragma once
#include "framework.h"
#include "minesweeper.h"

class hdlMine
{
private:
	int level = 0;
	minesweeper mineGame;
	int x = 0;
	int y = 0;
	int select = 0;
public:
	int getLevel() const;
	void askLevel();
	void startMine();
};

