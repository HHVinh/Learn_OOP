#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "quanLyLoaiHang.h"
#include "Validator.h"

QuanLyLoaiHang* QuanLyLoaiHang::instance = nullptr;
QuanLyLoaiHang::QuanLyLoaiHang() 
{

}

QuanLyLoaiHang* QuanLyLoaiHang::getInstance() 
{
	if (!instance) 
	{
		instance = new QuanLyLoaiHang();
	}
	return instance;
}

string QuanLyLoaiHang::sinhMaLoaiHang() 
{
	int maxNum = 0;
	vector<int> used;
	for (const auto& lh : ds) 
	{
		string ma = lh.getMaLoai();
		if (ma.size() >= 5 && ma.substr(0, 2) == "LH") 
		{
			int num = stoi(ma.substr(2));
			used.push_back(num);
			if (num > maxNum) maxNum = num;
		}
	}

	sort(used.begin(), used.end());
	for (int i = 1; i <= maxNum; ++i) 
	{
		if (find(used.begin(), used.end(), i) == used.end()) 
		{
			stringstream ss;
			ss << "LH" << setw(3) << setfill('0') << i;
			return ss.str();
		}
	}

	stringstream ss;
	ss << "LH" << setw(3) << setfill('0') << (maxNum + 1);
	return ss.str();
}

void QuanLyLoaiHang::themLoaiHang(const LoaiHang& lh) 
{
	auto pos = lower_bound(ds.begin(), ds.end(), lh, [](const LoaiHang& a, const LoaiHang& b) 
	{
		return a.getMaLoai() < b.getMaLoai();
	});
	
	ds.insert(pos, lh);
	Notify();
	cout << "\nĐã thêm loại hàng có mã: " << lh.getMaLoai() << " thành công!\n";
}

bool QuanLyLoaiHang::xoaLoaiHang(const string& maLoai) 
{
	for (auto i = ds.begin(); i != ds.end(); ++i) 
	{
		if (i->getMaLoai() == maLoai) 
		{
			ds.erase(i);
			Notify();
			cout << "\nĐã xóa loại hàng có mã: " << maLoai << "." << "\n";
			return true;
		}
	}
	cout << "\nKhông tìm thấy mặt hàng có mã: " << maLoai << "\n";
	return false;
}

bool QuanLyLoaiHang::suaLoaiHang(const string& maLoai) 
{
	for (auto& lh : ds) 
	{
		if(lh.getMaLoai() == maLoai)
		{
			cout << "\n==== THÔNG TIN LOẠI HÀNG CẦN SỬA ====\n";
			LoaiHang::inTieuDe();
			lh.xuatDuLieu();

			const int wMa = 8, wTen = 40, wMoTa = 70;
			cout << "   +" << string(wMa + 2, '-')
				<< "+" << string(wTen + 2, '-')
				<< "+" << string(wMoTa + 2, '-') << "+\n";

			string tenMoi, moTaMoi;
			do 
			{
				cout << "\nNhập tên loại mới: ";
				getline(cin >> ws, tenMoi);

				if (isEmpty(tenMoi))
					cout << "\nTên loại không được để trống!\n";
				else break;
			} while (true);

			cout << "\nNhập mô tả mới: ";
			getline(cin, moTaMoi);
			lh.setTenLoai(tenMoi);
			lh.setMoTa(moTaMoi);

			Notify();
			cout << "\nĐã cập nhật loại hàng\n";
			return true;
		}
	}

	cout << "\nKhông tìm thấy mã loại hàng cần sửa!\n";
	return false;
}

void QuanLyLoaiHang::timKiemTheoTen(const string& tuKhoa) 
{
	string key = tuKhoa;
	transform(key.begin(), key.end(), key.begin(), ::tolower);
	bool found = false;

	cout << "\n==== KẾT QUẢ TÌM KIẾM LOẠI HÀNG ====\n";
	LoaiHang::inTieuDe();
	for (const auto& lh : ds) 
	{
		string ten = lh.getTenLoai();
		string lowerTen = ten;
		transform(lowerTen.begin(), lowerTen.end(), lowerTen.begin(), ::tolower);

		if (lowerTen.find(key) != string::npos) 
		{
			lh.xuatDuLieu();
			found = true;
		}
	}

	if (!found) 
	{
		cout << "\nKhông tìm thấy loại hàng nào chứa từ khóa \"" << tuKhoa << "\"!\n";
	}
	else 
	{
		const int wMa = 8, wTen = 40, wMoTa = 70;
		cout << "   +" << string(wMa + 2, '-')
			<< "+" << string(wTen + 2, '-')
			<< "+" << string(wMoTa + 2, '-') << "+\n";
	}
}

void QuanLyLoaiHang::hienThiDanhSach() 
{
	auto& ds = getDanhSach();
	cout << "\n==== DANH SÁCH LOẠI HÀNG ====\n";
	if (ds.empty()) 
	{
		cout << "Danh sách trống!\n";
		return;
	}

	LoaiHang::inTieuDe();
	for (const auto& lh : ds) 
	{
		lh.xuatDuLieu();
	}
	
	const int wMa = 8, wTen = 40, wMoTa = 70;
	cout << "   +" << string(wMa + 2, '-')
		 << "+" << string(wTen + 2, '-')
		 << "+" << string(wMoTa + 2, '-') << "+\n";
	cout << endl;

}

vector<LoaiHang>& QuanLyLoaiHang::getDanhSach() 
{
	return ds;
}

QuanLyLoaiHang::~QuanLyLoaiHang() 
{
	ds.clear();
}