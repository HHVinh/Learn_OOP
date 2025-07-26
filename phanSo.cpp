#include <stdio.h>
#include "phanSo.h"


void nhapPhanSo(phanSo &a)
{
    printf("Nhập tử số: ");
    scanf("%d",&a.TuSo);
    printf("Nhập mẫu số: ");
    scanf("%d",&a.MauSo);
}

phanSo congHaiPhanSo(phanSo &a, phanSo &b)
{
    phanSo ketqua;
    ketqua.TuSo = a.TuSo * b.MauSo + a.MauSo * b.TuSo;
    ketqua.MauSo = a.MauSo * b.MauSo;
    return ketqua;
}

void inPhanSo(phanSo &a)
{
    printf("Kết quả là: %d/%d", a.TuSo, a.MauSo);
}