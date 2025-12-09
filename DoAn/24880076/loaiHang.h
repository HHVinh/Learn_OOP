#ifndef LOAIHANG_H
#define LOAIHANG_H

#include <vector>
#include <iostream>
#include <string>
using namespace std;

class LoaiHang
{
private:
    string m_maLoai;
    string m_tenLoai;
    string m_moTa;
    
public:
    LoaiHang();
    LoaiHang(string maLoai, string tenLoai, string moTa);
    string getMaLoai() const;
    string getTenLoai() const;
    string getMoTa() const;
    bool nhap();
    void setTenLoai(const string& ten);
    void setMoTa(const string& mota);
    void xuatDuLieu() const;
    static void inTieuDe();
};

#endif
