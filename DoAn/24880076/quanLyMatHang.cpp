#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "quanLyMatHang.h"
#include "quanLyLoaiHang.h"
#include "Validator.h"

QuanLyMatHang* QuanLyMatHang::instance = nullptr;
QuanLyMatHang::QuanLyMatHang() 
{

}

QuanLyMatHang* QuanLyMatHang::getInstance() 
{
	if (!instance) 
	{
		instance = new QuanLyMatHang();
	}
	return instance;
}

string QuanLyMatHang::sinhMaMatHang() 
{
	int maxNum = 0;
	vector<int> used;
	for (const auto& mh : ds) 
	{
		string ma = mh.getMa();
		if (ma.size() >= 5 && ma.substr(0, 2) == "MH") 
		{
			int num = stoi(ma.substr(2));
			used.push_back(num);
			if (num > maxNum) 
			{
				maxNum = num;
			}
		}
	}

	sort(used.begin(), used.end());
	for (int i = 1; i <= maxNum; ++i) 
	{
		if (find(used.begin(), used.end(), i) == used.end()) 
		{
			stringstream ss;
			ss << "MH" << setw(3) << setfill('0') << i;
			return ss.str();
		}
	}

	stringstream ss;
	ss << "MH" << setw(3) << setfill('0') << (maxNum + 1);
	return ss.str();
}

void QuanLyMatHang::themMatHang(const MatHang& mh) 
{
	for (const auto& item : ds) 
	{
		if (item.getMa() == mh.getMa()) 
		{
			cout << "\nMã mặt hàng " << mh.getMa() << " đã tồn tại!\n";
			return;
		}
	}

	auto pos = std::lower_bound(ds.begin(), ds.end(), mh, [](const MatHang& a, const MatHang& b) 
		{
			return a.getMa() < b.getMa();
		});

	ds.insert(pos, mh);
	Notify();

	cout << "\nĐã thêm mặt hàng có mã: " << mh.getMa() << " thành công!\n";
}

bool QuanLyMatHang::xoaMatHang(const string& ma) 
{
	for (auto i = ds.begin(); i != ds.end(); ++i) 
	{
		if (i->getMa() == ma) 
		{
			ds.erase(i);
			Notify();
			cout << "\nĐã xóa mặt hàng có mã: " << ma << "." << "\n";
			return true;
		}
	}
	cout << "\nKhông tìm thấy mặt hàng có mã: " << ma << "\n";
	return false;
}

