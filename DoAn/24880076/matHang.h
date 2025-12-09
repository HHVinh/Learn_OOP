#ifndef MATHANG_H
#define MATHANG_H

#include <vector>
#include <iostream>
#include <string>
using namespace std;

class MatHang 
{
private:
    string m_ma;
    string m_tenHang;
    string m_hanSuDung;
    string m_congTySanXuat;
    string m_loai;

public:
    MatHang();
    MatHang(string ma, string tenHang, string hanSuDung, string congTySanXuat, string loai);
    string getMa() const;
    string getTen() const;
    string getHangSX() const;
    string getHanSD() const;
    string getLoai() const;
    bool nhap();
    bool nhapMatHangTheoNCC(const std::string& nhaCungCap);
    void setMa(const string& maMoi);
    void setTen(const string& tenHangMoi);
    void setHangSX(const string& congTySanXuatMoi);
    void setHanSD(const string& hanSuDungMoi);
    void setLoai(const string& loaiMoi);
    void xuatDuLieu() const;
    static void inTieuDe();
};

#endif
