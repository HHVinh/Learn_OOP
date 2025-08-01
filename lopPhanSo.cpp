#include <stdio.h>
#include "lopPhanSo.h"

void lopPhanSo::nhapPhanSo()
{
    printf("Nhập tử số: ");
    scanf("%d", &tuSo);
    printf("Nhập mẫu số: ");
    scanf("%d", &mauSo);
}

lopPhanSo lopPhanSo::cong(lopPhanSo b)
{
    lopPhanSo kq;

    kq.tuSo = tuSo * b.mauSo + mauSo*b.tuSo;
    kq.mauSo = mauSo * b.mauSo;

    return kq;
}

void lopPhanSo::inPhanSo()
{
    printf("%d/%d", tuSo, mauSo);
}