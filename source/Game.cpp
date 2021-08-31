#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Game.h"
#include "Log.h"
GAME::GAME()
{
	setThoiGian(0);                  // khởi động thời gian
	GAME::docFile();					// đọc dữ liệu
	setMoiTruong(randomMoiTruong());	// tạo môi trường
}
void GAME::setMoiTruong(string _moiTruong)
{
	moiTruong = _moiTruong;
}
void GAME::setThoiGian(float _thoiGian)
{
	thoiGian = _thoiGian;
}
void GAME::setUsername1(string _us1)
{
	username_1 = _us1;
}
void GAME::setUsername2(string _us2)
{
	username_2 = _us2;
}
void GAME::setCheDo(int _cheDo)
{
	cheDo = _cheDo;
}
string GAME::getMoiTruong()
{
	return moiTruong;
}
float GAME::getThoiGian()
{
	return thoiGian;
}
string GAME::getUsername1()
{
	return username_1;
}
string GAME::getUsername2()
{
	return username_2;
}
int GAME::getCheDo()
{
	return cheDo;
}
void GAME::docFile()
{
	fstream fileIn("ListHero.txt", ios::in | ios::out); // đọc file vào vector listTuong
	if (!fileIn)
	{
		cout << "\nCANNOT OPEN FILE!";
		exit(0);
	}
	string temp;
	getline(fileIn, temp, '\n');
	if (temp != "")  // xem định dạng file có dòng đầu hay không
	{
		fileIn.seekg(0);
	}
	while (!fileIn.eof())
	{
		TUONG x;
		fileIn >> x;  // dùng nạp chồng toán tử >> 
		listTuong.push_back(x);
	}
	fileIn.close();
}
string GAME::randomMoiTruong() // trả về môi trường ngẫu nhiên
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
vector<TUONG> GAME::chonTuongBinhThuong() // trả về danh sách tướng đc chọn 1 cách bình thường
{
	vector<TUONG> x;
	cout << "\nCHAMPION" << endl;   // in danh sách tướng
	for (int i = 0; i < listTuong.size(); ++i)
	{
		cout << "\n		" << i + 1 << ". ";
		listTuong.at(i).print(cout);
	}
	cout << endl;
	int i = 0;
	for (i; i < nChamp; i++)          // lượt pick 
	{
		try 
		{
			int idx;
			cout << "\nPLAYER PICK CHAMPION " << i + 1 << " (INDEX): ";
			cin >> idx;
			if (cin.fail())						// bắt lỗi nhập cin ko phải là 1 số
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				throw 1;
			}
			if (idx < 1 || idx > listTuong.size()) // bắt lỗi nhập số ko có trong danh sách tướng
			{
				throw 1;
			}
			x.push_back(listTuong.at(idx - 1));
		}
		catch (int x)		
		{	
			if (x)							// yêu cầu nhập lại con tướng đó
			{
				--i;
				cout << "		NO CHAMPION";	
			}
		}
	}
	return x;
}
vector<TUONG> GAME::chonTuongNgauNhien()
{
	vector<TUONG> x;
	srand((int)time(0));
	int r;
	for (int i = 0; i < nChamp; i++)
	{
		r = rand() % listTuong.size(); // sinh ngẫu nhiên
		for (int j = 0; j < listTuong.size(); ++j)
		{
			if (r == j)
			{
				x.push_back(listTuong.at(j));
			}
		}
	}
	return x;
}
void GAME::chonTuong()
{
	if (cheDo == 1)
	{
		player_1 = chonTuongBinhThuong(); // player-1 thì chọn bình thường
		player_2 = chonTuongNgauNhien(); // sinh ngẫu nhiên
	}
	if (cheDo == 2)
	{
		cout << "\nPLAYER " << getUsername1() << " PICK";
		player_1 = chonTuongBinhThuong();
		system("cls");
		cout << "\nPLAYER " << getUsername2() << " PICK";
		player_2 = chonTuongBinhThuong();
	}
}
void GAME::xuLyMoiTruong(vector<TUONG>& x) // xử lý môi trường ảnh hưởng đến 1 danh sách tướng
{
	for (int i = 0; i < nChamp; ++i)
	{
		if (x.at(i).getHeTSTK()[0] == moiTruong || x.at(i).getHeTSTK()[2] == moiTruong) 
		{ // nếu hệ đó tương khắc với môi trường
			x.at(i).setMau(x.at(i).getMau() * 97 / 100);  // giảm chỉ số máu
		}
		if (x.at(i).getHeTSTK()[1] == moiTruong || x.at(i).getHeTSTK()[3] == moiTruong)  
		{ // nếu hệ đó tương sinh với môi trường
			x.at(i).setMau(x.at(i).getMau() * 105 / 100);  // tăng máu
			x.at(i).setTocDanh(x.at(i).getTocDanh() * 90 / 100); //giảm thời gian ra đòn
		}
	}
}
void GAME::xuLyCungDoi(vector<TUONG>& x)
{
	for (int i = 0; i < nChamp; i++)
	{
		for (int j = 0; j < nChamp; j++)
		{
			if (i != j) // lấy từng đôi một có thứ tự
			{
				if (x.at(i).getHeTSTK()[0] == x.at(j).getHe()) // nếu hệ khắc của con i là con j
				{
					x.at(i).setTocDanh(x.at(i).getTocDanh() * 110 / 100); // con i tự tăng thời gian ra đòn
				}
				if (x.at(i).getHeTSTK()[1] == x.at(j).getHe()) // nếu hệ buff của con i là con j
				{
					x.at(i).setMau(x.at(i).getMau() * 115 / 100); // được tăng máu
				}
			}
		}
	}
}
void GAME::xuLyDoiKhang(vector<TUONG>& x, vector<TUONG>& y) // xử lý đối kháng ảnh hưởng đến chỉ số con tướng
{
	for (int i = 0; i < nChamp; ++i)
	{
		if (x.at(i).getHeTSTK()[0] == y.at(i).getHe()) // nếu con tướng y khắc con tướng x
		{
			x.at(i).setThu(x.at(i).getThu() / 2); // x sẽ bị giảm thủ
			y.at(i).setCong(y.at(i).getCong() * 110 / 100); // y sẽ tăng công
		}
	}
}
void GAME::xuLyChung()
{
	xuLyMoiTruong(player_1);
	xuLyMoiTruong(player_2);
	xuLyCungDoi(player_1);
	xuLyCungDoi(player_2);
	xuLyDoiKhang(player_1, player_2);
	xuLyDoiKhang(player_2, player_1);
	if (getCheDo() == 1)   // xử lý thời gian
	{
		thoiGian = 1;
	}
	else
	{
		cout << "\nINPUT MATCH TIME (1/2/5 MINUTES): ";
		cin >> thoiGian;
	}
}
void GAME::hienThiTranDau()
{
	cout << "\n....____________________________  _______";
	cout << "\n.../ __/  _ / ___/ // /_  __/  _/ |/ / ___/";
	cout << "\n../ _/_/ / / (_ / _  / / / _/ //    / (_ / ";
	cout << "\n./_/ /___ /\___/_//_/ /_/ /___/_/|_/\___/ ";
	cout << "\n";
	cout << "\nENVIROMENT: " << moiTruong << endl;
	for (int i = 0; i < nChamp; ++i) // in ra danh sách tướng đang đấu
	{
		cout << "\n" << setw(20) << player_1.at(i).getTen() << setw(20) << "\tvs.\t\t" << player_2.at(i).getTen();
	}
	cout << "\n\nTIME: ";
	for (int n = 1; n <= (int)thoiGian * 60; n++) // chạy đến hết giờ thi đấu
	{
		if (n == 60 || n == 120 || n == 180 || n == 240 || n == 300) // tại các thời điểm này thì reset để hiển thị lại đồng hồ đếm
		{
			system("cls");
			cout << "\n....____________________________  _______";
			cout << "\n.../ __/  _ / ___/ // /_  __/  _/ |/ / ___/";
			cout << "\n../ _/_/ / / (_ / _  / / / _/ //    / (_ / ";
			cout << "\n./_/ /___ /\___/_//_/ /_/ /___/_/|_/\___/ ";
			cout << "\n";
			cout << "\nENVIROMENT: " << moiTruong << endl;
			for (int i = 0; i < nChamp; ++i)
			{
				cout << "\n" << setw(20) << player_1.at(i).getTen() << setw(20) << "\tvs.\t\t" << player_2.at(i).getTen();
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
		endwait = clock() + 0.1 * CLOCKS_PER_SEC;  // 0.01 để đánh nhanh hơn tốc độ bình thường 100 lần
		while (clock() < endwait) {}
	}
	Sleep(1000);
	cout << "\n...._____  _____   ________   __  _______";
	cout << "\n.../ __/ |/ / _ \ / ___/ _ | /  |/  / __/";
	cout << "\n../ _//    / // // (_ / __ |/ /|_/ / _/  ";
	cout << "\n./___/_/|_/____/ \___/_/ |_/_/  /_/___/";
	Sleep(2000);
}
void GAME::danhNhau(TUONG& x, TUONG& y) // 2 tướng đánh nhau
{
	float xy = x.thoiGianGietDich(y); // thời gian x giết y
	float yx = y.thoiGianGietDich(x); // thời gian y giết x
	if (xy == -1 && yx == -1)	// cả 2 đánh đều không vào máu
	{
		return;
	}
	else if (xy == -1)			// x đánh ko vào máu y => y thắng
	{
		x.setMau(0);
	}
	else if (yx == -1)			// x thắng
	{
		y.setMau(0);
	}
	else if (xy > yx) // thời gian y giết x bé hơn nên y thắng => số máu của y còn, số máu x = 0
	{
		int sld = (int)(yx / x.getTocDanh());// số lần đánh của x
		y.setMau(y.getMau() - sld * (x.getCong() - y.getThu()));
		x.setMau(0);
	}
	else if (xy < yx) // trường hợp x thắng
	{
		int sld = (int)(xy / y.getTocDanh());// số lần đánh của x
		x.setMau(x.getMau() - sld * (y.getCong() - x.getThu()));
		y.setMau(0);
	}
	else             // xy = yx
	{
		if (x.getTocDanh() == y.getTocDanh())		// nếu tốc đánh là như nhau thì cả 2 cùng chết
		{	
			x.setMau(0);
			y.setMau(0);
		}
		else if (x.getTocDanh() > y.getTocDanh())	// y ra đòn nhanh hơn => y thắng
		{
			y.setMau(x.getCong() - y.getThu());		// còn 1 lượng máu bằng lần ra đòn cuối của x
			x.setMau(0);
		}
		else
		{
			x.setMau(y.getCong() - x.getThu());
			y.setMau(0);
		}
	}
}
void GAME::danhNhau()
{
	for (int i = 0; i < nChamp; ++i)
	{
		danhNhau(player_1.at(i), player_2.at(i));  // cho 2 con tướng đánh nhau từng đôi
	}
}
int GAME::xuLyThangThua() // 1 nếu player 1 thắng, 0 nếu hòa, -1 nếu player 1 thua
{
	int count1 = 0; // đếm số tướng team 1 chết
	int count2 = 0; // đếm số tướng team 2 chết
	for (int i = 0; i < nChamp; ++i)
	{
		if (player_1.at(i).getMau() == 0)
		{
			count1++;
		}
		if (player_2.at(i).getMau() == 0)
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
string GAME::ketQua()  // trả về kết quả trận đấu
{
	string str;
	if (xuLyThangThua() == 1)
	{
		str = "PLAYER WIN: " + username_1;
	}
	else if(xuLyThangThua() == -1)
	{
		str = "PLAYER WIN: " + username_2;
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
	cout << "\n" << ketQua();
	cout << "\n\nTEAM " << username_1;
	for (int i = 0; i < nChamp; ++i)
	{
		cout << endl << "\t\t";
		player_1.at(i).print(cout);
	}
	cout << "\n\nTEAM " + username_2;
	for (int i = 0; i < nChamp; ++i)
	{
		cout << endl << "\t\t";
		player_2.at(i).print(cout);
	}
	cout << "\n\n\n\n\n";
}
void GAME::luuLog() // lưu lại log
{
	LOG log;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	log.setH(ltm->tm_hour);
	log.setM(ltm->tm_min);
	log.setS(ltm->tm_sec);
	log.setDD(ltm->tm_mday);
	log.setMM(1 + ltm->tm_mon);
	log.setYY(1900 + ltm->tm_year);
	log.setUsername_1(username_1);
	log.setUsername_2(username_2);
	log.setListTuongPlayer_1(player_1);
	log.setListTuongPlayer_2(player_2);
	log.setMoiTruong(moiTruong);
	log.setKetQua(ketQua());
	fstream fileOut("Log.txt", ios::in | ios::out | ios::app);
	if (!fileOut)
	{
		cout << "\nCANNOT OPEN FILE!";
		exit(0);
	}
	fileOut << log;
	fileOut.close();
}
void GAME::themTuong()
{
	TUONG x;
	cout << "\nINPUT CHAMPION!!!\n";
	x.nhapThongTin();                  // nhập thông tin tướng cần thêm
	fstream fileOut("ListHero.txt", ios::in | ios::out | ios::app);
	if (!fileOut)
	{
		cout << "\nCANNOT OPEN FILE";
		exit(0);
	}
	fileOut << x;
	fileOut.close();
}
void GAME::xoaTuong()
{
	fstream  fileOut("ListHero.txt", ios::out | ios::trunc);
	cout << "\nDELETE CHAMPION!!!\n";
	cout << "\nCHAMPION" << endl;  // in ra danh sách tướng có trong list
	for (int i = 0; i < listTuong.size(); ++i)
	{
		cout << "\n		" << i + 1 << ". ";
		listTuong.at(i).print(cout);
	}
	int idx;
	bool flag = true;			// nếu flag == true thì yêu cầu nhập lại
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
			if (idx < 1 || idx > listTuong.size())
			{
				throw 1;
			}
			flag = false;			// nhập đúng rồi thì thoát
		}
		catch (int x)
		{
			if (x)
			{
				flag == true;
			}
		}
	}
	for (int i = 0; i < listTuong.size(); ++i)
	{
		if (i != idx - 1)             // nếu ko phải tướng cần xóa thì lưu lại vào file cũ
		{
			fileOut << listTuong.at(i);
		}
	}
	fileOut.close();
}