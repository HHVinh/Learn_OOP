#include "QuanLyHinh.h"
#include "HTron.h"
#include "HVuong.h"
#include "HChuNhat.h"
QuanLyHinh::QuanLyHinh()
{
}

QuanLyHinh::~QuanLyHinh()
{
    xoaTatCaHinh();
}

void QuanLyHinh::themHinh()
{   
    int soLuong;
    cout << "\nNhập số lượng hình: ";
    cin >> soLuong;

    for (int i  = 0; i < soLuong; i++)
    {
        int loai;
        cout << "\n\nNhập loại cho hình thứ "<<i+1<<" (1: tròn, 2: vuông, 3: chữ nhật): ";
        cin >> loai;

        MatPhang* hinh = nullptr;

        switch (loai)
        {
            case 1:
                hinh = new HTron();
                break;

            case 2:
                hinh = new HVuong();
                break;

            case 3:
                hinh = new HChuNhat();
                break;

            default:
                cout << "Lựa chọn không hợp lệ!";
                i--;
                continue;
        }

        hinh->themHinh();
        danhSachHinh.push_back(hinh);
    }
}


void QuanLyHinh::xuatHinh()
{
    cout <<"\n"<<"=== DANH SÁCH HÌNH ===\n";

    for (int i = 0; i < danhSachHinh.size(); i++)
    {
        cout << "\n" <<"Hình thứ "<< i+1 <<": ";
        danhSachHinh[i]->xuatHinh();
        cout << "\n";
    }
}

void QuanLyHinh::xoaTatCaHinh() {
    for (auto hinh : danhSachHinh) {
        delete hinh;
    }
    danhSachHinh.clear();
}

