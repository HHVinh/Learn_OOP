#include <stdio.h>
#include "lopDaGiac2.h"

int main()
{
    lopDaGiac daGiac;

    daGiac.nhapDiem();

    double result = daGiac.chuVi();
    printf("Chu vi của đa giác vừa nhập là: %.2lf", result);

    return 0;
}