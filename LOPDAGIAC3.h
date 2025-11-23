#ifndef LOPDAGIAC_H
#define LOPDAGIAC_H

#include "LOPDIEM3.h"
class LOPDAGIAC
{
public:

    // Thành phần dữ liệu
    LOPDIEM DanhSachDinh[100];
    int SoLuongDinh;

    // Thành phần xử lý
    void nhapDG();
    double TinhChuViDG();
};

#endif