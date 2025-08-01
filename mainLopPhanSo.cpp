#include <stdio.h>
#include "lopPhanSo.h"

int main()
{
    lopPhanSo a, b;
    // int n;
    // printf("Nhập số lượng phân số: ");
    // scanf("%d", &n);
    // for (int i = 0; i < n; i++)
    // {
    //     /* code */
    // }
    
    printf("Nhập phân số thứ 1: \n");
    a.nhapPhanSo();
    printf("\nNhập phân số thứ 2: \n");
    b.nhapPhanSo();

    lopPhanSo kq = a.cong(b);

    printf("\n%d/%d + %d/%d = %d/%d", a.tuSo, a.mauSo, b.tuSo, b.mauSo, kq.tuSo, kq.mauSo);
    printf("\n");
    kq.inPhanSo();

    return 0;
}