#include "hdlMine.h"

int hdlMine::getLevel()
{
	return level;
}

void hdlMine::askLevel()
{
	int level;
	cout << "Please enter the desired level of difficulty." << endl;
	cout << "EASY : 1\tNORMAL : 2\tHARD : 3" << endl;
	cin >> level;
	this->level = level;
}

void hdlMine::startMine()
{
	//mineGame(getLevel());
}
