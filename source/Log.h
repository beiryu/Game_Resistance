#ifndef __LOG_H__
#define __LOG_H__
#include "Champion.h"
#include "Game.h"
#include <ctime>

class LOG
{
private:
	int h;	// giờ
	int m;	// phút
	int s;	// giây
	int dd; // ngày
	int mm; // tháng
	int yy; // năm
	string userName1;
	string userName2;
	vector<CHAMPION> player1;
	vector<CHAMPION> player2;
	string env;
	string result;

public:
	void setH(int);
	void setM(int);
	void setS(int);
	void setDD(int);
	void setMM(int);
	void setYY(int);
	void setNameForUser1(string);
	void setNameForUser2(string);
	void setListChampionForPlayer1(const vector<CHAMPION>);
	void setListChampionForPlayer2(const vector<CHAMPION>);
	void setEnv(string);
	void setResult(string);
	int getH();
	int getM();
	int getS();
	int getDD();
	int getMM();
	int getYY();
	string getNameForUser1();
	string getNameForUser2();
	vector<CHAMPION> getListChampionForPlayer1();
	vector<CHAMPION> getListChampionForPlayer2();
	string getEnv();
	string getResult();
	friend ostream &operator<<(ostream &outDev, LOG &);
	friend istream &operator>>(istream &inDev, LOG &);
	void readLog();			// đọc file log ra listLog
	int showLog();			// trả về index thời gian trận đấu
	void showLogDetailed(); // xem chi tiết trận đấu
};

#endif // !__LOG_H__