#include <stdio.h>
#include "phanSo3.h"

void NhapPhanSo(PhanSo &a)
{
    printf("Nhập tử số: ");
    scanf("%d", &a.tuSo);
    printf("Nhập mẫu số: ");
    scanf("%d", &a.mauSo);
}

PhanSo CongHaiPhanSo(PhanSo a, PhanSo b)
{
    PhanSo ketQua;
    ketQua.tuSo = a.tuSo * b.mauSo + a.mauSo * b.tuSo;
    ketQua.mauSo = a.mauSo * b.mauSo;
    return ketQua;
}

void XuatPhanSo(PhanSo a)
{
    printf("%d/%d", a.tuSo, a.mauSo);
}