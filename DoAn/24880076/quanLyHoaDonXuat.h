#ifndef QUANLYHOADONXUAT_H
#define QUANLYHOADONXUAT_H

#include <vector>
#include "subject.h"
#include "hoaDonXuat.h"
#include "quanLyMatHang.h"
using namespace std;

class QuanLyHoaDonXuat : public Subject 
{
private:
	vector<HoaDonXuat> ds;
	static QuanLyHoaDonXuat* instance;
	QuanLyHoaDonXuat();

public:
	static QuanLyHoaDonXuat* getInstance();
	string sinhMaHoaDonXuat();
	bool xoaHoaDon(const string& maHD);
	bool suaHoaDon(const string& maHD);
	bool suaThongTinHoaDon(HoaDonXuat& hd);
	bool suaChiTietHoaDon(HoaDonXuat& hd);
	bool themChiTietHoaDon(HoaDonXuat& hd);
	bool xoaChiTietHoaDon(HoaDonXuat& hd);
	void themHoaDon(const HoaDonXuat& hd);
	void hienThiDanhSach();
	void timKiemHoaDonTheoKhachHang(const string& tuKhoa);
	vector<HoaDonXuat>& getDanhSach();
	~QuanLyHoaDonXuat();
};

#endif