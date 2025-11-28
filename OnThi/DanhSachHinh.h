#ifndef DANHSACHHINH_H
#define DANHSACHHINH_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "HinhHoc.h"
#include "HinhTron.h"
#include "HinhChuNhat.h"

class DanhSachHinh
{
private:
    vector<HinhHoc*> m_DSHinh;
public:
    DanhSachHinh(/* args */);
    ~DanhSachHinh();
    virtual void themHinh();
    virtual int demSoLuong();

};

#endif