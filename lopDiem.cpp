#include <stdio.h>
#include <math.h>
#include "lopDiem.h"

void lopDiem::nhapDiem()
{
    printf("Nhập tọa độ X: ");
    scanf("%d",&X);
    printf("Nhập tọa độ Y: ");
    scanf("%d",&Y);
}

void lopDiem::xuatDiem()
{
    printf("(%d,%d)", X, Y);
}

double lopDiem::khoangCach(lopDiem B)
{
    double kq = sqrt((X - B.X) * (X - B.X) + (Y - B.Y) * (Y - B.Y));
    return kq;
}