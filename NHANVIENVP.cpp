#include <iostream>
#include "NHANVIENVP.h"
using namespace std;

NHANVIENVP ::NHANVIENVP()
{
    // cout << "Hàm tạo 0 đối số của NHANVIENVP\n";
    HeSoLuong = 0;
    PhuCap = 0;
}

NHANVIENVP ::NHANVIENVP(int t) : NHANVIEN(t)
{
    // cout << "Hàm tạo 1 đối số của NHANVIENPV\n";
    HeSoLuong = 0;
    PhuCap = 0;
}

NHANVIENVP ::NHANVIENVP(const NHANVIENVP& b) : NHANVIEN(b)
{
    // cout << "Hàm tạo sao chép của NHANVIENVP\n";
    HeSoLuong = b.HeSoLuong;
    PhuCap = b.PhuCap;
}

void NHANVIENVP ::HamAo()
{
    cout << "Hàm ảo của NHANVIENVP\n";
}

void NHANVIENVP::operator=(const NHANVIENVP& b)
{
    if(this != &b)
    {
        HeSoLuong = b.HeSoLuong;
        PhuCap = b.PhuCap;
    }
}

void NHANVIENVP ::NhapNV()
{
    cout << "Hàm nhập của NHANVIENVP\n";
    return;
    NHANVIEN:: NhapNV();
    cout << "Nhập hệ số lương: ";
    cin >> HeSoLuong;
    cout << "Nhập phụ cấp: ";
    cin >> PhuCap;
    cin.ignore();
}

double NHANVIENVP::TinhLuongNVVP()
{
    return HeSoLuong * 1000 + PhuCap;
}

NHANVIENVP ::~NHANVIENVP()
{

}
