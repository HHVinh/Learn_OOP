#include "DongHoDienTu.h"
DongHoDienTu::DongHoDienTu()
{
    m_subject = 0;
}

DongHoDienTu::~DongHoDienTu()
{

}

DongHoDienTu::DongHoDienTu(ThoiGian* t)
{
    m_subject = t;
    m_subject->Attach(this);
}

void DongHoDienTu::Update()
{
    int hour = m_subject->GetHour();
    cout << "\nĐồng hồ điện tử: " << hour << " giờ";
}