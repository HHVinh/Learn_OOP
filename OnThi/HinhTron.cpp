#include "HinhTron.h"

HinhTron::HinhTron(/* args */)
{
}

HinhTron::~HinhTron()
{
}

void HinhTron::nhapHinh()
{
    cout << "\nNhap toa do tam: ";
    m_Tam.NhapToaDo();
    cout << "\nNhap ban kinh: ";
    cin >> m_BanKinh;
}

bool HinhTron::hinhYeuCau()
{   
    ToaDo O;
    double doDai;
    doDai = m_Tam.KhoangCach(O);
    return doDai <= m_BanKinh;
}
