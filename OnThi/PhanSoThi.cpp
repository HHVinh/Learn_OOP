#include "PhanSoThi.h"

PhanSoThi::PhanSoThi()
{
    m_tuSo = 0;
    m_mauSo = 1;
}

PhanSoThi::~PhanSoThi()
{

}

void PhanSoThi::NhapPhanSo()
{
    int tuSo, mauSo;
    cout << "\nNhap tu so: ";
    cin >> tuSo;

    cout << "Nhap mau so: ";
    cin >> mauSo;

    while (mauSo == 0) {
        cout << "Mau so phai khac 0!";
        cout << "Nhap lai mau so: ";
        cin >> mauSo;
    }

    m_tuSo = tuSo;
    m_mauSo = mauSo;
}

void PhanSoThi::InPhanSo()
{
    cout << "\n" << m_tuSo << "/" << m_mauSo;
}

PhanSoThi PhanSoThi::operator+(const PhanSoThi& b)
{
    PhanSoThi kq;
    kq.m_tuSo = m_tuSo * b.m_mauSo + m_mauSo * b.m_tuSo;
    kq.m_mauSo = m_mauSo * b.m_mauSo;

    return kq;
}

double PhanSoThi::giaTriPhanSo() const
{
    return (m_tuSo * 1.0) / (m_mauSo * 1.0);
}

bool PhanSoThi::phanSoDuong() const
{
    return (m_tuSo >= 0 && m_mauSo > 0) || (m_tuSo <= 0 && m_mauSo < 0);
}

void PhanSoThi::soSanh(int k)
{
    double giaTri = giaTriPhanSo();

    if (giaTri > k)
    {
        cout << "\n\nPhân số ";
        InPhanSo();
        cout << " > " << k;
    }
    else if (giaTri < k)
    {
        cout << "\n\nPhân số ";
        InPhanSo();
        cout << " < " << k;
    }
    else
    {
        cout << "\n\nPhân số ";
        InPhanSo();
        cout << " = " << k;
    }
}
