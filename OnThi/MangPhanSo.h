#ifndef MANGPHANSO_H
#define MANGPHANSO_H

#include <iostream>
#include <vector>
#include "PhanSoThi.h"
using namespace std;


class MangPhanSo
{
private:
    vector<PhanSoThi> danhSach;

public:
    MangPhanSo();
    ~MangPhanSo();
    void themPhanSo(const PhanSoThi& b);
    void inMangPhanSo();
    double tinhTrungBinh();
};


#endif