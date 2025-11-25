#include "ThoiGian.h"
ThoiGian::ThoiGian()
{
    m_gio = 0;
    m_phut = 0;
    m_giay = 0;
}

ThoiGian::~ThoiGian()
{

}

void ThoiGian::SetTime(int gio, int phut, int giay)
{
    m_gio = gio;
    m_phut = phut;
    m_giay = giay;
    Notify();
}

int ThoiGian::GetHour()
{
    return m_gio;
}

// THIẾU 2 HÀM:
void ThoiGian::Notify()
{
    // Gọi Notify của lớp cha để thông báo cho tất cả Observer
    Subject::Notify();
}

void ThoiGian::Update()
{
    // Implement này (có thể để trống nếu ThoiGian không cần update)
}