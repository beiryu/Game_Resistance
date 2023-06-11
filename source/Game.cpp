#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Game.h"
#include "Log.h"

GAME::GAME()
{
	setTime(0);			 // khởi động thời gian
	GAME::readFile();	 // đọc dữ liệu
	setEnv(randomEnv()); // tạo môi trường
}
void GAME::setEnv(string _env)
{
	env = _env;
}
void GAME::setTime(float _time)
{
	time = _time;
}
void GAME::setNameForUser1(string _userName1)
{
	userName1 = _userName1;
}
void GAME::setNameForUser2(string _userName2)
{
	userName2 = _userName2;
}
void GAME::setMode(int _mode)
{
	mode = _mode;
}
string GAME::getEnv()
{
	return env;
}
float GAME::getTime()
{
	return time;
}
string GAME::getNameForUser1()
{
	return userName1;
}
string GAME::getNameForUser2()
{
	return userName2;
}
int GAME::getMode()
{
	return mode;
}
void GAME::readFile()
{
	fstream fileIn("ListHero.txt", ios::in | ios::out); // đọc file vào vector listChampion
	if (!fileIn)
	{
		cout << "\nCANNOT OPEN FILE!";
		exit(0);
	}
	string temp;
	getline(fileIn, temp, '\n');
	if (temp != "") // xem định dạng file có dòng đầu hay không
	{
		fileIn.seekg(0);
	}
	while (!fileIn.eof())
	{
		CHAMPION x;
		fileIn >> x; // dùng nạp chồng toán tử >>
		listChampion.push_back(x);
	}
	fileIn.close();
}
string GAME::randomEnv() // trả về môi trường ngẫu nhiên
{
	string mt;
	srand((int)time(0));
	int r = rand() % 5;
	switch (r)
	{
	case 0:
		mt = "Water";
		break;
	case 1:
		mt = "Wood";
		break;
	case 2:
		mt = "Fire";
		break;
	case 3:
		mt = "Earth";
		break;
	case 4:
		mt = "Metal";
		break;
	default:
		break;
	}
	return mt;
}
vector<CHAMPION> GAME::normalChampionModeSelection() // trả về danh sách tướng đc chọn 1 cách bình thường
{
	vector<CHAMPION> x;
	cout << "\nCHAMPION" << endl; // in danh sách tướng
	for (int i = 0; i < listChampion.size(); ++i)
	{
		cout << "\n		" << i + 1 << ". ";
		listChampion.at(i).print(cout);
	}
	cout << endl;
	int i = 0;
	for (i; i < nChamp; i++) // lượt pick
	{
		try
		{
			int idx;
			cout << "\nPLAYER PICK CHAMPION " << i + 1 << " (INDEX): ";
			cin >> idx;
			if (cin.fail()) // bắt lỗi nhập cin ko phải là 1 số
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				throw 1;
			}
			if (idx < 1 || idx > listChampion.size()) // bắt lỗi nhập số ko có trong danh sách tướng
			{
				throw 1;
			}
			x.push_back(listChampion.at(idx - 1));
		}
		catch (int x)
		{
			if (x) // yêu cầu nhập lại con tướng đó
			{
				--i;
				cout << "		NO CHAMPION";
			}
		}
	}
	return x;
}
vector<CHAMPION> GAME::randomChampionModeSelection()
{
	vector<CHAMPION> x;
	srand((int)time(0));
	int r;
	for (int i = 0; i < nChamp; i++)
	{
		r = rand() % listChampion.size(); // sinh ngẫu nhiên
		for (int j = 0; j < listChampion.size(); ++j)
		{
			if (r == j)
			{
				x.push_back(listChampion.at(j));
			}
		}
	}
	return x;
}
void GAME::selectChampion()
{
	if (mode == 1)
	{
		player1 = normalChampionModeSelection(); // player-1 thì chọn bình thường
		player2 = randomChampionModeSelection(); // sinh ngẫu nhiên
	}
	if (mode == 2)
	{
		cout << "\nPLAYER " << getNameForUser1() << " PICK";
		player1 = normalChampionModeSelection();
		system("cls");
		cout << "\nPLAYER " << getNameForUser2() << " PICK";
		player2 = randomChampionModeSelection();
	}
}
void GAME::envProcess(vector<CHAMPION> &x) // xử lý môi trường ảnh hưởng đến 1 danh sách tướng
{
	for (int i = 0; i < nChamp; ++i)
	{
		if (x.at(i).getGandRType()[0] == env || x.at(i).getGandRType()[2] == env)
		{													   // nếu hệ đó tương khắc với môi trường
			x.at(i).setHealth(x.at(i).getHealth() * 97 / 100); // giảm chỉ số máu
		}
		if (x.at(i).getGandRType()[1] == env || x.at(i).getGandRType()[3] == env)
		{																 // nếu hệ đó tương sinh với môi trường
			x.at(i).setHealth(x.at(i).getHealth() * 105 / 100);			 // tăng máu
			x.at(i).setAttackSpeed(x.at(i).getAttackSpeed() * 90 / 100); // giảm thời gian ra đòn
		}
	}
}
void GAME::collaborationProcess(vector<CHAMPION> &x)
{
	for (int i = 0; i < nChamp; i++)
	{
		for (int j = 0; j < nChamp; j++)
		{
			if (i != j) // lấy từng đôi một có thứ tự
			{
				if (x.at(i).getGandRType()[0] == x.at(j).getType()) // nếu hệ khắc của con i là con j
				{
					x.at(i).setAttackSpeed(x.at(i).getAttackSpeed() * 110 / 100); // con i tự tăng thời gian ra đòn
				}
				if (x.at(i).getGandRType()[1] == x.at(j).getType()) // nếu hệ buff của con i là con j
				{
					x.at(i).setHealth(x.at(i).getHealth() * 115 / 100); // được tăng máu
				}
			}
		}
	}
}
void GAME::confrontationProcess(vector<CHAMPION> &x, vector<CHAMPION> &y) // xử lý đối kháng ảnh hưởng đến chỉ số con tướng
{
	for (int i = 0; i < nChamp; ++i)
	{
		if (x.at(i).getGandRType()[0] == y.at(i).getType()) // nếu con tướng y khắc con tướng x
		{
			x.at(i).setDefense(x.at(i).getDefense() / 2);		// x sẽ bị giảm thủ
			y.at(i).setAttack(y.at(i).getAttack() * 110 / 100); // y sẽ tăng công
		}
	}
}
void GAME::commonProcessing()
{
	envProcess(player1);
	envProcess(player2);
	collaborationProcess(player1);
	collaborationProcess(player2);
	confrontationProcess(player1, player2);
	confrontationProcess(player2, player1);
	if (getMode() == 1) // xử lý thời gian
	{
		time = 1;
	}
	else
	{
		cout << "\nINPUT MATCH TIME (1/2/5 MINUTES): ";
		cin >> time;
	}
}
void GAME::showMatch()
{
	cout << "\n....____________________________  _______";
	cout << "\n.../ __/  _ / ___/ // /_  __/  _/ |/ / ___/";
	cout << "\n../ _/_/ / / (_ / _  / / / _/ //    / (_ / ";
	cout << "\n./_/ /___ /\___/_//_/ /_/ /___/_/|_/\___/ ";
	cout << "\n";
	cout << "\nENVIROMENT: " << env << endl;
	for (int i = 0; i < nChamp; ++i) // in ra danh sách tướng đang đấu
	{
		cout << "\n"
			 << setw(20) << player1.at(i).getName() << setw(20) << "\tvs.\t\t" << player2.at(i).getName();
	}
	cout << "\n\nTIME: ";
	for (int n = 1; n <= (int)time * 60; n++) // chạy đến hết giờ thi đấu
	{
		if (n == 60 || n == 120 || n == 180 || n == 240 || n == 300) // tại các thời điểm này thì reset để hiển thị lại đồng hồ đếm
		{
			system("cls");
			cout << "\n....____________________________  _______";
			cout << "\n.../ __/  _ / ___/ // /_  __/  _/ |/ / ___/";
			cout << "\n../ _/_/ / / (_ / _  / / / _/ //    / (_ / ";
			cout << "\n./_/ /___ /\___/_//_/ /_/ /___/_/|_/\___/ ";
			cout << "\n";
			cout << "\nENVIROMENT: " << env << endl;
			for (int i = 0; i < nChamp; ++i)
			{
				cout << "\n"
					 << setw(20) << player1.at(i).getName() << setw(20) << "\tvs.\t\t" << player2.at(i).getName();
			}
			cout << "\n\nTIME: ";
		}
		int phut = n / 60;
		if ((n - phut * 60) < 10)
		{
			printf("%d", phut);
			printf(":");
			printf("%d\b\b\b", n - phut * 60);
		}
		else if ((n - phut * 60) < 100)
		{
			printf("%d", phut);
			printf(":");
			printf("%d\b\b\b\b", n - phut * 60);
		}
		clock_t endwait;
		endwait = clock() + 0.1 * CLOCKS_PER_SEC; // 0.01 để đánh nhanh hơn tốc độ bình thường 100 lần
		while (clock() < endwait)
		{
		}
	}
	Sleep(1000);
	cout << "\n...._____  _____   ________   __  _______";
	cout << "\n.../ __/ |/ / _ \ / ___/ _ | /  |/  / __/";
	cout << "\n../ _//    / // // (_ / __ |/ /|_/ / _/  ";
	cout << "\n./___/_/|_/____/ \___/_/ |_/_/  /_/___/";
	Sleep(2000);
}
void GAME::fighting(CHAMPION &x, CHAMPION &y) // 2 tướng đánh nhau
{
	float xy = x.timeToKill(y); // thời gian x giết y
	float yx = y.timeToKill(x); // thời gian y giết x
	if (xy == -1 && yx == -1)	// cả 2 đánh đều không vào máu
	{
		return;
	}
	else if (xy == -1) // x đánh ko vào máu y => y thắng
	{
		x.setHealth(0);
	}
	else if (yx == -1) // x thắng
	{
		y.setHealth(0);
	}
	else if (xy > yx) // thời gian y giết x bé hơn nên y thắng => số máu của y còn, số máu x = 0
	{
		int sld = (int)(yx / x.getAttackSpeed()); // số lần đánh của x
		y.setHealth(y.getHealth() - sld * (x.getAttack() - y.getDefense()));
		x.setHealth(0);
	}
	else if (xy < yx) // trường hợp x thắng
	{
		int sld = (int)(xy / y.getAttackSpeed()); // số lần đánh của x
		x.setHealth(x.getHealth() - sld * (y.getAttack() - x.getDefense()));
		y.setHealth(0);
	}
	else // xy = yx
	{
		if (x.getAttackSpeed() == y.getAttackSpeed()) // nếu tốc đánh là như nhau thì cả 2 cùng chết
		{
			x.setHealth(0);
			y.setHealth(0);
		}
		else if (x.getAttackSpeed() > y.getAttackSpeed()) // y ra đòn nhanh hơn => y thắng
		{
			y.setHealth(x.getAttack() - y.getDefense()); // còn 1 lượng máu bằng lần ra đòn cuối của x
			x.setHealth(0);
		}
		else
		{
			x.setHealth(y.getAttack() - x.getDefense());
			y.setHealth(0);
		}
	}
}
void GAME::fighting()
{
	for (int i = 0; i < nChamp; ++i)
	{
		fighting(player1.at(i), player2.at(i)); // cho 2 con tướng đánh nhau từng đôi
	}
}
int GAME::finalResultProcess() // 1 nếu player 1 thắng, 0 nếu hòa, -1 nếu player 1 thua
{
	int count1 = 0; // đếm số tướng team 1 chết
	int count2 = 0; // đếm số tướng team 2 chết
	for (int i = 0; i < nChamp; ++i)
	{
		if (player1.at(i).getHealth() == 0)
		{
			count1++;
		}
		if (player2.at(i).getHealth() == 0)
		{
			count2++;
		}
	}
	if (count1 == count2)
	{
		return 0;
	}
	if (count1 < count2)
	{
		return 1;
	}
	return -1;
}
string GAME::result() // trả về kết quả trận đấu
{
	string str;
	if (finalResultProcess() == 1)
	{
		str = "PLAYER WIN: " + userName1;
	}
	else if (finalResultProcess() == -1)
	{
		str = "PLAYER WIN: " + userName2;
	}
	else
	{
		str = "TIE";
	}
	return str;
}
void GAME::print() // in thông tin sau khi kết thúc trận đấu
{
	cout << "\n...___  __________  ____ ______";
	cout << "\n../ _ \/__ / __/ / / / //_  __/";
	cout << "\n./ , _/_ /_\ \/ /_/ / /__/ /";
	cout << "\n/_/|_/___/___/\____/____/_/";
	cout << "\n";
	cout << "\n"
		 << result();
	cout << "\n\nTEAM " << userName1;
	for (int i = 0; i < nChamp; ++i)
	{
		cout << endl
			 << "\t\t";
		player1.at(i).print(cout);
	}
	cout << "\n\nTEAM " + userName2;
	for (int i = 0; i < nChamp; ++i)
	{
		cout << endl
			 << "\t\t";
		player2.at(i).print(cout);
	}
	cout << "\n\n\n\n\n";
}
void GAME::saveLog() // lưu lại log
{
	LOG log;
	time_t now = time(0);
	tm *ltm = localtime(&now);
	log.setH(ltm->tm_hour);
	log.setM(ltm->tm_min);
	log.setS(ltm->tm_sec);
	log.setDD(ltm->tm_mday);
	log.setMM(1 + ltm->tm_mon);
	log.setYY(1900 + ltm->tm_year);
	log.setNameForUser1(userName1);
	log.setNameForUser2(userName2);
	log.setListChampionForPlayer1(player1);
	log.setListChampionForPlayer2(player2);
	log.setEnv(env);
	log.setResult(result());
	fstream fileOut("Log.txt", ios::in | ios::out | ios::app);
	if (!fileOut)
	{
		cout << "\nCANNOT OPEN FILE!";
		exit(0);
	}
	fileOut << log;
	fileOut.close();
}
void GAME::addChampion()
{
	CHAMPION x;
	cout << "\nINPUT CHAMPION!!!\n";
	x.inputInfo(); // nhập thông tin tướng cần thêm
	fstream fileOut("ListHero.txt", ios::in | ios::out | ios::app);
	if (!fileOut)
	{
		cout << "\nCANNOT OPEN FILE";
		exit(0);
	}
	fileOut << x;
	fileOut.close();
}
void GAME::deleteChampion()
{
	fstream fileOut("ListHero.txt", ios::out | ios::trunc);
	cout << "\nDELETE CHAMPION!!!\n";
	cout << "\nCHAMPION" << endl; // in ra danh sách tướng có trong list
	for (int i = 0; i < listChampion.size(); ++i)
	{
		cout << "\n		" << i + 1 << ". ";
		listChampion.at(i).print(cout);
	}
	int idx;
	bool flag = true; // nếu flag == true thì yêu cầu nhập lại
	while (flag)
	{
		try
		{
			cout << "\nINPUT INDEX: ";
			cin >> idx;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				throw 1;
			}
			if (idx < 1 || idx > listChampion.size())
			{
				throw 1;
			}
			flag = false; // nhập đúng rồi thì thoát
		}
		catch (int x)
		{
			if (x)
			{
				flag == true;
			}
		}
	}
	for (int i = 0; i < listChampion.size(); ++i)
	{
		if (i != idx - 1) // nếu ko phải tướng cần xóa thì lưu lại vào file cũ
		{
			fileOut << listChampion.at(i);
		}
	}
	fileOut.close();
}