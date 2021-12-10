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
	clock_t start, finish;
	float record;
	askLevel();
	mineGame.setLevel(getLevel());
	mineGame.layMine();

	start = clock();
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
				cout << "¢º : Correct flag \t ¢¹ : Wrong flag" << endl << "¡Ù : Mine \t\t ¡Ú : You stepped this mine" << endl;
				break;
			}
			if (mineGame.getDig() == 0)
			{
				finish = clock();
				record = (float)(finish - start) / CLOCKS_PER_SEC;
				mineGame.printMine();
				cout << "Congraturation! You've found all the mines." << endl;
				cout << "¢º : Correct flag\t ¡Ù : Mine" << endl << endl;
				cout << "Your record : " << record << endl;
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
