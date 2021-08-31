#pragma once
#ifndef __TUONG_H__
#define __TUONG_H__
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>
#include <sstream>
#include <Windows.h>
using namespace std;
#define nChamp 3 // số lượng tướng trong 1 đội
class TUONG
{
private: // lưu những thuộc tính của 1 con tướng
	string ten;
	string he;
	float mau;
	float cong;
	float thu;
	float tocDanh;
public:
	TUONG();
	TUONG(const TUONG&);
	TUONG(string, string, float, float, float, float);
	void setTen(string);
	void setHe(string);
	void setMau(float);
	void setCong(float);
	void setThu(float);
	void setTocDanh(float);
	string getTen();
	string getHe();
	float getMau();
	float getCong();
	float getThu();
	float getTocDanh();
	string* getHeTSTK(); // 1 mảng string trả về các hệ tương sinh tương khắc 0. hệ khắc/1. hệ sinh/2. hệ bị khắc/3. hệ được sinh
	float thoiGianGietDich(TUONG dich); // thời gian để giết chết 1 con tướng khác
	bool chet(); // kiểm tra xem đã chết chưa 
	void print(ostream& outDev); // hàm in
	friend istream& operator >> (istream& inDev, TUONG& x);
	friend ostream& operator << (ostream& outDev, TUONG& x);
	void nhapThongTin(); // nhập thông tin 1 con tướng
};
#endif // !__TUONG_H__