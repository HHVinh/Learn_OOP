#include "HChuNhat.h"
HChuNhat::HChuNhat()
{  
    m_chieuRong = 0;
    m_chieuDai = 0;
}

HChuNhat::~HChuNhat()
{
}

void HChuNhat::themHinh()
{
    int chieuRong, chieuDai;
    cout << "\nNhập chiều rộng: ";
    cin >> chieuRong;
    cout << "\nNhập chiều dài: ";
    cin >> chieuDai;
    
    m_chieuRong = chieuRong;
    m_chieuDai = chieuDai;
}

double HChuNhat::tinhChuVi() const
{
    return (m_chieuDai + m_chieuRong)* 2;
}

double HChuNhat::tinhDienTich() const
{
    return m_chieuDai * m_chieuRong;
}

void HChuNhat::xuatHinh() const
{
    if( m_chieuDai != 0 && m_chieuRong != 0)
    {
        cout << "\nHình chữ nhật dài " << m_chieuDai 
             <<" x rộng "<< m_chieuRong <<", có chu vi "
             << tinhChuVi() <<" và diện tích "<< tinhDienTich();
    }
}