#include "DanhSachHinh.h"
DanhSachHinh::DanhSachHinh(/* args */)
{

}

DanhSachHinh::~DanhSachHinh()
{
    // for (int i = 0; i < m_DSHinh.size(); i++)
    // {
    //     delete m_DSHinh[i];
    // }

    m_DSHinh.clear();
}

void DanhSachHinh::themHinh()
{
    int soLuongHinh;
    cout << "\nNhap so luong hinh: ";
    cin >> soLuongHinh;

    for (int i = 0; i < soLuongHinh; i++)
    {
        int luaChon;
        cout << "\nNhap lua chon (1 Hinh Tron - 2 Hinh Chu Nhat): ";
        cin >> luaChon;

        HinhHoc* hinh = nullptr;

        switch (luaChon)
        {
            case 1:
                hinh = new HinhTron();
                break;
            
            case 2:
                hinh = new HinhChuNhat();
                break;
            default:
                cout << "Lựa chọn không hợp lệ!";
                i--;
                continue; 
        }

        hinh->nhapHinh();
        m_DSHinh.push_back(hinh);
    }
}

int DanhSachHinh::demSoLuong()
{
    int soLuong = 0;
    for (int i = 0; i < m_DSHinh.size(); i++)
    {
        if (m_DSHinh[i]->hinhYeuCau())
        {
            soLuong ++;
        }
    }
    return soLuong;
}

