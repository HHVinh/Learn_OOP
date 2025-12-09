#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "hoaDonNhap.h"
#include "quanLyLoaiHang.h"
#include "quanLyMatHang.h"
#include "quanLyHoaDonNhap.h"
#include "menu.h"
#include "fileManager.h"
#include "Validator.h"

HoaDonNhap::HoaDonNhap() 
{

}

HoaDonNhap::HoaDonNhap(const string& maHD, string ngayNhap, const string& nhaCungCap) 
{
	m_maHoaDon = maHD;
	m_ngayNhap = ngayNhap;
	m_nhaCungCap = nhaCungCap;
}

string HoaDonNhap::getMaHD() const 
{
	return m_maHoaDon;
}

string HoaDonNhap::getNgayNhap() const 
{
	return m_ngayNhap;
}

string HoaDonNhap::getNhaCungCap() const 
{
	return m_nhaCungCap;
}

vector<ChiTietHoaDonNhap>& HoaDonNhap::getChiTiet() 
{
	return dsChiTiet;
}

const vector<ChiTietHoaDonNhap>& HoaDonNhap::getChiTiet() const 
{
	return dsChiTiet;
}

void HoaDonNhap::setMaHD(const string& maHD) 
{
	m_maHoaDon = maHD;
}

void HoaDonNhap::setNgayNhap(const string& ngayNhap) 
{
	m_ngayNhap = ngayNhap;
}

void HoaDonNhap::setNhaCungCap(const string& nhaCungCap) 
{
	m_nhaCungCap = nhaCungCap;
}

void HoaDonNhap::themChiTietHoaDon(const ChiTietHoaDonNhap& cthd) 
{
	dsChiTiet.push_back(cthd);
}

