#include <stdio.h>
#include "lopTamGiac2.h"
#include "lopDiem2.h"

void lopTamGiac::nhapDiem()
{
    printf("\nNhập điểm A: ");
    A.nhapDiem();
    printf("\nNhập điểm B: ");
    B.nhapDiem();
    printf("\nNhập điểm C: ");
    C.nhapDiem();
}

double lopTamGiac::chuVi()
{
    double a, b, c;
    a = B.khoangCach(C);
    b = A.khoangCach(C);
    c = A.khoangCach(B);
    return a + b + c;
}