#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "matHang.h"
#include "quanLyMatHang.h"
#include "quanLyLoaiHang.h"
#include "Validator.h"

MatHang::MatHang() 
{

}

MatHang::MatHang(string ma, string tenHang, string hanSuDung, string congTySanXuat, string loai) 
{
	m_ma = ma;
	m_tenHang = tenHang;
	m_hanSuDung = hanSuDung;
	m_congTySanXuat = congTySanXuat;
	m_loai = loai;
}

string MatHang::getMa() const 
{
	return m_ma;
}

string MatHang::getTen() const 
{
	return m_tenHang;
}

string MatHang::getHangSX() const 
{
	return m_congTySanXuat;
}

string MatHang::getHanSD() const 
{
	return m_hanSuDung;
}

string MatHang::getLoai() const 
{
	return m_loai;
}

void MatHang::setMa(const string& maMoi) 
{
	m_ma = maMoi;
}

void MatHang::setTen(const string& tenHangMoi) 
{
	m_tenHang = tenHangMoi;
}

void MatHang::setHangSX(const string& congTySanXuatMoi) 
{
	m_congTySanXuat = congTySanXuatMoi;
}

void MatHang::setHanSD(const string& hanSuDungMoi) 
{
	m_hanSuDung = hanSuDungMoi;
}

void MatHang::setLoai(const string& loaiMoi) 
{
	m_loai = loaiMoi;
}

bool MatHang::nhap() 
{
	QuanLyMatHang* ql = QuanLyMatHang::getInstance();
	auto& dsMH = ql->getDanhSach();
	QuanLyLoaiHang* qlLH = QuanLyLoaiHang::getInstance();
	auto& dsLoai = qlLH->getDanhSach();

	if (dsLoai.empty()) 
	{
		cout << "\nChưa có loại hàng nào trong hệ thống. Hãy thêm loại hàng trước!\n";
		return false;
	}

	cout << "\n==== NHẬP THÔNG TIN MĂT HÀNG ====\n";
	
	m_ma = ql->sinhMaMatHang();
	cout << "\nMã mặt hàng: " << m_ma << "\n";

	while (true) 
	{
		cout << "\nNhập tên mặt hàng hoặc nhập 0 để hủy thao tác: ";
		getline(cin, m_tenHang);

		if (m_tenHang == "0") 
		{
			cout << "\nĐã hủy nhập mặt hàng!\n";
			return false;
		}

		if (isEmpty(m_tenHang))
		{
			cout << "\nTên mặt hàng không được để trống!\n";
		}
		else
		{
			break;
		}
	}

	do 
	{
		cout << "\nNhập hãng sản xuất: ";
		getline(cin, m_congTySanXuat);

		if (isEmpty(m_congTySanXuat))
			cout << "\nCông ty sản xuất không được để trống!\n";
		else
			break;
	} while (true);

	do 
	{
		string input;
		cout << "\nThời hạn sử dụng (ví dụ: 10 ngay, 7 tuan, 3 thang, 1 nam, ...).\n";
		cout <<	"\nNhập thời hạn sử dụng: ";
		getline(cin >> ws, input);

		transform(input.begin(), input.end(), input.begin(), ::tolower);
		input.erase(0, input.find_first_not_of(" \t"));
		input.erase(input.find_last_not_of(" \t") + 1);

		if (input.empty()) 
		{
			cout << "\nHạn sử dụng không được để trống!\n";
			continue;
		}

		string soPhan = "";
		string donViPhan = "";

		for (char c : input) 
		{
			if (isdigit(c))
				soPhan += c;
			else if (!isspace(c))
				donViPhan += c;
		}

		if (soPhan.empty()) 
		{
			stringstream ss(input);
			ss >> soPhan >> donViPhan;
		}

		if (soPhan.empty() || donViPhan.empty()) 
		{
			cout << "\nĐịnh dạng không hợp lệ! Vui lòng nhập như: 10 ngay, 7 tuan, 3 thang, 1 nam, ..!\n";
			continue;
		}

		int soLuong = stoi(soPhan);
		if (soLuong <= 0) 
		{
			cout << "\nThời lượng phải lớn hơn 0!\n";
			continue;
		}

		vector<string> hopLe = 
		{ "ngay", "thang", "nam", "tuan" };
		bool ok = false;
		for (auto& u : hopLe) 
		{
			if (donViPhan == u) 
			{
				ok = true;
				break;
			}
		}

		if (!ok) 
		{
			cout << "\nĐơn vị không hợp lệ! Chỉ chấp nhận: ngay, tuan, thang, nam!\n";
			continue;
		}

		m_hanSuDung = to_string(soLuong) + " " + donViPhan;
		break;

	} while (true);

	do 
	{
		cout << "\nNhập mã loại hàng: ";
		getline(cin >> ws, m_loai);

		bool tonTai = false;
		for (auto& lh : dsLoai) 
		{
			if (lh.getMaLoai() == m_loai) 
			{
				tonTai = true;
				break;
			}
		}

		if (!tonTai)
			cout << "\nMã loại hàng không tồn tại trong danh sách!\n";
		else
			break;
	} while (true);

	return true;
}

