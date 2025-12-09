#ifndef CHITIETHOADONXUAT_H
#define CHITIETHOADONXUAT_H

#include <string>
using namespace std;

class ChiTietHoaDonXuat 
{
private:
    string m_maHang;
    int m_soLuong;
    int m_donGia;

public:
    ChiTietHoaDonXuat();
    ChiTietHoaDonXuat(const string& maHang, int soLuong, double donGia);
    string getMaHang() const;
    int getSoLuong() const;
    int getDonGia() const;
    int thanhTien() const;
    void setMaHang(const string& ma);
    void setSoLuong(int sl);
    void setDonGia(double dg);
};

#endif
