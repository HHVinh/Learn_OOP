#include <iostream>
using namespace std;
#include "MATPHANG.h"
#include "HINHCHUNHAT.h"
#include "HINHTRON.h"

MATPHANG::MATPHANG()
{
    soLuongHinh = 0;
}

MATPHANG::~MATPHANG()
{

}

void MATPHANG::nhap()
{
    cout << "Hàm nhập MATPHANG\n";
    cout << "Nhập số lượng hình: ";
    cin >> soLuongHinh;

    for (int i = 0; i < soLuongHinh; i++)
    {
        cout << "\nNhập hình thứ " << i + 1 << " :";
        cout << "\nNhập loại hình (1 hình Chữ Nhật, 2 hình Tròn): ";
        int loaiHinh;
        cin >> loaiHinh;
        if (loaiHinh == 1)
            DANHSACHHINH[i] = new HINHCHUNHAT();
        else
            DANHSACHHINH[i] = new HINHTRON();
        
        DANHSACHHINH[i] ->nhapHinh();
    }
}

double MATPHANG::tongChuVi()
{
    double ketQua = 0;
    for (int i = 0; i < soLuongHinh; i++)
    {
        ketQua += DANHSACHHINH[i]->tinhChuVi();
    }
    return ketQua;
}