bool MatHang::nhapMatHangTheoNCC(const std::string& nhaCungCap) 
{
	QuanLyLoaiHang* qlLH = QuanLyLoaiHang::getInstance();
	auto& dsLoai = qlLH->getDanhSach();
	m_congTySanXuat = nhaCungCap;

	do 
	{
		string input;
		cout << "\nThời hạn sử dụng (ví dụ: 10 ngay, 7 tuan, 3 thang, 1 nam, ...).\n";
		cout <<	"\nNhập thời hạn sử dụng: ";
		getline(cin >> ws, input);

		transform(input.begin(), input.end(), input.begin(), ::tolower);
		input.erase(0, input.find_first_not_of(" \t"));
		input.erase(input.find_last_not_of(" \t") + 1);

		if (input.empty()) 
		{
			cout << "\nHạn sử dụng không được để trống!\n";
			continue;
		}

		string soPhan = "";
		string donViPhan = "";

		for (char c : input) 
		{
			if (isdigit(c))
				soPhan += c;
			else if (!isspace(c))
				donViPhan += c;
		}

		if (soPhan.empty()) 
		{
			stringstream ss(input);
			ss >> soPhan >> donViPhan;
		}

		if (soPhan.empty() || donViPhan.empty()) 
		{
			cout << "\nĐịnh dạng không hợp lệ! Vui lòng nhập như: 10 ngay, 7 tuan, 3 thang, 1 nam, ..!\n";
			continue;
		}

		int soLuong = stoi(soPhan);
		if (soLuong <= 0) 
		{
			cout << "\nThời lượng phải lớn hơn 0!\n";
			continue;
		}

		vector<string> hopLe = 
		{ "ngay", "thang", "nam", "tuan" };
		bool ok = false;
		for (auto& u : hopLe) 
		{
			if (donViPhan == u) 
			{
				ok = true;
				break;
			}
		}

		if (!ok) 
		{
			cout << "\nĐơn vị không hợp lệ! Chỉ chấp nhận: ngay, tuan, thang, nam!\n";
			continue;
		}

		m_hanSuDung = to_string(soLuong) + " " + donViPhan;
		break;

	} while (true);

	do 
	{
		cout << "\nNhập mã loại hàng: ";
		getline(cin >> ws, m_loai);

		bool tonTai = false;
		for (auto& lh : dsLoai) 
		{
			if (lh.getMaLoai() == m_loai) 
			{
				tonTai = true;
				break;
			}
		}

		if (!tonTai)
			cout << "\nMã loại hàng không tồn tại trong danh sách!\n";
		else
			break;
	} while (true);

	return true;

}

void MatHang::inTieuDe() 
{
	const int wMa = 6, wTen = 35, wHangSX = 25, wHanSD = 12, wLoai = 8;

	auto printLine = [&](char c = '-') 
	{
		cout << "   +" << string(wMa + 2, c)
			<< "+" << string(wTen + 2, c)
			<< "+" << string(wHangSX + 2, c)
			<< "+" << string(wHanSD + 2, c)
			<< "+" << string(wLoai + 2, c)
			<< "+\n";
		};

	printLine();
	cout << left
		<< "   | Mã MH" << string(wMa - 5, ' ')
		<< " |           Tên mặt hàng " << string(wTen - 23, ' ')
		<< " |       Hãng sản xuất " << string(wHangSX - 20, ' ')
		<< " | Hạn Sử Dụng " << string(wHanSD - 12, ' ')
		<< " | Mã Loại " << string(wLoai - 8, ' ')
		<< " |\n";
	printLine('=');
}

void MatHang::xuatDuLieu() const 
{
	const int wMa = 6, wTen = 35, wHangSX = 25, wHanSD = 12, wLoai = 7;

	auto pad = [](int width, int len) 
	{
		return string(max(0, width - len), ' ');
		};

	cout << "   | " << left << setw(wMa) << m_ma
		<< " | " << setw(wTen) << m_tenHang
		<< " | " << setw(wHangSX) << m_congTySanXuat
		<< " | " << setw(wHanSD) << m_hanSuDung
		<< " |  " << setw(wLoai) << m_loai
		<< " |\n";
}