bool QuanLyMatHang::suaMatHang(const string& ma) 
{
	for (auto& mh : ds) 
	{
		if (mh.getMa() == ma) 
		{
			cout << "\n==== THÔNG TIN MẶT HÀNG CẦN SỬA ====\n";
			MatHang::inTieuDe();
			mh.xuatDuLieu();
			const int wMa = 6, wTen = 35, wHangSX = 25, wHanSD = 12, wLoai = 8;
			cout << "   +" << string(wMa + 2, '-')
				<< "+" << string(wTen + 2, '-')
				<< "+" << string(wHangSX + 2, '-')
				<< "+" << string(wHanSD + 2, '-')
				<< "+" << string(wLoai + 2, '-')
				<< "+\n";
			
			string tenHangMoi, congTySanXuatMoi, hanSuDungMoi, loaiMoi;
			int namSXMoi;
			do 
			{
				cout << "\nNhập tên mặt hàng mới: ";
				getline(cin, tenHangMoi);

				if (isEmpty(tenHangMoi))
					cout << "\nTên mặt hàng không được để trống!\n";
				else
				{
					break;
				}
			} while (true);

			do 
			{
				cout << "\nNhập hãng sản xuất mới: ";
				getline(cin, congTySanXuatMoi);
				if (isEmpty(congTySanXuatMoi))
				{
					cout << "\nCông ty sản xuất không được để trống!\n";
				}
				else
				{
					break;
				}
			} while (true);

			do 
			{
				string input;
				cout << "\nThời hạn sử dụng mới (ví dụ: 10 ngay, 7 tuan, 3 thang, 1 nam, ...).\n";
				cout <<	"\nNhập thời hạn sử dụng mới: ";
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
					{
						soPhan += c;
					}
					else if (!isspace(c))
					{
						donViPhan += c;
					}
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

				hanSuDungMoi = to_string(soLuong) + " " + donViPhan;
				break;

			} while (true);

			do 
			{
				cout << "\nNhập năm sản xuất mới: ";
				cin >> namSXMoi;
				if (cin.fail()) 
				{
					cout << "\nNăm sản xuất không hợp lệ!\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					continue;
				}
				if (!isValidYear(namSXMoi))
				{
					cout << "\nNăm sản xuất không được lớn hơn năm hiện tại!\n";
				}
				else
				{
					break;
				}
			} while (true);
			cin.ignore();

			do 
			{
				cout << "\nNhập mã loại hàng mới: ";
				getline(cin >> ws, loaiMoi);
				auto& dsLoai = QuanLyLoaiHang::getInstance()->getDanhSach();
				bool tonTai = false;
				for (auto& lh : dsLoai) 
				{
					if (lh.getMaLoai() == loaiMoi) 
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

			mh.setTen(tenHangMoi);
			mh.setHangSX(congTySanXuatMoi);
			mh.setHanSD(hanSuDungMoi);
			mh.setLoai(loaiMoi);

			Notify();
			cout << "\nĐã cập nhật loại hàng!\n";
			return true;
		}
	}
	cout << "\nKhông tìm thấy mã mặt hàng cần sửa!\n";
	return false;
}

void QuanLyMatHang::timKiemTheoTen(const string& tuKhoa) 
{
	if (ds.empty()) 
	{
		cout << "\nDanh sách mặt hàng trống!\n";
		return;
	}

	string key = tuKhoa;
	transform(key.begin(), key.end(), key.begin(), ::tolower);
	bool found = false;
	cout << "\n==== KẾT QUẢ TÌM KIẾM MẶT HÀNG ====\n";

	MatHang::inTieuDe();
	for (const auto& mh : ds) 
	{
		string ten = mh.getTen();
		string lowerTen = ten;
		transform(lowerTen.begin(), lowerTen.end(), lowerTen.begin(), ::tolower);

		if (lowerTen.find(key) != string::npos) 
		{
			mh.xuatDuLieu();
			found = true;
		}
	}

	if (!found) 
	{
		cout << "\nKhông tìm thấy mặt hàng nào chứa từ khóa \"" << tuKhoa << "\n";
	}
	else 
	{
		const int wMa = 6, wTen = 35, wHangSX = 25, wHanSD = 12, wLoai = 8;

		cout << "   +" << string(wMa + 2, '-')
			<< "+" << string(wTen + 2, '-')
			<< "+" << string(wHangSX + 2, '-')
			<< "+" << string(wHanSD + 2, '-')
			<< "+" << string(wLoai + 2, '-')
			<< "+\n";
	}
}

void QuanLyMatHang::hienThiDanhSach() 
{
	auto& ds = getDanhSach();
	cout << "\n==== DANH SÁCH MẶT HÀNG ====\n";
	if (ds.empty()) 
	{
		cout << "\nDanh sách trống!\n";
		return;
	}

	MatHang::inTieuDe();
	for (const auto& mh : ds)
	{
		mh.xuatDuLieu();
	}

	const int wMa = 6, wTen = 35, wHangSX = 25, wHanSD = 12, wLoai = 8;
	cout << "   +" << string(wMa + 2, '-')
		<< "+" << string(wTen + 2, '-')
		<< "+" << string(wHangSX + 2, '-')
		<< "+" << string(wHanSD + 2, '-')
		<< "+" << string(wLoai + 2, '-') << "+\n";
}

vector<MatHang>& QuanLyMatHang::getDanhSach() 
{
	return ds;
}

QuanLyMatHang::~QuanLyMatHang() 
{
	ds.clear();
}