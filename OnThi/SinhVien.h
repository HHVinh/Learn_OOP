#ifndef SINHVIEN_H
#define SINHVIEN_H
#include <iostream>
#include <string>
using namespace std;

class SinhVien
{
private:
    int m_MSSV;
    string m_hoVaTen;
    double m_diemTrungBinh;

public:
    SinhVien();
    ~SinhVien();
    void nhapThongTin();

    double getDiemTrungBinh() const;
    void xuatThongTin() const;
};

#endif