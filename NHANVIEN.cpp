#include <iostream>
#include "NHANVIEN.h"
using namespace std;

NHANVIEN ::NHANVIEN()
{
    // cout << "Hàm tạo 0 đối số của NHANVIEN\n";
}

NHANVIEN ::NHANVIEN(int t)
{
    // cout << "Hàm tạo 1 đối số của NHANVIEN\n";
}

NHANVIEN ::NHANVIEN(const NHANVIEN& b)
{
    HoTen = b.HoTen;
    DiaChi = b.DiaChi;
}

void NHANVIEN ::operator=(const NHANVIEN& b)
{
    if (this != &b)
    {
        HoTen = b.HoTen;
        DiaChi = b.DiaChi;
    }
}

void NHANVIEN ::HamAo()
{
    cout << "Hàm ảo của NHANVIEN\n";
}

void NHANVIEN ::NhapNV()
{   
    cout << "Hàm nhập của NHANVIEN\n";
    return;
    cin.ignore();
    cout << "Nhập họ tên: ";
    getline(cin, HoTen);
    cout << "Nhập địa chỉ: ";
    getline(cin, DiaChi);
}

NHANVIEN ::~NHANVIEN()
{

}
