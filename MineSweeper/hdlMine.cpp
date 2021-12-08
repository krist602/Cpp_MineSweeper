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
	askLevel();
	mineGame.setLevel(getLevel());
	mineGame.layMine();

	while (1)
	{
		mineGame.printBoard();
		cout << "Please select num" << endl;
		cin >> x >> y;

		cout << "What are you want? (dig : 1, set flag : 2)" << endl;
		cin >> select;

		switch (select)
		{
		case 1:
			mineGame.dig(x, y);
			break;
		case 2:
			mineGame.flag(x, y);
			break;
		default:
			break;
		}
	}
}
