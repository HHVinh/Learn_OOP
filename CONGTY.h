#ifndef CONGTY_H
#define CONGTY_H

#include "NHANVIEN.h"
#include "NHANVIENVP.h"
#include "NHANVIENSX.h"

class CONGTY
{
    private:
        NHANVIEN* DanhSachNV[100];
        int SoLuongNV;

    public:
        CONGTY();
        void Nhap();
        double TongLuong();
        ~CONGTY();

};

#endif