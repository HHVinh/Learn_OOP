#include <stdio.h>
#include "lopDaGiac2.h"

void lopDaGiac::nhapDiem()
{
    printf("Nhập số lượng đỉnh: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("\nNhập điểm %d: ", i+1);
        arr[i].nhapDiem();
    }
}

double lopDaGiac::chuVi()
{
    double result;
    for(int i = 0; i < n-1; i++)
    {
        result += arr[i].khoangCach(arr[i+1]);
    }

    result += arr[0].khoangCach(arr[n-1]);

    return result;
}
