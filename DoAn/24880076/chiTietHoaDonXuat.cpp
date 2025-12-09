#include <string>
#include "chiTietHoaDonXuat.h"

ChiTietHoaDonXuat::ChiTietHoaDonXuat() 
{

}

ChiTietHoaDonXuat::ChiTietHoaDonXuat(const string& maHang, int soLuong, double donGia) 
{
	m_maHang = maHang;
	m_soLuong = soLuong;
	m_donGia = donGia;
}

string ChiTietHoaDonXuat::getMaHang() const 
{
	return m_maHang;
}

int ChiTietHoaDonXuat::getSoLuong() const 
{
	return m_soLuong;
}

int ChiTietHoaDonXuat::getDonGia() const 
{
	return m_donGia;
}

int ChiTietHoaDonXuat::thanhTien() const 
{
	return m_soLuong * m_donGia;
}

void ChiTietHoaDonXuat::setMaHang(const string& ma) 
{
	m_maHang = ma;
}

void ChiTietHoaDonXuat::setSoLuong(int sl) 
{
	m_soLuong = sl;
}

void ChiTietHoaDonXuat::setDonGia(double dg) 
{
	m_donGia = dg;
}