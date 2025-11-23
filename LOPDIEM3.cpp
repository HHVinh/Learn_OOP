#include <stdio.h>
#include "LOPDIEM3.h"
#include <math.h>

void LOPDIEM ::NhapDiem()
{
    printf("Nhập x: ");
    scanf("%d", &x);
    printf("Nhập y: ");
    scanf("%d", &y);
}

double LOPDIEM::TinhKhoangCach(LOPDIEM b)
{
    double ketQua;
    ketQua = sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
    return ketQua;
}