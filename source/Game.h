#pragma once
#ifndef __GAME_H__
#define __GAME_H__
#include "Champion.h"
#include <iomanip>
class GAME
{
private:
	vector<CHAMPION> listChampion; // danh sách tướng đọc từ file ListHero.txt
	vector<CHAMPION> player1;	   // danh sách tướng 2 người chơi
	vector<CHAMPION> player2;
	string userName1; // tên 2 người chơi
	string userName2;
	string env; // môi trường
	float time; // thời gian của hiệp đấu
	int mode;	// 1. là chế độ 1 người chơi, 2. là chế độ 2 người chơi

public:
	GAME();
	void setEnv(string);
	void setTime(float);
	void setNameForUser1(string _userName1);
	void setNameForUser2(string _userName2);
	void setMode(int);
	string getEnv();
	float getTime();
	string getNameForUser1();
	string getNameForUser2();
	int getMode();
	void readFile();												   // đọc file ListHero.txt vào bộ nhớ game
	string randomEnv();												   // tạo môi trường
	vector<CHAMPION> normalChampionModeSelection();					   // người chơi chọn
	vector<CHAMPION> randomChampionModeSelection();					   // máy chọn
	void selectChampion();											   // chọn tướng trong từng chế độ chơi
	void envProcess(vector<CHAMPION> &);							   // ảnh hưởng của môi trường
	void collaborationProcess(vector<CHAMPION> &);					   // ảnh hưởng của các thành viên cùng team
	void confrontationProcess(vector<CHAMPION> &, vector<CHAMPION> &); // ảnh hưởng của địch
	void commonProcessing();										   // xử lý chung cho 1 game đấu
	void showMatch();
	void fighting(CHAMPION &, CHAMPION &);
	void fighting();		  // cho các tướng đánh nhau
	int finalResultProcess(); // 1. nếu player1 win, 0 nếu hòa, -1 nếu player1 thua
	string result();		  // toString kết quả trận đấu
	void print();			  // in ra kết quả
	void saveLog();
	void addChampion();	   // thêm vào file ListHero.txt
	void deleteChampion(); // xóa khỏi listhero
};

#endif // !__GAME_H__