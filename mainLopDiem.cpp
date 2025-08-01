#include <stdio.h>
#include "lopDiem.h"

int main()
{
    lopDiem a, b;
    a.nhapDiem();
    b.nhapDiem();

    printf("\nĐiểm A là: ");
    a.xuatDiem();
    printf("\nĐiểm B là: ");
    b.xuatDiem();

    double kq = a.khoangCach(b);

    printf("\nKhoảng cách giữa 2 điểm A và B là: %f", kq);

    return 0;
}