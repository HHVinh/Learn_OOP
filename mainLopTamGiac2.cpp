#include <stdio.h>
#include "lopTamGiac2.h"
#include "lopDiem2.h"


int main()
{
    lopTamGiac tamGiac;

    tamGiac.nhapDiem();

    double result;
    result = tamGiac.chuVi();

    printf("Chu vi tam giác ABC là: %.2f",result);
    
    return 0;
}