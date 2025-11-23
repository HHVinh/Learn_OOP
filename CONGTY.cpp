#include <iostream>
#include "CONGTY.h"

using namespace std;

CONGTY::CONGTY()
{
    SoLuongSX = 0;
    SoLuongVP = 0;
}

void CONGTY::Nhap()
{
    cout << "Nhập số lượng NVVP: ";
    cin >> SoLuongVP;
    cin.ignore();

    if(SoLuongVP > 0)
    {
        for (int i = 0; i < SoLuongVP; i++)
        {
            DanhSachNVVP[i].NhapNV();
        }
    }

    cout << endl << "Nhập số lượng NVSX: ";
    cin >> SoLuongSX;
    cin.ignore();

    if(SoLuongSX > 0)
    {
        for (int i = 0; i < SoLuongSX; i++)
        {
            DanhSachNVSX[i].NhapNV();
        }
    }
}

double CONGTY::TongLuong()
{
    double TongLuong = 0;
    for (int i = 0; i < SoLuongVP; i++)
    {
        TongLuong += DanhSachNVVP[i].TinhLuongNVVP();

    }

    for (int i = 0; i < SoLuongSX; i++)
    {
        TongLuong += DanhSachNVSX[i].TinhLuongNVSX();
        
    }

    return TongLuong;
}
