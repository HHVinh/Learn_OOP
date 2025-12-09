#ifndef HOADONNHAPXUAT_H
#define HOADONNHAPXUAT_H

#include <string>
#include <vector>
#include "chiTietHoaDonXuat.h"
using namespace std;

class HoaDonXuat {
private:
    string m_maHoaDon;
    string m_ngayXuat;
    string m_khachHang;
    vector<ChiTietHoaDonXuat> dsChiTiet;

public:
    HoaDonXuat();
    HoaDonXuat(const string& maHD, const string& ngayXuat, const string& khachHang);
    string getMaHD() const;
    string getNgayXuat() const;
    string getKhachHang() const;
    bool nhapHoaDonXuat();
    int tongTien() const;
    vector<ChiTietHoaDonXuat>& getChiTiet();
    const vector<ChiTietHoaDonXuat>& getChiTiet() const;
    void setMaHD(const string& maHD);
    void setNgayXuat(const string& ngayNhap);
    void setKhachHang(const string& khachHang);
    void themChiTietHoaDon(const ChiTietHoaDonXuat& cthd);
    void xuatDuLieu() const;
    static void inTieuDe();
    void xuatChiTietHoaDonSua() const;

};

#endif
