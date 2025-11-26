#include "Tivi.h"

Tivi::Tivi()
{
    m_kichThuoc = 52;
    m_heDieuHanh = "Android TV";
    m_kenhHienTai = 1;
}

Tivi::~Tivi()
{

}

void Tivi::getDeviceType()
{
    cout << "\nTi vi";
}

void Tivi::displayInfo()
{   
    ThongTinChung::xuatThongTin();
    cout << "\nKích thước: " << m_kichThuoc;
    cout << "\nHệ điều hành: " << m_heDieuHanh;
    cout << "\nKênh hiện tại: " << m_kenhHienTai;
}
