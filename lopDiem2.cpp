#include <stdio.h>
#include "lopDiem2.h"
#include <math.h>

void lopDiem::nhapDiem()
{
    printf("\nNhập X: ");
    scanf("%d", &X);
    printf("\nNhập Y: ");
    scanf("%d", &Y);
}

double lopDiem::khoangCach(lopDiem B)
{
    double result;
    result = sqrt((X - B.X) * (X - B.X) + (Y - B.Y) * (Y - B.Y));
    return result;
}