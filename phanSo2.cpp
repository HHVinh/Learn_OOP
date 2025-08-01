#include <stdio.h>
#include "phanSo2.h"

void nhapPhanSo(ps &a)
{
    printf("Tử số: ");
    scanf("%d", &a.tuSo);
    printf("Mẫu số: ");
    scanf("%d", &a.mauSo);
}

ps congHaiPhanSo(ps a, ps b)
{
    ps kq;

    kq.tuSo = a.tuSo * b.mauSo + a.mauSo * b.tuSo;
    kq.mauSo = a.mauSo * b.mauSo;

    return kq;
}

void inPhanSo(ps a)
{
    printf("Kết quả của cộng hai phân số trên là: %d/%d", a.tuSo, a.mauSo);
}




