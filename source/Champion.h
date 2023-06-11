#pragma once
#ifndef __CHAMPION_H__
#define __CHAMPION_H__
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>
#include <sstream>
#include <Windows.h>
using namespace std;
#define nChamp 3 // số lượng tướng trong 1 đội

class CHAMPION
{
private: // lưu những thuộc tính của 1 con tướng
	string name;
	string type;
	float health;
	float attack;
	float defense;
	float attackSpeed;

public:
	CHAMPION();
	CHAMPION(const CHAMPION &);
	CHAMPION(string, string, float, float, float, float);
	void setName(string);
	void setType(string);
	void setHealth(float);
	void setAttack(float);
	void setDefense(float);
	void setAttackSpeed(float);
	string getName();
	string getType();
	float getHealth();
	float getAttack();
	float getDefense();
	float getAttackSpeed();
	string *getGandRType();			 // 1 mảng string trả về các hệ tương sinh tương khắc 0. hệ khắc/1. hệ sinh/2. hệ bị khắc/3. hệ được sinh
	float timeToKill(CHAMPION dich); // thời gian để giết chết 1 con tướng khác
	bool isDie();					 // kiểm tra xem đã chết chưa
	void print(ostream &outDev);	 // hàm in
	friend istream &operator>>(istream &inDev, CHAMPION &x);
	friend ostream &operator<<(ostream &outDev, CHAMPION &x);
	void inputInfo(); // nhập thông tin 1 con tướng
};

#endif // !__CHAMPION_H__