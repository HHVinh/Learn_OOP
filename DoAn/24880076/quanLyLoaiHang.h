#ifndef QUANLYLOAIHANG_H
#define QUANLYLOAIHANG_H

#include <vector>
#include <iostream>
#include <string>
#include "loaiHang.h"
#include "subject.h"
using namespace std;

class QuanLyLoaiHang : public Subject 
{
private:
	vector<LoaiHang> ds;
	static QuanLyLoaiHang* instance;
	QuanLyLoaiHang();
	
public:
	static QuanLyLoaiHang* getInstance();
	string sinhMaLoaiHang();
	void themLoaiHang(const LoaiHang& lh);
	bool xoaLoaiHang(const string& maLoai);
	bool suaLoaiHang(const string& maLoai);
	void timKiemTheoTen(const string& tuKhoa);
	void hienThiDanhSach();
	vector<LoaiHang>& getDanhSach();
	~QuanLyLoaiHang();
};

#endif