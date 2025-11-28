#include "HTron.h"
HTron::HTron()
{  
    m_banKinh = 0;
}

HTron::~HTron()
{
}

void HTron::themHinh()
{
    double bk;
    cout << "\nNhập bán kính: ";
    cin >> bk;
    m_banKinh = bk;
}

double HTron::tinhChuVi() const
{   
    return m_banKinh * 2 * 3.14;
}

double HTron::tinhDienTich() const
{
    return m_banKinh * m_banKinh * 3.14;
}

void HTron::xuatHinh() const
{
    if( m_banKinh != 0)
    {
        cout << "\nHình tròn bán kính "<< m_banKinh
             <<", có chu vi "<< tinhChuVi() 
             <<" và diện tích "<< tinhDienTich();
    }
}

