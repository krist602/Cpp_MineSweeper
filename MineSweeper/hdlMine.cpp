#include "hdlMine.h"

bool cmp(pair<string, float> p1, pair<string, float> p2)
{
	return p1.second < p2.second;
}

hdlMine::hdlMine()
{
	ofstream writeFile;
	ifstream readFile;
	string name = "";
	string time = "";
	int count = 1;
	readFile.open("difEasy.txt");
	//difEasy의 내용을 vector<> rankEasy에 넣기
	if (readFile.is_open())
	{
		count = 1;
		while (!readFile.eof())
		{
			if (count > 6)
				break;
			if (count % 2 == 1)
			{
				getline(readFile, name);
			}
			else
			{
				getline(readFile, time);
				rankEasy.push_back(make_pair(name, stof(time)));
			}
			count++;
		}
	}
	else
	{
		writeFile.open("difEasy.txt");
		writeFile.close();
	}
	readFile.close();

	readFile.open("difNormal.txt");
	//difNormal의 내용을 vector<> rankNormal에 넣기
	if (readFile.is_open())
	{
		count = 1;
		while (!readFile.eof())
		{
			if (count > 6)
				break;
			if (count % 2 == 1)
			{
				getline(readFile, name);
			}
			else
			{
				getline(readFile, time);
				rankNormal.push_back(make_pair(name, stof(time)));
			}
			count++;
		}
	}
	else
	{
		writeFile.open("difNormal.txt");
		writeFile.close();
	}
	readFile.close();

	readFile.open("difHard.txt");
	//difHard의 내용을 vector<> rankHard에 넣기
	if (readFile.is_open())
	{
		count = 1;
		while (!readFile.eof())
		{
			if (count > 6)
				break;
			if (count % 2 == 1)
			{
				getline(readFile, name);
			}
			else
			{
				getline(readFile, time);
				rankEasy.push_back(make_pair(name, stof(time)));
			}
			count++;
		}
	}
	else
	{
		writeFile.open("difHard.txt");
		writeFile.close();
	}
	readFile.close();
}

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

void hdlMine::mainMenu()
{
	while (1)
	{
		cout << "Select Menu" << endl << "1. Game Start" << endl << "2. Record" << endl << "3. exit" << endl;
		cin >> select;
		if (select == 1)
			startMine();
		else if (select == 2)
			checkRecord();
		else if (select == 3)
			break;
		else
			cout << "Wrong Number" << endl;

	}
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
				cout << "▶ : Correct flag \t ▷ : Wrong flag" << endl << "☆ : Mine \t\t ★ : You stepped this mine" << endl;
				break;
			}
			if (mineGame.getDig() == 0)
			{
				finish = clock();
				record = (float)(finish - start) / CLOCKS_PER_SEC;
				mineGame.printMine();
				cout << "Congraturation! You've found all the mines." << endl;
				cout << "▶ : Correct flag\t ☆ : Mine" << endl << endl;
				cout << "Your record : " << record << endl;
				switch (level)
				{
				case Lev::EASY:
					if (rankEasy.empty())
						writeRecord(rankEasy, record, level);
					else if (rankEasy.back().second > record)
						writeRecord(rankEasy, record, level);
					break;
				case Lev::NORMAL:
					if (rankNormal.empty())
						writeRecord(rankNormal, record, level);
					else if (rankNormal.back().second > record)
						writeRecord(rankNormal, record, level);
					break;
				case Lev::HARD:
					if (rankHard.empty())
						writeRecord(rankHard, record, level);
					else if (rankHard.back().second > record)
						writeRecord(rankHard, record, level);
					break;
				default:
					break;
				}
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

void hdlMine::checkRecord()
{
	ifstream readFile;
	string str = "";
	bool flag = false;
	cout << "Please enter the desired level of difficulty." << endl;
	cout << "EASY : 1\tNORMAL : 2\tHARD : 3" << endl;
	cin >> select;
	switch (select)
	{
	case Lev::EASY:
		readFile.open("difEasy.txt");
		if (readFile.is_open())
		{
			while (!readFile.eof())
			{
				getline(readFile, str);
				if (flag == false)
					cout << str << "\t\t";
				else
					cout << str << endl;
				flag = !flag;
			}
		}
		readFile.close();
		break;
	case Lev::NORMAL:
		readFile.open("difNormal.txt");
		if (readFile.is_open())
		{
			while (!readFile.eof())
			{
				getline(readFile, str);
				if (flag == false)
					cout << str << "\t\t";
				else
					cout << str << endl;
				flag = !flag;
			}
		}
		readFile.close();
		break;
	case Lev::HARD:
		break;
	default:
		break;
	}
}

void hdlMine::writeRecord(vector<pair<string, float>> rank, float timer, int level)
{
	ofstream writeFile;
	string name = "";
	cout << "Please enter a nickname." << endl;
	cin >> name;
	rank.push_back(make_pair(name, timer));
	sort(rank.begin(), rank.end(), cmp);
	if (rank.size() > 3) //기록이 3명보다 많을 경우 3명까지의 기록만 남긴다.
		rank.erase(rank.begin() + 3, rank.end());
	switch (level)
	{
	case Lev::EASY:
		writeFile.open("difEasy.txt");
		break;
	case Lev::NORMAL:
		writeFile.open("difNormal.txt");
		break;
	case Lev::HARD:
		writeFile.open("difHard.txt");
		break;
	default:
		break;
	}
	for (int i = 0; i < rank.size(); i++)
	{
		string tmp1 = rank[i].first;
		tmp1 += "\n";
		tmp1 += to_string(rank[i].second);
		if (i != rank.size() - 1)
			tmp1 += "\n";

		writeFile.write(tmp1.c_str(), tmp1.size());
	}
	writeFile.close();

	return;
}

