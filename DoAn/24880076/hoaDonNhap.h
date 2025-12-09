#ifndef HOADONHAP_H
#define HOADONHAP_H

#include <string>
#include <vector>
#include "chiTietHoaDonNhap.h"
using namespace std;

class HoaDonNhap 
{
private:
	string m_maHoaDon;
	string m_ngayNhap;
	string m_nhaCungCap;
	vector<ChiTietHoaDonNhap> dsChiTiet;

public:
	HoaDonNhap();
	HoaDonNhap(const string& maHD, string ngayNhap, const string& nhaCungCap);
	string getMaHD() const;
	string getNgayNhap() const;
	string getNhaCungCap() const;
	vector<ChiTietHoaDonNhap>& getChiTiet();
	const vector<ChiTietHoaDonNhap>& getChiTiet() const;
	void setMaHD(const string& maHD);
	void setNgayNhap(const string& ngayNhap);
	void setNhaCungCap(const string& nhaCungCap);
	void themChiTietHoaDon(const ChiTietHoaDonNhap& cthd);
	bool nhapHoaDonNhap_MatHangCoSan();
	bool nhapHoaDonNhap_MatHangMoi();
	bool nhapHoaDonNhap_NhaCungCapMoi();
	int tongTien() const;
	void xuatDuLieu() const;
	static void inTieuDe();
};

#endif

