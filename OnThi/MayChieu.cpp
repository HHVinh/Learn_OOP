#include "MayChieu.h"

MayChieu::MayChieu()
{
    m_doSang = 100;
    m_tiLeChieu = 1.5;
}

MayChieu::~MayChieu()
{

}

void MayChieu::getDeviceType()
{
    cout << "\nMáy chiếu";
}

void MayChieu::displayInfo()
{   
    ThongTinChung::xuatThongTin();
    cout << "\nĐộ sáng: " << m_doSang;
    cout << "\nTỉ lệ chiếu: " << m_tiLeChieu;
}
