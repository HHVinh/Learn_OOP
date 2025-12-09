#ifndef CHITIETHOADONNHAP_H
#define CHITIETHOADONNHAP_H

#include <string>
using namespace std;

class ChiTietHoaDonNhap 
{
private:
    string m_maHang;
    string m_ngaySanXuat;
    int m_soLuong;
    int m_donGia;

public:
    ChiTietHoaDonNhap();
    ChiTietHoaDonNhap(const string& maHang, const string& ngaySanXuat, int soLuong, double donGia);
    string getMaHang() const;
    string getNgaySanXuat() const;
    int getSoLuong() const;
    int getDonGia() const;
    int thanhTien() const;
    void setMaHang(const string& ma);
    void setNgaySanXuat(const string& date);
    void setSoLuong(int sl);
    void setDonGia(double dg);
};

#endif
