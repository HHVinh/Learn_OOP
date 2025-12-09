#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include "loaiHang.h"
#include "quanLyLoaiHang.h"
#include "Validator.h"

LoaiHang::LoaiHang() 
{

}

LoaiHang::LoaiHang(string maLoai, string tenLoai, string moTa) 
{
	m_maLoai = maLoai;
	m_tenLoai = tenLoai;
	m_moTa = moTa;
}

string LoaiHang::getMaLoai() const 
{
	return m_maLoai;
}

string LoaiHang::getTenLoai() const 
{
	return m_tenLoai;
}

string LoaiHang::getMoTa() const 
{
	return m_moTa;
}

void LoaiHang::setTenLoai(const string& ten) 
{
	m_tenLoai = ten;
}

void LoaiHang::setMoTa(const string& mota) 
{
	m_moTa = mota;
}

bool LoaiHang::nhap() 
{
	QuanLyLoaiHang* ql = QuanLyLoaiHang::getInstance();
	auto& ds = ql->getDanhSach();

	cout << "\n==== NHẬP THÔNG TIN LOẠI HÀNG ====\n";

	m_maLoai = ql->sinhMaLoaiHang();
	cout << "\nMã loại hàng: " << m_maLoai << "\n";

	while (true) 
	{
		cout << "Nhập tên loại hàng hoặc nhập 0 để hủy thao tác: ";
		getline(cin, m_tenLoai);
		
		if (m_tenLoai == "0") 
		{
			cout << "\nĐã hủy nhập loại hàng!\n";
			return false;
		}

		if (isEmpty(m_tenLoai))
			cout << "\nTên loại không được để trống!\n";
		else
			break;
	}

	cout << "Mô tả (Có thể bỏ trống): ";
	getline(cin, m_moTa);
	return true;
}

void LoaiHang::xuatDuLieu() const 
{
	const int wMa = 8;
	const int wTen = 40;
	const int wMoTa = 70;

	string ma = m_maLoai;
	string ten = m_tenLoai;
	string mota = m_moTa;

	if (mota.length() > wMoTa - 1)
		mota = mota.substr(0, wMoTa - 4) + "...";

	auto pad = [](int width, int len) 
	{
		return string(max(0, width - len), ' ');
		};

	cout << "   | " << ma << pad(wMa, static_cast<int>(ma.length()))
		 << " | " << ten << pad(wTen, static_cast<int>(ten.length()))
		 << " | " << mota << pad(wMoTa, static_cast<int>(mota.length()))
		 << " |\n";
}


void LoaiHang::inTieuDe() 
{
	const int wMa = 8;
	const int wTen = 40;
	const int wMoTa = 70;

	auto printLine = [&](char c = '-') 
	{
		cout << "   +" << string(wMa + 2, c)
			 << "+" << string(wTen + 2, c)
			 << "+" << string(wMoTa + 2, c)
			 << "+\n";
		};

	printLine();
	cout << "   | Mã loại" << string(wMa - 7, ' ')
		 << " | Tên loại" << string(wTen - 8, ' ')
		 << " | Mô tả" << string(wMoTa - 5, ' ')
		 << " |\n";
	printLine('=');
}
