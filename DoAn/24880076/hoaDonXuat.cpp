#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "hoaDonXuat.h"
#include "quanLyLoaiHang.h"
#include "quanLyMatHang.h"
#include "quanLyHoaDonXuat.h"
#include "fileManager.h"
#include "Validator.h"

HoaDonXuat::HoaDonXuat() 
{

}

HoaDonXuat::HoaDonXuat(const string& maHD, const string& ngayXuat, const string& khachHang) 
{
	m_maHoaDon = maHD;
	m_ngayXuat = ngayXuat;
	m_khachHang = khachHang;
}

string HoaDonXuat::getMaHD() const 
{ 
	return m_maHoaDon; 
}

string HoaDonXuat::getNgayXuat() const 
{ 
	return m_ngayXuat; 
}

string HoaDonXuat::getKhachHang() const 
{ 
	return m_khachHang; 
}

vector<ChiTietHoaDonXuat>& HoaDonXuat::getChiTiet() 
{
	return dsChiTiet;
}

const vector<ChiTietHoaDonXuat>& HoaDonXuat::getChiTiet() const 
{
	return dsChiTiet;
}

void HoaDonXuat::themChiTietHoaDon(const ChiTietHoaDonXuat& cthd) 
{
	dsChiTiet.push_back(cthd);
}

int HoaDonXuat::tongTien() const 
{
	int tong = 0;
	for (const auto& ct : dsChiTiet)
	{
		tong += ct.thanhTien();
	}
	return tong;
}

void HoaDonXuat::setMaHD(const string& maHD) 
{
	m_maHoaDon = maHD; 
}

void HoaDonXuat::setNgayXuat(const string& ngayXuat) 
{
	m_ngayXuat = ngayXuat; 
}

void HoaDonXuat::setKhachHang(const string& khachHang) 
{
	m_khachHang = khachHang; 
}

