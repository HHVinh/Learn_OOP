#include <stdio.h>
#include "lopDaGiac.h"
#include "lopDiem.cpp"

void lopDaGiac::nhapDiem()
{   
    printf("Nhập số lượng đỉnh: ");
    scanf("%d", &soLuongDinh);
    
    for(int i = 0; i < soLuongDinh; i++)
    {
        printf("Nhập điểm %d: \n", i +1);
        danhSachDinh[i].nhapDiem();
    }
}

double lopDaGiac::tinhChuVi()
{
    double chuVi;
    for (int i = 0; i <= soLuongDinh -1; i++)
    {
        chuVi += danhSachDinh[i].khoangCach(danhSachDinh[i+1]);
    }
    chuVi += danhSachDinh[0].khoangCach(danhSachDinh[soLuongDinh-1]);
    return chuVi;
}