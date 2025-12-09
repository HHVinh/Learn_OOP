#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Observer.h"
#include "hoaDonNhap.h"  
#include <vector>
#include <string>
using namespace std;

class FileManager : public Observer 
{
private:
	static FileManager* instance;
	FileManager() = default;
	void ghiMatHang();
	void ghiLoaiHang();
	void ghiHoaDonNhap();
	void ghiHoaDonXuat();
	void ghiKho();
	void xoaKhoTheoHoaDon(const string& maHD);
	void xoaKhoTheoChiTiet(const string& maHD, const string& maMH);
	void capNhatKhoSauXuat(const string& maHang, int soLuongXuat);
	void capNhatKhoSauXuat_HoanTra(const string& maHang, int soLuongHoan);

public:
	static FileManager* getInstance();
	friend class QuanLyHoaDonXuat;
	void docLoaiHang();
	void docMatHang();
	void docHoaDonNhap();
	void docHoaDonXuat();
	void docKho(std::vector<std::vector<std::string>>& dsKho);
	void Update(Subject* subject) override;
	void capNhatKhoSauXuatPublic(const string& maHang, int soLuongXuat) 
	{
		capNhatKhoSauXuat(maHang, soLuongXuat);
	}
	void capNhatKhoSauXuat_HoanTraPublic(const string& maHang, int soLuongHoan) 
	{
		capNhatKhoSauXuat_HoanTra(maHang, soLuongHoan);
	}
};

#endif
