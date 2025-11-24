#include <iostream>
#include "CONGTY.h"

using namespace std;

CONGTY::CONGTY()
{
    SoLuongNV = 0;
}

void CONGTY::Nhap()
{
    cout << "Nhập số lượng NV: ";
    cin >> SoLuongNV;
    cin.ignore();

    for (int i = 0; i < SoLuongNV; i++)
    {
        cout << "Nhập nhân viên thứ " << i + 1 << ": ";
        cout << "\nNhập loại nhân viên (1 NVVP, 2 NVSX): ";
        int loaiNhanVien;
        cin >> loaiNhanVien;
        if (loaiNhanVien == 1)
            DanhSachNV[i] = new NHANVIENVP();
        else
            DanhSachNV[i] = new NHANVIENSX();

        DanhSachNV[i]->NhapNV();

    }

}

double CONGTY::TongLuong()
{
    double TongLuong = 0;
    for (int i = 0; i < SoLuongNV; i++)
    {
        TongLuong += DanhSachNV[i]->TinhLuong();

    }

    return TongLuong;
}

CONGTY::~CONGTY()
{
    
}
