#include "Champion.h"
TUONG::TUONG()
{
	ten = "";
	he = "";
	mau = 0;
	cong = 0;
	thu = 0;
	tocDanh = 0;
}
TUONG::TUONG(const TUONG& x)
{
	ten = x.ten;
	he = x.he;
	mau = x.mau;
	cong = x.cong;
	thu = x.thu;
	tocDanh = x.tocDanh;
}
TUONG::TUONG(string _ten, string _he, float _mau, float _cong, float _thu, float _tocDanh)
{
	ten = _ten;
	he = _he;
	mau = _mau;
	cong = _cong;
	thu = _thu;
	tocDanh = _tocDanh;
}
void TUONG::setTen(string _ten)
{
	ten = _ten;
}
void TUONG::setHe(string _he)
{
	he = _he;
}

void TUONG::setMau(float _mau)
{
	mau = _mau;
}
void TUONG::setCong(float _cong)
{
	cong = _cong;
}
void TUONG::setThu(float _thu)
{
	thu = _thu;
}
void TUONG::setTocDanh(float _tocDanh)
{
	tocDanh = _tocDanh;
}
string TUONG::getTen()
{
	return ten;
}
string TUONG::getHe()
{
	return he;
}
float TUONG::getMau()
{
	return mau;
}
float TUONG::getCong()
{
	return cong;
}
float TUONG::getThu()
{
	return thu;
}
float TUONG::getTocDanh()
{
	return tocDanh;
}
string* TUONG::getHeTSTK()
{
	string h = getHe();
	string* tstk = new string[4];
	if (h == "Water") // dựa vào quy luật tương sinh tương khắc để cho ra kết quả
	{
		tstk[0] = "Earth";
		tstk[1] = "Metal";
		tstk[2] = "Fire";
		tstk[3] = "Wood";
	}
	else if (h == "Wood")
	{
		tstk[2] = "Earth";
		tstk[0] = "Metal";
		tstk[3] = "Fire";
		tstk[1] = "Water";
	}
	else if (h == "Fire")
	{
		tstk[3] = "Earth";
		tstk[2] = "Metal";
		tstk[0] = "Water";
		tstk[1] = "Wood";
	}
	else if (h == "Earth")
	{
		tstk[2] = "Water";
		tstk[3] = "Metal";
		tstk[1] = "Fire";
		tstk[0] = "Wood";
	}
	else if (h == "Metal")
	{
		tstk[1] = "Earth";
		tstk[3] = "Water";
		tstk[0] = "Fire";
		tstk[2] = "Wood";
	}
	else
	{
		return tstk;
	}
	return tstk;
}
float TUONG::thoiGianGietDich(TUONG dich)
{
	float time = 0;
	float mauDich = dich.mau;
	if (cong < dich.thu) return -1; // không đánh vào máu nổi	
	while (mauDich > 0) 
	{
		mauDich -= (cong - dich.thu);
		time += tocDanh;
	}
	return time;
}
bool TUONG::chet()
{
	return mau == 0;
}
void TUONG::print(ostream& outDev)
{
	outDev << getTen() << ";" << getHe() << ";" << getMau() << ";" << getCong() << ";" << getThu() << ";" << getTocDanh();
}
istream& operator >> (istream& inDev, TUONG& x)
{
	string temp;
	getline(inDev, temp, ';');
	x.ten = temp;
	getline(inDev, temp, ';');
	x.he = temp;
	getline(inDev, temp, ';');
	x.mau = stof(temp);
	getline(inDev, temp, ';');
	x.cong = stof(temp);
	getline(inDev, temp, ';');
	x.thu = stof(temp);
	getline(inDev, temp, '\n');
	x.tocDanh = stof(temp);
	return inDev;
}
ostream& operator << (ostream& outDev, TUONG& x)
{
	outDev << "\n";
	x.print(outDev);
	return outDev;
}
void TUONG::nhapThongTin()
{
	cout << "INPUT NAME: ";
	getline(cin, ten);
	cout << "INPUT ORIGIN: ";
	getline(cin, he);
	cout << "INPUT HEALTH: ";
	cin >> mau;
	cout << "INPUT ATTACK DAMAGE: ";
	cin >> cong;
	cout << "INPUT ARMOR: ";
	cin >> thu;
	cout << "INPUT ATTACK SPEED: ";
	cin >> tocDanh;
}