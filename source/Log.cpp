#include "Log.h"

vector<LOG> listLog; // danh sách log
void LOG::setH(int _h)
{
	h = _h;
}
int LOG::getH()
{
	return h;
}
void LOG::setM(int _m)
{
	m = _m;
}
int LOG::getM()
{
	return m;
}
void LOG::setS(int _s)
{
	s = _s;
}
int LOG::getS()
{
	return s;
}
void LOG::setDD(int _dd)
{
	dd = _dd;
}
int LOG::getDD()
{
	return dd;
}
void LOG::setMM(int _mm)
{
	mm = _mm;
}
int LOG::getMM()
{
	return mm;
}
void LOG::setYY(int _yy)
{
	yy = _yy;
}
int LOG::getYY()
{
	return yy;
}
void LOG::setNameForUser1(string username)
{
	userName1 = username;
}
string LOG::getNameForUser1()
{
	return userName1;
}
void LOG::setNameForUser2(string username)
{
	userName2 = username;
}
string LOG::getNameForUser2()
{
	return userName2;
}
void LOG::setListChampionForPlayer1(const vector<CHAMPION> x)
{
	for (int i = 0; i < x.size(); ++i)
	{
		CHAMPION t(x.at(i));
		player1.push_back(t);
	}
}
vector<CHAMPION> LOG::getListChampionForPlayer1()
{
	return player1;
}
void LOG::setListChampionForPlayer2(const vector<CHAMPION> x)
{
	for (int i = 0; i < x.size(); ++i)
	{
		CHAMPION t(x.at(i));
		player2.push_back(t);
	}
}
vector<CHAMPION> LOG::getListChampionForPlayer2()
{
	return player2;
}
void LOG::setEnv(string _env)
{
	env = _env;
}
string LOG::getEnv()
{
	return env;
}
void LOG::setResult(string _result)
{
	result = _result;
}
string LOG::getResult()
{
	return result;
}
ostream &operator<<(ostream &outDev, LOG &x) // viết toán tử << cho log theo cấu trúc dễ đọc và đầy đủ
{
	outDev << "\n<" << x.h << ":" << x.m << ":" << x.s << " " << x.dd << "/" << x.mm << "/" << x.yy << ">\n";
	outDev << "<" << x.userName1 << ">\n";
	for (int i = 0; i < nChamp; i++)
	{
		x.player1.at(i).print(outDev);
		outDev << "\n";
	}
	outDev << "<" << x.userName2 << ">\n";
	for (int i = 0; i < nChamp; i++)
	{
		x.player2.at(i).print(outDev);
		outDev << "\n";
	}
	outDev << "<" << x.env << ">";
	outDev << x.result;
	return outDev;
}
istream &operator>>(istream &inDev, LOG &x) // đọc ra lại
{
	char c;
	inDev >> c; // bỏ dòng đầu
	string temp;
	getline(inDev, temp, ':');
	x.h = stoi(temp);
	getline(inDev, temp, ':');
	x.m = stoi(temp);
	getline(inDev, temp, ' ');
	x.s = stoi(temp);
	getline(inDev, temp, '/');
	x.dd = stoi(temp);
	getline(inDev, temp, '/');
	x.mm = stoi(temp);
	getline(inDev, temp, '>');
	x.yy = stoi(temp);
	inDev >> c;
	getline(inDev, temp, '>');
	x.userName1 = temp;
	for (int i = 0; i < nChamp; ++i)
	{
		CHAMPION champion;
		inDev >> champion;
		x.player1.push_back(champion);
	}
	inDev >> c;
	getline(inDev, temp, '>');
	x.userName2 = temp;
	for (int i = 0; i < nChamp; ++i)
	{
		CHAMPION champion;
		inDev >> champion;
		x.player2.push_back(champion);
	}
	inDev >> c;
	getline(inDev, temp, '>');
	x.env = temp;
	getline(inDev, temp, '\n');
	x.result = temp;
	return inDev;
}
void LOG::readLog()
{
	listLog.clear();					 // xóa listLog cũ
	fstream fileLog("Log.txt", ios::in); // đọc log
	if (!fileLog)
	{
		cout << "\nCANNOT OPEN FILE!!!";
		exit(0);
	}
	string temp;
	getline(fileLog, temp, '\n');
	if (temp != "") // xem định dạng file có dòng đầu hay không
	{
		fileLog.seekg(0);
	}
	while (!fileLog.eof())
	{
		LOG x;
		fileLog >> x;
		listLog.push_back(x);
	}
	fileLog.close();
}
int LOG::showLog()
{
	cout << "\nHISTORY MATCH\n";
	cout << "\n		0. EXIT";				 // nếu ko có log thì thoát
	for (int i = 0; i < listLog.size(); ++i) // in ra thời gian mỗi trận trong listLog
	{
		LOG temp = listLog.at(i);
		cout << "\n		" << i + 1 << ". " << temp.h << ":" << temp.m << ":" << temp.s << " " << temp.dd << "/" << temp.mm << "/" << temp.yy;
	}
	int idx;
	bool flag = true;
	while (flag)
	{
		try
		{ // bắt lỗi nhập
			cout << "\nINPUT TIME (INDEX): ";
			cin >> idx;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				throw 1;
			}
			if (idx < 0 || idx > listLog.size())
			{
				throw 1;
			}
			flag = false; // nếu nhập đúng thì dừng vòng lặp
		}
		catch (int x)
		{
			if (x)
			{
				flag = true; // cho nhập lại
			}
		}
	}
	system("cls");
	return idx;
}
void LOG::showLogDetailed()
{
	int idx = showLog();
	if (idx == 0)
	{
		cout << "\n\n\n\n\n";
		return; // chọn thoát thì return
	}
	LOG temp = listLog.at(idx - 1);
	cout << "\nMATCH DETAIL: \n";
	cout << temp.result;
	cout << "\n\nTEAM " << temp.userName1;
	for (int i = 0; i < nChamp; ++i)
	{
		cout << "\n";
		temp.player1.at(i).print(cout);
	}
	cout << "\n\nTEAM " << temp.userName2;

	for (int i = 0; i < nChamp; ++i)
	{
		cout << "\n";
		temp.player2.at(i).print(cout);
	}
	cout << "\n\n\n\n\n";
}