bool HoaDonNhap::nhapHoaDonNhap_MatHangCoSan() 
{
	QuanLyHoaDonNhap* qlHD = QuanLyHoaDonNhap::getInstance();
	QuanLyMatHang* qlMH = QuanLyMatHang::getInstance();
	auto& dsMH = qlMH->getDanhSach();
	m_maHoaDon = qlHD->sinhMaHoaDonNhap();
	cout << "\nMã hóa đơn: " << m_maHoaDon << "\n";

	do 
	{
		cout << "\nNhập ngày nhập (dd/mm/yyyy): ";
		getline(cin >> ws, m_ngayNhap);

		if (isEmpty(m_ngayNhap)) 
		{
			cout << "\nNgày nhập không được để trống!\n";
			continue;
		}
		if (!isValidDateFormat(m_ngayNhap)) 
		{
			cout << "\nĐịnh dạng ngày không hợp lệ! (dd/mm/yyyy)\n";
			continue;
		}
		if (!isDateNotFuture(m_ngayNhap)) 
		{
			cout << "\nNgày nhập không được lớn hơn ngày hiện tại!\n";
			continue;
		}
		break;
	} while (true);

	while (true) 
	{
		cout << "\nNhập tên nhà cung cấp hoặc nhập 0 để hủy thao tác: ";
		getline(cin >> ws, m_nhaCungCap);

		if (m_nhaCungCap == "0") 
		{
			cout << "\nĐã hủy nhập hóa đơn!\n";
			return false;
		}

		if (isEmpty(m_nhaCungCap)) 
		{
			cout << "\nNhà cung cấp không được để trống!\n";
			continue;
		}

		bool tonTaiNCC = false;
		for (auto& mh : dsMH)
			if (toLowerTrim(mh.getHangSX()) == toLowerTrim(m_nhaCungCap)) 
			{
				tonTaiNCC = true;
				break;
			}

		if (!tonTaiNCC) 
		{
			cout << "\nNhà cung cấp '" << m_nhaCungCap << "Không tồn tại trong hệ thống!\n";
			continue;
		}
		break;
	}

	vector<MatHang> dsNCC;
	for (auto& mh : dsMH)
		if (toLowerTrim(mh.getHangSX()) == toLowerTrim(m_nhaCungCap))
			dsNCC.push_back(mh);

	if (dsNCC.empty()) 
	{
		cout << "\nNhà cung cấp này chưa có mặt hàng nào!\n";
		return false;
	}

	cout << "\nDANH SÁCH MẶT HÀNG CỦA " << toUpper(m_nhaCungCap) << "\n";
	MatHang::inTieuDe();
	for (auto& mh : dsNCC) mh.xuatDuLieu();
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

	printLine('-');
	cout << "\n";
	dsChiTiet.clear();
	bool daNhap = false;
	int stt = 0;

	while (true) 
	{
		cout << "\nNhập chi tiết hàng thứ " << (stt + 1) << ": \n";
		string maHang;
		cout << "\nNhập mã mặt hàng hoặc nhập 0 để hủy thao tác: ";
		getline(cin >> ws, maHang);

		if (maHang == "0") 
		{
			if (!daNhap) 
			{
				string xacNhan;
				do 
				{
					cout << "\nHóa đơn nhập phải có ít nhất 1 mặt hàng!\n";
					cout << "\nBạn có muốn hủy hóa đơn này không? (y/n): ";
					getline(cin >> ws, xacNhan);

					if (xacNhan == "y" || xacNhan == "Y") 
					{
						cout << "\nĐã hủy toàn bộ hóa đơn!\n";
						return false;
					}
					else if (xacNhan == "n" || xacNhan == "N") 
					{
						cout << "\nTiếp tục nhập hóa đơn!\n";
						break;
					}
					else 
					{
						cout << "\nChỉ được nhập 'y' hoặc 'n'! Vui lòng nhập lại!\n";
					}
				} while (true);
				continue;
			}
			break;
		}

		auto it = find_if(dsNCC.begin(), dsNCC.end(),
			[&](const MatHang& m) 
			{ return m.getMa() == maHang; });

		if (it == dsNCC.end()) 
		{
			cout << "\nMã mặt hàng không tồn tại hoặc không thuộc nhà cung cấp này!\n";
			continue;
		}

		string ngaySanXuat;
		do 
		{
			cout << "\nNhập ngày sản xuất (dd/mm/yyyy): ";
			getline(cin >> ws, ngaySanXuat);

			if (!isValidDateFormat(ngaySanXuat)) 
			{
				cout << "\nSai định dạng!\n";
				continue;
			}
			if (!isDateLessOrEqual(ngaySanXuat, m_ngayNhap)) 
			{
				cout << "\nNgày sản xuất phải nhỏ hơn hoặc bằng ngày nhập hàng!\n";
				continue;
			}
			break;

		} while (true);
		int soLuong;
		do 
		{
			soLuong = safeInputInt("\nNhập số lượng nhập: ");
			if (soLuong <= 0)
				cout << "\nSố lượng phải > 0!\n";
		} while (soLuong <= 0);

		int donGia;
		do 
		{
			donGia = safeInputInt("\nNhập đơn giá nhập: ");
			if (donGia < 1000)
				cout << "\nĐơn giá phải >= 1000!\n";
		} while (donGia < 1000);

		dsChiTiet.push_back(
			ChiTietHoaDonNhap(maHang, ngaySanXuat, soLuong, donGia)
		);

		daNhap = true;
		stt++;

		cout << "\nĐã thêm mặt hàng: " << maHang
			<< " | SL: " << soLuong
			<< " | ĐG: " << donGia
			<< " | NSX: " << ngaySanXuat << "\n";
	}

	cout << "\nHoàn tất nhập hóa đơn!\n";
	return true;
}

