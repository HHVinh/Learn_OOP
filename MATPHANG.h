#ifndef MATPHANG_H
#define MATPHANG_H
#include "HINH.h"

class MATPHANG
{
    private:
        HINH* DANHSACHHINH[100];
        int soLuongHinh;

    public:
        MATPHANG();
        ~MATPHANG();
        void nhap();
        double tongChuVi();
};

#endif