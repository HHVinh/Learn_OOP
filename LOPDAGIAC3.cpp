#include <stdio.h>
#include "LOPDAGIAC3.h"

void LOPDAGIAC ::nhapDG()
{   
    printf("Nhập số lượng đỉnh: ");
    scanf("%d", &SoLuongDinh);

    for (int i = 0; i < SoLuongDinh; i++)
    {
        printf("Nhập đỉnh thứ %d:\n", i + 1);
        DanhSachDinh[i].NhapDiem();
    }
}

double LOPDAGIAC ::TinhChuViDG()
{
    double chuVi = 0;
    // Khoảng cách từ đỉnh đầu tới đỉnh kế cuối
    // Ví dụ có 5 đỉnh thì từ đỉnh 1 -> 4 (i chạy từ 0 -> 3)
    for(int i = 0; i < SoLuongDinh - 1; i++)
    {
        chuVi += DanhSachDinh[i].TinhKhoangCach(DanhSachDinh[i+1]);
    }

    // Tính thêm khoảng cách từ đỉnh cuối tới đỉnh đầu
    chuVi += DanhSachDinh[SoLuongDinh - 1].TinhKhoangCach(DanhSachDinh[0]);
    return chuVi;
}