bool HoaDonNhap::nhapHoaDonNhap_MatHangMoi() 
{
	QuanLyHoaDonNhap* qlHD = QuanLyHoaDonNhap::getInstance();
	QuanLyMatHang* qlMH = QuanLyMatHang::getInstance();
	auto& dsMH = qlMH->getDanhSach();

	m_maHoaDon = qlHD->sinhMaHoaDonNhap();
	cout << "\nMã hóa đơn: " << m_maHoaDon << "\n";

	do 
	{
		cout << "\nNhập ngày nhập (dd/mm/yyyy): ";
		getline(cin >> ws, m_ngayNhap);
		if (!isValidDateFormat(m_ngayNhap) || !isDateNotFuture(m_ngayNhap))
		{
			cout << "\nNgày nhập không hợp lệ!\n";
		}
	} while (!isValidDateFormat(m_ngayNhap) || !isDateNotFuture(m_ngayNhap));

	while (true) 
	{
		cout << "\nNhập tên nhà cung cấp hoặc nhập 0 để hủy thao tác: ";
		getline(cin >> ws, m_nhaCungCap);

		if (m_nhaCungCap == "0") return false;
		if (isEmpty(m_nhaCungCap)) 
		{
			cout << "\nKhông được để trống!\n";
			continue;
		}

		bool found = false;
		for (auto& mh : dsMH)
			if (toLowerTrim(mh.getHangSX()) == toLowerTrim(m_nhaCungCap))
				found = true;

		if (!found) 
		{
			cout << "\nNhà cung cấp không tồn tại trong hệ thống!\n";
			continue;
		}
		break;
	}

	vector<MatHang> dsNCC;
	for (auto& mh : dsMH)
		if (toLowerTrim(mh.getHangSX()) == toLowerTrim(m_nhaCungCap))
			dsNCC.push_back(mh);

	cout << "\n==== DANH SÁCH MẶT HÀNG ĐÃ CÓ ====\n";
	if (!dsNCC.empty()) 
	{
		MatHang::inTieuDe();
		for (auto& mh : dsNCC) mh.xuatDuLieu();
		cout << "   ------------------------------------------------------------------------------------------------------\n";
	}
	else 
	{
		cout << "\nNhà cung cấp chưa có mặt hàng nào!\n";
	}

	dsChiTiet.clear();
	bool daNhapMoi = false;

	while (true) 
	{
		cout << "\n==== NHẬP MẶT HÀNG MỚI ====\n";

		string maMoi = qlMH->sinhMaMatHang();
		cout << "\nMã mặt hàng mới: " << maMoi << "\n";

		string tenMH;
		cout << "\nNhập tên mặt hàng mới hoặc nhập 0 để hủy thao tác: ";
		getline(cin >> ws, tenMH);

		if (tenMH == "0") 
		{
			if (!daNhapMoi) 
			{
				string x;
				cout << "\nChưa có mặt hàng nào!\n";
				while (true) 
				{
					cout << "\nBạn có chắc muốn hủy hóa đơn? (y/n): ";
					getline(cin >> ws, x);

					if (x == "y" || x == "Y") return false;
					if (x == "n" || x == "N") break;
					cout << "\nChỉ được nhập y hoặc n!\n";
				}
				continue;
			}
			break;
		}

		if (isEmpty(tenMH)) 
		{
			cout << "\nKhông được để trống!\n";
			continue;
		}

		MatHang mhMoi;
		mhMoi.setMa(maMoi);
		mhMoi.setTen(tenMH);
		mhMoi.setHangSX(m_nhaCungCap);

		if (!mhMoi.nhapMatHangTheoNCC(m_nhaCungCap)) continue;
		qlMH->themMatHang(mhMoi);
		string ngaySX;
		int sl, gia;

		while (true) 
		{
			cout << "\nNgày sản xuất (dd/mm/yyyy): ";
			getline(cin >> ws, ngaySX);

			if (!isValidDateFormat(ngaySX)) 
			{ 
				cout << "\nSai định dạng!\n"; continue; 
			}
			if (!isDateLessOrEqual(ngaySX, m_ngayNhap)) 
			{ 
				cout << "\nNgày sản xuất > ngày nhập!\n"; continue; 
			}
			break;
		}

		do 
		{
			sl = safeInputInt("\nSố lượng nhập: ");
		} while (sl <= 0);
		do 
		{
			gia = safeInputInt("\nĐơn giá nhập: ");
		} while (gia < 1000);

		dsChiTiet.push_back(ChiTietHoaDonNhap(maMoi, ngaySX, sl, gia));
		daNhapMoi = true;

		cout << "\nĐã thêm mặt hàng mới!\n";
	}

	if (!dsNCC.empty()) 
	{
		while (true) 
		{
			string ch;
			cout << "\nBạn có muốn thêm mặt hàng cũ không? (y/n): ";
			getline(cin >> ws, ch);
			if (ch == "n" || ch == "N") break;
			if (ch != "y" && ch != "Y") 
			{
				cout << "y/n!\n";
				continue;
			}

			string ma;
			cout << "\nNhập mã mặt hàng cũ: ";
			getline(cin >> ws, ma);

			auto it = find_if(dsNCC.begin(), dsNCC.end(),
				[&](const MatHang& mh) 
				{ return mh.getMa() == ma; });

			if (it == dsNCC.end()) 
			{
				cout << "\nKhông tồn tại!\n";
				continue;
			}

			string ngaySX;
			int sl, gia;

			while (true) 
			{
				cout << "\nNgày sản xuất (dd/mm/yyyy): ";
				getline(cin >> ws, ngaySX);

				if (!isValidDateFormat(ngaySX)) 
				{ cout << "\nSai định dạng!\n"; continue; }
				if (!isDateLessOrEqual(ngaySX, m_ngayNhap)) 
				{ cout << "\nNgày sản xuất > ngày nhập!\n"; continue; }

				break;
			}

			do 
			{
				sl = safeInputInt("\nSố lượng nhập: ");
			} while (sl <= 0);

			do 
			{
				gia = safeInputInt("\nĐơn giá nhập: ");
			} while (gia < 1000);

			dsChiTiet.push_back(ChiTietHoaDonNhap(ma, ngaySX, sl, gia));

			cout << "\nThêm hàng cũ thành công!\n";
		}
	}
	return true;
}

