#ifndef QUANLYMATHANG_H
#define QUANLYMATHANG_H

#include <vector>
#include <iostream>
#include <string>
#include "matHang.h"
#include "subject.h"
using namespace std;

class QuanLyMatHang: public Subject
{
private:
	vector<MatHang> ds;
	static QuanLyMatHang* instance;
	QuanLyMatHang();
	bool notifyEnabled = true;

public:
	static QuanLyMatHang* getInstance();
	string sinhMaMatHang();
	void themMatHang(const MatHang& mh);
	bool xoaMatHang(const string& ma);
	bool suaMatHang(const string& ma);
	void timKiemTheoTen(const string& tuKhoa);
	void hienThiDanhSach();
	vector<MatHang>& getDanhSach();
	void setNotifyEnabled(bool state) { notifyEnabled = state; }
	bool isNotifyEnabled() const { return notifyEnabled; }
	void Notify() override 
	{
		if (!notifyEnabled) return; 
		Subject::Notify(); 
	}
	~QuanLyMatHang();
};

#endif