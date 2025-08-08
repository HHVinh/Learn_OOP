#include <stdio.h>
#include "lopDiem2.h"
#include "lopTamGiac2.h"


int main()
{
    lopDiem A, B;

    A.nhapDiem();
    B.nhapDiem();

    double result = A.khoangCach(B);
    printf("\nKhoảng cách tử điểm A đến điểm B là: %.2f", result);

    return 0;
}