#include <stdio.h>
#include "lopDaGiac.h"

int main()
{
    lopDaGiac daGiac;

    daGiac.nhapDiem();

    double chuVi = daGiac.tinhChuVi();

    printf("Chu vi đa giác là: %f\n", chuVi);
    return 0;
}