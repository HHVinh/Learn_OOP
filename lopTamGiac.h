#ifndef LOPTAMGIAC_H
#define LOPTAMGIAC_H

#include "lopDiem.h"

class lopTamGiac
{
private:
    lopDiem A;
    lopDiem B;
    lopDiem C;

public:
    void nhapDiem();
    double tinhChuVi();
    bool kiemTraTamGiac(lopDiem A, lopDiem B, lopDiem C);
};


#endif