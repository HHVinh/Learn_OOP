#include <stdio.h>
#include "lopTamGiac.h"
#include "lopDiem.cpp"

void lopTamGiac::nhapDiem()
{
    do
    {
        printf("Nhập điểm A:\n");
        A.nhapDiem();
        printf("\nNhập điểm B:\n");
        B.nhapDiem();
        printf("\nNhập điểm C:\n");
        C.nhapDiem();
    } while (kiemTraTamGiac(A,B,C) == false);
}

bool lopTamGiac::kiemTraTamGiac(lopDiem A, lopDiem B, lopDiem C)
{
    double a, b, c;
    a = A.khoangCach(B);
    b = B.khoangCach(C);
    c = C.khoangCach(A);

    if (a > 0 && b > 0 && c > 0 &&
        a + b > c && a + c > b && b + c > a)
    {
        return true;
    }
    else
    {
        return false;
    }
}


double lopTamGiac::tinhChuVi()
{
    double a, b, c;
    a = B.khoangCach(C);
    b = A.khoangCach(C);
    c = A.khoangCach(B);
    return a + b + c;
}