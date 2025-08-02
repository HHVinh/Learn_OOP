#include <stdio.h>
#include "lopTamGiac.h"
#include "lopDiem.cpp"

void lopTamGiac::nhapDiem()
{
    printf("Nhập điểm A:\n");
    A.nhapDiem();
    printf("\nNhập điểm B:\n");
    B.nhapDiem();
    printf("\nNhập điểm C:\n");
    C.nhapDiem();
}

double lopTamGiac::tinhChuVi()
{
    double a, b, c;
    a = B.khoangCach(C);
    b = A.khoangCach(C);
    c = A.khoangCach(B);
    return a + b + c;
}