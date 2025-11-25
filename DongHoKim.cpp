#include "DongHoKim.h"
DongHoKim::DongHoKim()
{
    m_subject = 0;
}

DongHoKim::~DongHoKim()
{

}

DongHoKim::DongHoKim(ThoiGian* t)
{
    m_subject = t;
    m_subject->Attach(this);
}

void DongHoKim::Update()
{
    int hour = m_subject->GetHour();
    cout << "\nĐồng hồ kim: " << hour << " giờ";
}
