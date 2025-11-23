#ifndef CONGTY_H
#define CONGTY_H

#include "NHANVIEN.h"
#include "NHANVIENVP.h"
#include "NHANVIENSX.h"

class CONGTY
{
    private:
        NHANVIENSX DanhSachNVSX[100];
        int SoLuongSX;
        NHANVIENVP DanhSachNVVP[100];
        int SoLuongVP;

    public:
        CONGTY();
        void Nhap();
        double TongLuong();

};

#endif