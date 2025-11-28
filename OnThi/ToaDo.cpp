#include "ToaDo.h"
#include <math.h>
ToaDo::ToaDo(/* args */)
{
    m_X = 0;
    m_Y = 0;
}

ToaDo::~ToaDo()
{

}

void ToaDo::NhapToaDo()
{
    int x, y;
    cout << "\nNhap X: ";
    cin >> x;
    cout << "Nhap Y: ";
    cin >> y;

    m_X = x;
    m_Y = y;
}

void ToaDo::InToaDo()
{
    cout << "(" << m_X << ", " << m_Y <<")";
}

double ToaDo::KhoangCach(const ToaDo& b)
{
    double ketQua;

    ketQua = sqrt((b.m_X - m_X) * (b.m_X - m_X) + (b.m_Y - m_Y) * (b.m_Y - m_Y));

    return ketQua;
}

bool ToaDo::DiemToaDo()
{
    return m_X == 0 && m_Y == 0;
}

bool ToaDo::DiemTrucXTrai()
{
    return m_X == 0 && m_Y < 0;
}

bool ToaDo::DiemTrucXPhai()
{
    return m_X == 0 && m_Y > 0;
}

bool ToaDo::DiemTrucYTren()
{
    return m_X > 0 && m_Y == 0;
}

bool ToaDo::DiemTrucYDuoi()
{
    return m_X < 0 && m_Y == 0;
}

bool ToaDo::DiemTrenTrai()
{
    return m_X < 0 && m_Y > 0;
}

bool ToaDo::DiemTrenPhai()
{
    return m_X > 0 && m_Y > 0;
}

bool ToaDo::DiemDuoiTrai()
{
    return m_X < 0 && m_Y < 0;
}

bool ToaDo::DiemDuoiPhai()
{
    return m_X > 0 && m_Y < 0;
}