bool HoaDonNhap::nhapHoaDonNhap_NhaCungCapMoi() 
{
	QuanLyHoaDonNhap* qlHD = QuanLyHoaDonNhap::getInstance();
	QuanLyMatHang* qlMH = QuanLyMatHang::getInstance();
	m_maHoaDon = qlHD->sinhMaHoaDonNhap();
	cout << "\nMã hóa đơn: " << m_maHoaDon << "\n";

	do 
	{
		cout << "\nNhập ngày nhập (dd/mm/yyyy): ";
		getline(cin >> ws, m_ngayNhap);
		if (!isValidDateFormat(m_ngayNhap) || !isDateNotFuture(m_ngayNhap))
		{
			cout << "\nNgày nhập không hợp lệ!\n";
		}
	} 
	while (!isValidDateFormat(m_ngayNhap) || !isDateNotFuture(m_ngayNhap));
	do 
	{
		cout << "\nNhập tên nhà cung cấp mới: ";
		getline(cin >> ws, m_nhaCungCap);
		if (isEmpty(m_nhaCungCap))
			cout << "\nKhông được để trống!\n";
	} while (isEmpty(m_nhaCungCap));

	dsChiTiet.clear();
	bool daNhap = false;
	int stt = 0;

	while (true) 
	{
		cout << "\nThêm mặt hàng mới cho nhà cung cấp "
			<< toUpper(m_nhaCungCap) << "\n";

		string maMH = qlMH->sinhMaMatHang();
		cout << "\nMã mặt hàng mới: " << maMH << "\n";

		string tenMH;
		cout << "\nNhập tên mặt hàng mới hoặc nhập 0 để hủy thao tác: ";
		getline(cin >> ws, tenMH);

		if (tenMH == "0") 
		{
			if (!daNhap) return false;
			break;
		}

		if (isEmpty(tenMH)) 
		{
			cout << "\nTên mặt hàng không được để trống!\n";
			continue;
		}

		MatHang mhMoi;
		mhMoi.setMa(maMH);
		mhMoi.setTen(tenMH);
		mhMoi.setHangSX(m_nhaCungCap);

		if (!mhMoi.nhapMatHangTheoNCC(m_nhaCungCap)) 
		{
			if (dsChiTiet.empty()) return false;
			continue;
		}

		qlMH->themMatHang(mhMoi);
		int soLuong, donGia;
		string ngaySX;

		do 
		{
			soLuong = safeInputInt("\nNhập số lượng nhập: ");
			if (soLuong <= 0)
				cout << "\nSố lượng phải > 0!\n";
		} while (soLuong <= 0);

		do 
		{
			cout << "\nNhập ngày sản xuất (dd/mm/yyyy): ";
			getline(cin >> ws, ngaySX);

			if (!isValidDateFormat(ngaySX)) 
			{
				cout << "\nSai định dạng!\n";
				continue;
			}

			if (!isDateLessOrEqual(ngaySX, m_ngayNhap)) 
			{
				cout << "\nNgày sản xuất phải <= ngày nhập!\n";
				continue;
			}

			break;

		} while (true);

		do 
		{
			donGia = safeInputInt("\nNhập đơn giá nhập: ");
			if (donGia < 1000)
				cout << "\nĐơn giá >= 1000!\n";
		} while (donGia < 1000);

		dsChiTiet.push_back(ChiTietHoaDonNhap(maMH, ngaySX, soLuong, donGia));
		daNhap = true;
		stt++;

		cout << "\nThêm mặt hàng vào hóa đơn thành công!\n";
	}
	return true;
}

