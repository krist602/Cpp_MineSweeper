#include "hdlMine.h"

int hdlMine::getLevel() const
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
		cout << "Please select num\t\tFlag Number : " << mineGame.getFlag() << endl;//<<"\t\tget Dig : "<<mineGame.getDig() << endl;
		cin >> x >> y;

		cout << "What are you want? (dig : 1, set flag : 2)" << endl;
		cin >> select;

		if (select == 1)
		{
			if (mineGame.dig(y, x) == false)
			{
				mineGame.printMine();
				cout << "You stepped on a mine." << endl;
				cout << "�� : Correct flag \t �� : Wrong flag" << endl << "�� : Mine \t\t �� : You stepped this mine" << endl;
				break;
			}
			if (mineGame.getDig() == 0)
			{
				mineGame.printMine();
				cout << "Congraturation! You've found all the mines." << endl;
				cout << "�� : Correct flag\t �� : Mine" << endl;
				break;
			}
		}
		else if (select == 2)
		{
			mineGame.flag(y, x);
		}
		else
		{

		}
		/*
		switch (select)
		{
		case 1:
			mineGame.dig(y, x);
			break;
		case 2:
			mineGame.flag(y, x);
			break;
		default:
			break;
		}
		*/
	}
}
