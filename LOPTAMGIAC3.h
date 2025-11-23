#ifndef LOPTAMGIAC_H
#define LOPTAMGIAC_H

#include "LOPDIEM3.h"

class LOPTAMGIAC
{
private:
     // Thành phần dữ liệu
    LOPDIEM A;
    LOPDIEM B;
    LOPDIEM C;
    bool KiemTraHopLe(LOPDIEM a, LOPDIEM b, LOPDIEM c);
public:
    // Thành phần xử lý
    void Nhap();
    double TinhChuVi();
};

#endif