bool HoaDonXuat::nhapHoaDonXuat() 
{
	QuanLyMatHang* qlMH = QuanLyMatHang::getInstance();
	auto& dsMH = qlMH->getDanhSach();
	cout << "\n==== NHẬP HÓA ĐƠN XUẤT ====\n";
	QuanLyHoaDonXuat* qlHDX = QuanLyHoaDonXuat::getInstance();
	m_maHoaDon = qlHDX->sinhMaHoaDonXuat();
	cout << "\nMã hóa đơn: " << m_maHoaDon << "\n";

	do 
	{
		cout << "\nNhập ngày xuất hóa đơn (dd/mm/yyyy): ";
		getline(cin >> ws, m_ngayXuat);
		if (!isValidDateFormat(m_ngayXuat))
			cout << "\nNgày xuất hóa đơn không hợp lệ!\n";
		else if (!isDateNotFuture(m_ngayXuat))
			cout << "\nNgày xuất hóa đơn không được lớn hơn ngày hiện tại!\n";
		else break;
	} while (true);

	do 
	{
		cout << "\nTên khách hàng: ";
		getline(cin >> ws, m_khachHang);
		if (isEmpty(m_khachHang))
			cout << "\nTên khách hàng không được để trống!\n";
		else break;
	} while (true);

	dsChiTiet.clear();
	vector<vector<string>> dsKho;
	FileManager::getInstance()->docKho(dsKho);

	while (true) 
	{
		string maHang;

		cout << "\nNhập mã mặt hàng: ";
		getline(cin >> ws, maHang);

		if (maHang == "0") break;

		if (isEmpty(maHang)) 
		{
			cout << "\nMã mặt hàng không được để trống!\n";
			continue;
		}

		if (!isValidFormatMaMatHang(maHang)) 
		{
			cout << "\nMã mặt hàng phải có dạng MHxxx (Ví dụ: MH001, MH002) hoặc nhập 0 để hủy thao tác!\n";
			continue;
		}

		auto it = find_if(dsMH.begin(), dsMH.end(),
			[&](const MatHang& m) 
			{ return m.getMa() == maHang; });

		if (it == dsMH.end()) 
		{
			cout << "\nMã mặt hàng này không tồn tại trong hệ thống!\n";
			continue;
		}

		vector<vector<string>> loTon;
		int tongTon = 0;
		for (auto& dong : dsKho) 
		{
			if (dong.size() >= 8 && dong[0] == maHang && stoi(dong[5]) > 0) 
			{
				loTon.push_back(dong);
				tongTon += stoi(dong[5]);
			}
		}

		if (loTon.empty()) 
		{
			cout << "\nMặt hàng này hiện đã hết tồn trong kho!\n";
			continue;
		}

		string tenMH = "Unknown";
		for (auto& mh : dsMH) 
		{
			if (mh.getMa() == maHang) 
			{
				tenMH = mh.getTen();
				break;
			}
		}

		int tongTonKho = 0;
		for (auto& dong : loTon) 
		{
			try 
			{ tongTonKho += stoi(dong[5]); }
			catch (...) 
			{}
		}

		cout << "\n==== THÔNG TIN TỒN KHO MẶT HÀNG ====\n";
		cout << "   Mã hàng        : " << maHang << "\n";
		cout << "   Tên mặt hàng   : " << tenMH << "\n";
		cout << "   Tổng tồn kho   : " << tongTonKho << " sản phẩm\n";
		
		int soLuongXuat;
		while (true) 
		{
			cout << "\nNhập số lượng xuất: ";
			string slStr;
			getline(cin >> ws, slStr);

			if (slStr.empty()) 
			{
				cout << "\nKhông được để trống!\n";
				continue;
			}

			if (!all_of(slStr.begin(), slStr.end(), ::isdigit)) 
			{
				cout << "\nChỉ được nhập số nguyên dương!\n";
				continue;
			}

			soLuongXuat = stoi(slStr);
			if (soLuongXuat <= 0) 
			{
				cout << "\nSố lượng phải lớn hơn 0!\n";
				continue;
			}

			if (soLuongXuat > tongTon) 
			{
				cout << "\nSố lượng vượt quá tồn kho!\n";
				continue;
			}

			break;
		}

		int canLay = soLuongXuat;
		long long tongGiaTri = 0;
		int tongLay = 0;

		for (auto& dong : loTon) 
		{
			if (canLay <= 0) break;
			int soTon = stoi(dong[5]);
			int giaNhap = stoi(dong[7]);

			int lay = min(canLay, soTon);
			tongGiaTri += (long long)lay * giaNhap;
			tongLay += lay;
			canLay -= lay;
		}

		int giaNhapBinhQuan = (tongLay > 0) ? (int)(tongGiaTri / tongLay) : 0;
		cout << "\nGiá nhập trung bình: " << giaNhapBinhQuan << " VNĐ\n";

		int dg;
		do 
		{
			dg = safeInputInt("\nNhập đơn giá xuất (VNĐ): ");
			if (dg < giaNhapBinhQuan)
				cout << "\nĐơn giá xuất phải lớn hơn hoặc bằng giá nhập trung bình!\n";
			else break;
		} while (true);

		dsChiTiet.push_back(ChiTietHoaDonXuat(maHang, soLuongXuat, dg));
		cout << "\nĐã thêm " << maHang << " vào hóa đơn!\n";

		string tiep;
		cout << "\nTiếp tục thêm mặt hàng khác? (y/n): ";
		getline(cin >> ws, tiep);
		if (tiep != "y" && tiep != "Y")
			break;
	}

	if (dsChiTiet.empty()) 
	{
		cout << "\nHóa đơn xuất phải có ít nhất 1 mặt hàng!\n";
		return false;
	}

	cout << "\nHoàn tất nhập hóa đơn xuất!\n";
	return true;
}

