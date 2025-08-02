#include <stdio.h>
#include "lopTamGiac.h"
#include "lopDiem.h"

int main()
{
    lopTamGiac tamGiac;

    tamGiac.nhapDiem();
    double chuVi = tamGiac.tinhChuVi();

    printf("Chu vi tam giác là: %f\n", chuVi);
    return 0;
}
