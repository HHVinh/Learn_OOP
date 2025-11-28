#include "HVuong.h"
HVuong::HVuong()
{  
    m_chieuDaiCanh = 0;
}

HVuong::~HVuong()
{
}

void HVuong::themHinh()
{
    double chieuDai;
    cout << "\nNhập độ dài cạnh: ";
    cin >> chieuDai;
    m_chieuDaiCanh = chieuDai;
}

double HVuong::tinhChuVi() const
{
    return m_chieuDaiCanh * 4;
}

double HVuong::tinhDienTich() const
{
    return m_chieuDaiCanh * m_chieuDaiCanh;
}

void HVuong::xuatHinh() const
{
    if( m_chieuDaiCanh != 0)
    {
        cout << "\nHình vuông có cạnh dài "
             << m_chieuDaiCanh <<", có chu vi "
             << tinhChuVi() <<" và diện tích "<< tinhDienTich();
    }
}