int HoaDonNhap::tongTien() const 
{
	int tong = 0;
	for (auto& ct : dsChiTiet) 
	{
		tong += ct.thanhTien();
	}
	return tong;
}

void HoaDonNhap::xuatDuLieu() const 
{
	const int wMa = 10;
	const int wNgay = 12;
	const int wNCC = 32;
	const int wTong = 16;
	int tong = 0;
	for (auto& ct : dsChiTiet)
		tong += ct.thanhTien();

	auto printLine = [&](char c = '-') 
	{
		cout << "   +" << string(wMa + 2, c)
			<< "+" << string(wNgay + 2, c)
			<< "+" << string(wNCC + 2, c)
			<< "+" << string(wTong + 2, c)
			<< "+\n";
		};

	string ncc = m_nhaCungCap;
	cout << "   | " << left << setw(wMa) << m_maHoaDon
		<< " |  " << setw(wNgay) << m_ngayNhap
		<< "| " << setw(wNCC) << ncc
		<< " | " << string(wTong - to_string((int)tong).length(), ' ')
		<< fixed << setprecision(0) << tong
		<< " |\n";

	const int wMaCT = 8, wNSX = 12, wSL = 10, wDG = 15, wTT = 15;

	cout << "   |            +--------------------------------------------------------------------+\n";
	cout << "   |            |  " << left << setw(wMaCT) << "Mã hàng"
		<< " | " << setw(wNSX - 2) << left << "Ngày Sản Xuất"
		<< " |  " << setw(wSL) << "Số lượng"
		<< "  |   " << setw(wDG - 2) << "Đơn giá"
		<< "|  " << setw(wTT) << "Thành tiền"
		<< "|\n";
	cout << "   |             --------------------------------------------------------------------\n";

	for (auto& ct : dsChiTiet) 
	{
		cout << "   |            |  " << setw(wMaCT) << left << ct.getMaHang()
			<< "|  " << setw(wNSX) << left << ct.getNgaySanXuat()
			<< " | " << setw(wSL) << right << ct.getSoLuong()
			<< " | " << setw(wDG - 4) << right << ct.getDonGia()
			<< " | " << setw(wTT - 3) << right << ct.thanhTien()
			<< " |\n";
	}
	printLine('-');
	cout << endl;

}

void HoaDonNhap::inTieuDe() 
{
	const int wMa = 10;
	const int wNgay = 12;
	const int wNCC = 32;
	const int wTong = 16;

	auto printLine = [&](char c = '-') 
	{
		cout << "   +" << string(wMa + 2, c)
			<< "+" << string(wNgay + 2, c)
			<< "+" << string(wNCC + 2, c)
			<< "+" << string(wTong + 2, c)
			<< "+\n";
		};

	printLine();
	cout << "   | " << left << setw(wMa) << "Mã Hóa đơn"
		<< " |  " << setw(wNgay) << "Ngày nhập"
		<< "   |            " << setw(wNCC - 8) << "Nhà cung cấp"
		<< " |    " << setw(wTong - 4) << "Tổng tiền"
		<< "     |\n";
	printLine('-');
}