#ifndef __LOG_H__
#define __LOG_H__
#include "Champion.h"
#include "Game.h"
#include <ctime>

class LOG
{
private:
	int h; // giờ
	int m; // phút
	int s;	// giây
	int dd;	// ngày
	int mm;	// tháng
	int yy;	// năm
	string username_1;
	string username_2;
	vector<TUONG>player_1;
	vector<TUONG>player_2;
	string moiTruong;
	string ketQua;
public:
	void setH(int);
	void setM(int);
	void setS(int);
	void setDD(int);
	void setMM(int);
	void setYY(int);
	void setUsername_1(string);
	void setUsername_2(string);
	void setListTuongPlayer_1(const vector<TUONG>);
	void setListTuongPlayer_2(const vector<TUONG>);
	void setMoiTruong(string);
	void setKetQua(string);
	int getH();
	int getM();
	int getS();
	int getDD();
	int getMM();
	int getYY();
	string getUsername_1();
	string getUsername_2();
	vector<TUONG> getListTuongPlayer_1();
	vector<TUONG> getListTuongPlayer_2();
	string getMoiTruong();
	string getKetQua();
	friend ostream& operator << (ostream& outDev, LOG&);
	friend istream& operator >> (istream& inDev, LOG&);
	void docLog();			// đọc file log ra listLog
	int xemLog();			// trả về index thời gian trận đấu
	void xemLogChiTiet();	// xem chi tiết trận đấu
};
#endif // !__LOG_H__