void HoaDonXuat::xuatDuLieu() const 
{
	const int wMa = 10, wNgay = 10, wKH = 25, wTong = 12;

	int tong = 0;
	for (auto& ct : dsChiTiet)
		tong += ct.thanhTien();

	auto printLine = [&](char c = '-') 
	{
		cout << "   +" << string(wMa + 2, c)
			<< "+" << string(wNgay + 2, c)
			<< "+" << string(wKH + 2, c)
			<< "+" << string(wTong + 2, c)
			<< "+\n";
		};

	cout << "   |   " << left << setw(wMa - 2) << m_maHoaDon
		<< " | " << setw(wNgay) << m_ngayXuat
		<< " | " << setw(wKH) << m_khachHang
		<< " | " << right << setw(wTong) << (int)tong
		<< " |\n";

	const int wMaCT = 10, wSL = 10, wDG = 15, wTT = 15;
	cout << "   |            +-------------------------------------------------------+\n";
	cout << "   |            |  " << left << setw(wMaCT) << "Mã hàng"
		<< "  |  " << setw(wSL) << "Số lượng"
		<< "  |   " << setw(wDG - 2) << "Đơn giá"
		<< " |  " << setw(wTT) << "Thành tiền"
		<< "|\n";
	cout << "   |             -------------------------------------------------------\n";

	for (const auto& ct : dsChiTiet) 
	{
		cout << "   |            |   " << left << setw(8) << ct.getMaHang()
			<< " | " << right << setw(10) << ct.getSoLuong()
			<< " | " << right << setw(12) << (int)ct.getDonGia()
			<< " | " << right << setw(12) << (int)ct.thanhTien()
			<< " |\n";
	}

	printLine('-');
	cout << endl;
}

void HoaDonXuat::inTieuDe() 
{
	const int wMa = 10, wNgay = 10, wKH = 25, wTong = 12;

	cout << "   +" << string(wMa + 2, '-') << "+" << string(wNgay + 2, '-')
		<< "+" << string(wKH + 2, '-') << "+" << string(wTong + 2, '-') << "+\n";
	
	cout << "   | " << left << setw(wMa) << "Mã Hóa đơn"
		<< " | " << setw(wNgay) << "Ngày xuất"
		<< "  |         " << setw(wKH - 6) << "Khách hàng"
		<< " |  " << setw(wTong) << "Tổng tiền" << "   |\n";

	cout << "   +" << string(wMa + 2, '-') << "+" << string(wNgay + 2, '-')
		<< "+" << string(wKH + 2, '-') << "+" << string(wTong + 2, '-') << "+\n";
}

void HoaDonXuat::xuatChiTietHoaDonSua() const 
{
	const int wMa = 10, wNgay = 10, wKH = 25, wTong = 12;

	int tong = 0;
	for (auto& ct : dsChiTiet)
		tong += ct.thanhTien();

	auto printLine = [&](char c = '-') 
	{
		cout << "   +" << string(wMa + 2, c)
			<< "+" << string(wNgay + 2, c)
			<< "+" << string(wKH + 2, c)
			<< "+" << string(wTong + 2, c)
			<< "+\n";
		};

	cout << "   |   " << left << setw(wMa-2) << m_maHoaDon
		<< " | " << setw(wNgay) << m_ngayXuat
		<< " | " << setw(wKH) << m_khachHang
		<< " | " << right << setw(wTong) << (int)tong
		<< " |\n";

	const int wMaCT = 10, wSL = 10, wDG = 15, wTT = 15;
	cout << "   |            +-------------------------------------------------------+\n";
	cout << "   |            |  " << left << setw(wMaCT) << "Mã hàng"
		<< "  |  " << setw(wSL) << "Số lượng"
		<< "  |   " << setw(wDG - 2) << "Đơn giá"
		<< " |  " << setw(wTT) << "Thành tiền"
		<< "|\n";
	cout << "   |             -------------------------------------------------------\n";

	for (const auto& ct : dsChiTiet) 
	{
		cout << "   |            |   " << left << setw(8) << ct.getMaHang()
			<< " | " << right << setw(10) << ct.getSoLuong()
			<< " | " << right << setw(12) << (int)ct.getDonGia()
			<< " | " << right << setw(12) << (int)ct.thanhTien()
			<< " |\n";
	}

	printLine('-');
	cout << endl;
}