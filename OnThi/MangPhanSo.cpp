#include "MangPhanSo.h"
#include <string>

MangPhanSo::MangPhanSo()
{

}

MangPhanSo::~MangPhanSo()
{
    danhSach.clear();
}

void MangPhanSo::themPhanSo(const PhanSoThi& b)
{   
    danhSach.push_back(b);
}

void MangPhanSo::inMangPhanSo()
{   
    cout << "\n\n ===== DANH SACH PHAN SO =====";
    for (int i = 0; i < danhSach.size(); i++)
    {
        cout << "\nPhan so thu "<<i+1<<": ";
        danhSach[i].InPhanSo();
        cout <<"\n";
    }
}

double MangPhanSo::tinhTrungBinh()
{
    if(danhSach.empty())
    {
        cout << "\nDanh sach rong.";
        return 0;
    }
    
    PhanSoThi ps;
    int dem = 0;

    for (int i = 0; i < danhSach.size(); i++)
    {
        if (danhSach[i].phanSoDuong())
        {
            ps = ps + danhSach[i];
            dem ++;
        }
    }

    if (dem == 0)
    {
        cout << "\nKhong co phan so duong trong mang.";
        return 0;
    }
    else
    {
        double trungBinh;
        trungBinh =  ps.giaTriPhanSo() / dem;
        cout << "\nTrung binh cac phan so dương trong mang là: " << trungBinh;
        return trungBinh;
    }
}



