#include "chiTietHoaDonNhap.h"

ChiTietHoaDonNhap::ChiTietHoaDonNhap() 
{

}

ChiTietHoaDonNhap::ChiTietHoaDonNhap(const string& maHang, const string& ngaySanXuat, int soLuong, double donGia) 
{
	m_maHang = maHang;
	m_ngaySanXuat = ngaySanXuat;
	m_soLuong = soLuong;
	m_donGia = donGia;
}

string ChiTietHoaDonNhap::getMaHang() const 
{
	return m_maHang;
}

string ChiTietHoaDonNhap::getNgaySanXuat() const 
{
	return m_ngaySanXuat;
}

int ChiTietHoaDonNhap::getSoLuong() const 
{
	return m_soLuong;
}

int ChiTietHoaDonNhap::getDonGia() const 
{
	return m_donGia;
}

int ChiTietHoaDonNhap::thanhTien() const 
{
	return m_soLuong * m_donGia;
}

void ChiTietHoaDonNhap::setMaHang(const string& ma) 
{
	m_maHang = ma;
}

void ChiTietHoaDonNhap::setNgaySanXuat(const string& date) 
{
	m_ngaySanXuat = date;
}

void ChiTietHoaDonNhap::setSoLuong(int sl) 
{
	m_soLuong = sl;
}

void ChiTietHoaDonNhap::setDonGia(double dg) 
{
	m_donGia = dg;
}