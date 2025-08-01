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

double lopDiem::khoangCach(lopDiem b)
{
    double kq = sqrt((X - b.X) * (X - b.X) + (Y - b.Y) * (Y - b.Y));
    return kq;
}