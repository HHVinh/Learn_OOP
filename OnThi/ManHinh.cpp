#include "ManHinh.h"

ManHinh::ManHinh()
{
    m_doPhanGiai = "1920x1080";
    m_tangSoQuet = 110;
}

ManHinh::~ManHinh()
{

}

void ManHinh::getDeviceType()
{
    cout << "\nMàn hình";
}

void ManHinh::displayInfo()
{   
    ThongTinChung::xuatThongTin();
    cout << "\nĐộ phân giải: " << m_doPhanGiai;
    cout << "\nĐộ tần số quét: " << m_tangSoQuet;
}
