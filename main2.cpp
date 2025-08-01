#include <stdio.h>
#include "phanSo2.h"

int main()
{
    ps a, b;
    printf("Nhập phân số: \n\n");

    printf("Phân số 1: \n");
    nhapPhanSo(a);
    printf("\nPhân số 2: \n");
    nhapPhanSo(b);

    ps kq = congHaiPhanSo(a, b);

    inPhanSo(kq);

    return 0;
}