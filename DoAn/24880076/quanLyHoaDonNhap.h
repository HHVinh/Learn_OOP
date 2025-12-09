#ifndef QUANLYHOADONNHAP_H
#define QUANLYHOADONNHAP_H

#include <vector>
#include "hoaDonNhap.h"
#include "subject.h"
using namespace std;

class QuanLyHoaDonNhap : public Subject 
{
private:
	vector<HoaDonNhap> ds;
	static QuanLyHoaDonNhap* instance;
	static string maHoaDonDangXoa;
	QuanLyHoaDonNhap();

public:
	static QuanLyHoaDonNhap* getInstance();
	static string getMaHoaDonDangXoa();
	string sinhMaHoaDonNhap();
	bool xoaHoaDon(const string& maHD);
	bool suaHoaDon(const string& maHD);
	bool suaThongTinHoaDon(HoaDonNhap& hd);
	bool suaChiTietHoaDon(HoaDonNhap& hd);
	bool xoaChiTietHoaDon(HoaDonNhap& hd);
	void themHoaDon(const HoaDonNhap& hd);
	void hienThiDanhSach();
	void timKiemHoaDonTheoNhaCungCap(const string& tuKhoa);
	vector<HoaDonNhap>& getDanhSach();
	static void setMaHoaDonDangXoa(const string& maHD);
	~QuanLyHoaDonNhap();
};

#endif