#include <stdio.h>
#include "phanSo.h"

int main()
{
    phanSo a, b;

    nhapPhanSo(a);
    nhapPhanSo(b);

    phanSo kq;

    kq = congHaiPhanSo(a, b);

    printf("Kết quả là: %d/%d",kq.TuSo,kq.MauSo);

    return 0;
}