#ifndef PHANSOTHI_H
#define PHANSOTHI_H

#include <iostream>
#include <vector>
using namespace std;

class PhanSoThi
{
private:
    int m_tuSo;
    int m_mauSo;
    vector<PhanSoThi*> danhSach;

public:
    PhanSoThi();
    ~PhanSoThi();
    void NhapPhanSo();
    void InPhanSo();
    PhanSoThi operator+(const PhanSoThi& b);
    double giaTriPhanSo() const;
    bool phanSoDuong() const;
    void soSanh(int k);
};


#endif