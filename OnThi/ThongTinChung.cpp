#include "ThongTinChung.h"

ThongTinChung::ThongTinChung()
{
    m_tenThietBi = "";
    m_maThietBi = "";
    m_trangThai = "";
}

ThongTinChung::~ThongTinChung()
{

}

void ThongTinChung::xuatThongTin()
{
    cout << "\nTên: " << m_tenThietBi;
    cout << "\nMã: " << m_maThietBi;
    cout << "\nTrạng thái: " << m_trangThai;
}

void ThongTinChung::setTenThietBi(const string& ten)
{
    m_tenThietBi = ten;
}

void ThongTinChung::setMaThietBi(const string& ma)
{
    m_maThietBi = ma;
}

void ThongTinChung::setTrangThai(const string& trangThai)
{
    m_trangThai = trangThai;
}

string ThongTinChung::getTenThietBi() const
{
    return m_tenThietBi;
}

string ThongTinChung::getMaThietBi() const
{
    return m_maThietBi;
}

string ThongTinChung::getTrangThai() const
{
    return m_trangThai;
}

int ThongTinChung::turnOn() {
    m_trangThai = "Bat";
    return 1;
}

int ThongTinChung::turnOff() {
    m_trangThai = "Tat";
    return 0;
}

void ThongTinChung::disPlayContent(const string& content) {
    cout << "\nMàn hình '" << m_tenThietBi << "' đang hiển thị: '" << content << "'";
}

