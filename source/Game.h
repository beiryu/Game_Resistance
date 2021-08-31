#pragma once
#ifndef __GAME_H__
#define __GAME_H__
#include "Champion.h"
#include <iomanip>
class GAME
{
private:
	vector<TUONG> listTuong; // danh sách tướng đọc từ file ListHero.txt
	vector<TUONG> player_1;  // danh sách tướng 2 người chơi
	vector<TUONG> player_2;
	string username_1;		// tên 2 người chơi
	string username_2;
	string moiTruong;		// môi trường
	float thoiGian;			// thời gian của hiệp đấu
	int cheDo;				// 1. là chế độ 1 người chơi, 2. là chế độ 2 người chơi
public:
	GAME();
	void setMoiTruong(string);
	void setThoiGian(float);
	void setUsername1(string _us1);
	void setUsername2(string _us2);
	void setCheDo(int);
	string getMoiTruong();
	float getThoiGian();
	string getUsername1();
	string getUsername2();
	int getCheDo();
	void docFile();             // đọc file ListHero.txt vào bộ nhớ game
	string randomMoiTruong();    // tạo môi trường
	vector<TUONG> chonTuongBinhThuong(); // người chơi chọn
	vector<TUONG> chonTuongNgauNhien();		// máy chọn
	void chonTuong();			// chọn tướng trong từng chế độ chơi
	void xuLyMoiTruong(vector<TUONG>&); // ảnh hưởng của môi trường
	void xuLyCungDoi(vector<TUONG>&);	// ảnh hưởng của các thành viên cùng team
	void xuLyDoiKhang(vector<TUONG>&, vector<TUONG>&); // ảnh hưởng của địch
	void xuLyChung();	  // xử lý chung cho 1 game đấu
	void hienThiTranDau();
	void danhNhau(TUONG&, TUONG&);
	void danhNhau();			// cho các tướng đánh nhau		
	int xuLyThangThua();		// 1. nếu player1 win, 0 nếu hòa, -1 nếu player1 thua
	string ketQua();			// toString kết quả trận đấu
	void print();				// in ra kết quả
	void luuLog();
	void themTuong();			// thêm vào file ListHero.txt
	void xoaTuong();			// xóa khỏi listhero
};
#endif // !__GAME_H__