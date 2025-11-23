#include <iostream>
#include "NHANVIENSX.h"
using namespace std;

NHANVIENSX ::NHANVIENSX()
{
    // cout << "Hàm tạo 0 đối số của NHANVIENSX\n";
    SoLuong = 0;
}

NHANVIENSX ::NHANVIENSX(int t) : NHANVIEN(t)
{
    // cout << "Hàm tạo 1 đối số của NHANVIENSX\n";
    SoLuong = 0;
}

NHANVIENSX ::NHANVIENSX(const NHANVIENSX& b) : NHANVIEN(b)
{
    // cout << "Hàm tạo sao chép của NHANVIENSX\n";
    SoLuong = b.SoLuong;
}

void NHANVIENSX ::HamAo()
{
    cout << "Hàm ảo của NHANVIENSX\n";
}

void NHANVIENSX ::operator=(const NHANVIENSX& b)
{
    if(this != &b)
    {
        SoLuong = b.SoLuong;
    }
}

void NHANVIENSX ::NhapNV()
{
    cout << "Hàm nhập của NHANVIENSX\n";
    return;
    NHANVIEN ::NhapNV();
    cout<<"Nhập số sản phẩm: ";
    cin >> SoLuong;
    cin.ignore();
}

int NHANVIENSX::TinhLuongNVSX()
{
    return SoLuong * 10;
}

NHANVIENSX ::~NHANVIENSX()
{

}
