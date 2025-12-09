#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>
#include <typeinfo>
#include <vector>
#include <string>
#include <algorithm>
#include "fileManager.h"
#include "matHang.h"
#include "quanLyMatHang.h"
#include "loaiHang.h"
#include "quanLyLoaiHang.h"
#include "quanLyHoaDonNhap.h"
#include "quanLyHoaDonXuat.h"
#include "hoaDonNhap.h"
#include "hoaDonXuat.h"

FileManager* FileManager::instance = nullptr;
FileManager* FileManager::getInstance() 
{
	if (!instance)
	{
		instance = new FileManager();
	}
	return instance;
}

void FileManager::ghiLoaiHang() 
{
	ofstream file("loaihang.csv");
	if (!file.is_open()) 
	{
		cerr << "\nKhông thể ghi file loaihang.csv!\n";
		return;
	}

	file << "MaLoai;TenLoai;MoTa\n";
	auto& ds = QuanLyLoaiHang::getInstance()->getDanhSach();
	for (auto& lh : ds)
	{
		file << lh.getMaLoai() << ";" << lh.getTenLoai() << ";" << lh.getMoTa() << "\n";
	}
}

void FileManager::ghiMatHang() 
{
	ofstream file("mathang.csv");
	if (!file.is_open()) 
	{
		cerr << "\nKhông thể ghi file mathang.csv!\n";
		return;
	}

	file << "Ma;TenHang;CongTySX;HanSD;NamSX;Loai\n";
	auto& ds = QuanLyMatHang::getInstance()->getDanhSach();
	for (auto& mh : ds)
	{
		file << mh.getMa() << ";" << mh.getTen() << ";" << mh.getHangSX() << ";"
		<< mh.getHanSD() << ";" << mh.getLoai() << "\n";
	}
}

void FileManager::ghiHoaDonNhap() 
{
	ofstream file("hoadonnhap.csv");
	if (!file.is_open()) 
	{
		cerr << "\nKhông thể mở file hoadonnhap.csv để ghi!\n";
		return;
	}

	file << "MaHD;NgayNhap;NhaCungCap;MaHang;NgaySX;SoLuong;DonGia\n";

	auto& ds = QuanLyHoaDonNhap::getInstance()->getDanhSach();
	for (auto& hd : ds) 
	{
		for (auto& ct : hd.getChiTiet()) 
		{
			file << hd.getMaHD() << ";"
				<< hd.getNgayNhap() << ";"
				<< hd.getNhaCungCap() << ";"
				<< ct.getMaHang() << ";"
				<< ct.getNgaySanXuat() << ";"
				<< ct.getSoLuong() << ";"
				<< ct.getDonGia() << "\n";
		}
	}
}

void FileManager::ghiHoaDonXuat() 
{
	ofstream file("hoadonxuat.csv");
	if (!file.is_open()) 
	{
		cerr << "\nKhông thể mở file hoadonxuat.csv để ghi!\n";
		return;
	}

	file << "MaHD;NgayXuat;KhachHang;MaHang;SoLuong;DonGia\n";
	auto& ds = QuanLyHoaDonXuat::getInstance()->getDanhSach();
	for (auto& hd : ds) 
	{
		for (auto& ct : hd.getChiTiet()) 
		{
			file << hd.getMaHD() << ";"
				<< hd.getNgayXuat() << ";"
				<< hd.getKhachHang() << ";"
				<< ct.getMaHang() << ";"
				<< ct.getSoLuong() << ";"
				<< fixed << setprecision(0) << ct.getDonGia() << "\n";
		}
	}

	file.close();
	cout << "\nĐã ghi file hoadonxuat.csv thành công!\n";
}

void FileManager::ghiKho() 
{
	ofstream file("kho.csv");
	if (!file.is_open()) 
	{
		cerr << "\nKhông thể mở kho.csv để ghi!\n";
		return;
	}

	file << "MaMatHang;MaHD;TenHang;NgayNhap;SoLuongNhap;SoLuongTon;NhaCungCap;GiaNhap\n";

	auto& dsHD = QuanLyHoaDonNhap::getInstance()->getDanhSach();
	auto& dsMH = QuanLyMatHang::getInstance()->getDanhSach();

	struct DongKho 
	{
		string maMatHang;
		string maHD;
		string tenHang;
		string ngayNhap;
		string ngayKey;
		int soLuongNhap = 0;
		int soLuongTon = 0;
		string nhaCungCap;
		int giaNhap = 0;
	};

	vector<DongKho> dsKho;
	dsKho.reserve(1024);

	auto normalize = [](string s) 
	{
		while (!s.empty() && isspace((unsigned char)s.front())) s.erase(s.begin());
		while (!s.empty() && isspace((unsigned char)s.back())) s.pop_back();
		return s;
		};

	auto dateToKey = [](const string& date) -> string 
	{
		if (date.size() >= 10 && isdigit(date[0]) && date[2] == '/' && date[5] == '/') 
		{
			string dd = date.substr(0, 2);
			string mm = date.substr(3, 2);
			string yyyy = date.substr(6, 4);
			return yyyy + mm + dd;
		}
		return string("99999999");
		};

	for (const auto& hd : dsHD) 
	{
		string ngay = normalize(hd.getNgayNhap());
		string ncc = normalize(hd.getNhaCungCap());
		for (const auto& ct : hd.getChiTiet()) 
		{
			DongKho d;
			d.maMatHang = ct.getMaHang();
			d.maHD = hd.getMaHD();
			d.tenHang = "Unknown";

			for (const auto& mh : dsMH) 
			{
				if (mh.getMa() == d.maMatHang) 
				{ d.tenHang = normalize(mh.getTen()); break; }
			}
			d.ngayNhap = ngay;
			d.ngayKey = dateToKey(ngay);
			d.soLuongNhap = ct.getSoLuong();
			d.soLuongTon = ct.getSoLuong();
			d.nhaCungCap = ncc;
			d.giaNhap = static_cast<int>(ct.getDonGia());
			dsKho.push_back(std::move(d));
		}
	}

	stable_sort(dsKho.begin(), dsKho.end(), [&](const DongKho& a, const DongKho& b) 
	{
		if (a.maMatHang != b.maMatHang) return a.maMatHang < b.maMatHang;
		if (a.ngayKey != b.ngayKey) return a.ngayKey < b.ngayKey;
		return a.maHD < b.maHD;
		});

	for (const auto& d : dsKho) 
	{
		file << d.maMatHang << ";" << d.maHD << ";" << d.tenHang << ";"
			<< d.ngayNhap << ";" << d.soLuongNhap << ";" << d.soLuongTon << ";"
			<< d.nhaCungCap << ";" << d.giaNhap << "\n";
	}

	file.close();
	cout << "\nĐã ghi lại kho.csv (" << dsKho.size() << " dòng)!\n";
}

void FileManager::xoaKhoTheoHoaDon(const string& maHD) 
{
	if (maHD.empty()) return;

	ifstream in("kho.csv");
	if (!in.is_open()) 
	{
		cerr << "\nKhông thể mở kho.csv để cập nhật!\n";
		return;
	}

	vector<string> lines;
	string header;
	if (!getline(in, header)) 
	{
		in.close();
		return;
	}
	lines.push_back(header);

	string line;
	while (getline(in, line)) 
	{
		if (line.empty()) continue;
		stringstream ss(line);
		string col0, col1;
		if (!getline(ss, col0, ';')) continue;
		if (!getline(ss, col1, ';')) continue;

		if (col1 != maHD) 
		{
			lines.push_back(line);
		}
	}
	in.close();

	ofstream out("kho.csv", ios::trunc);
	if (!out.is_open()) 
	{
		cerr << "\nKhông thể mở kho.csv để ghi lại!\n";
		return;
	}
	for (const auto& l : lines) out << l << "\n";
	out.close();

	cout << "\nĐã xóa các dòng thuộc hóa đơn " << maHD << " khỏi kho.csv!\n";
}

void FileManager::xoaKhoTheoChiTiet(const string& maHD, const string& maMH) 
{
	ifstream in("kho.csv");
	if (!in.is_open()) 
	{
		cerr << "\nKhông thể mở kho.csv để cập nhật!\n";
		return;
	}

	vector<string> lines;
	string line;

	if (getline(in, line))
	{
		lines.push_back(line);
	}

	while (getline(in, line)) 
	{
		if (line.find(";" + maHD + ";") == string::npos || line.find(maMH + ";") == string::npos) 
		{
			lines.push_back(line);
		}
	}

	in.close();
	ofstream out("kho.csv", ios::trunc);
	for (const auto& l : lines)
	{
		out << l << "\n";
	}

	out.close();
	cout << "\nĐã xóa mặt hàng " << maMH << " thuộc hóa đơn " << maHD << " khỏi kho.csv!\n";
}

void FileManager::capNhatKhoSauXuat(const std::string& maHang, int soLuongXuat) 
{
	using namespace std;
	if (soLuongXuat <= 0) return;
	ifstream in("kho.csv");
	if (!in.is_open()) 
	{
		cerr << "\nKhông thể mở kho.csv để trừ tồn!\n";
		return;
	}

	string header;
	getline(in, header);
	vector<vector<string>> ds;
	string line;
	while (getline(in, line)) 
	{
		if (line.empty()) continue;
		stringstream ss(line);
		string cell;
		vector<string> row;
		while (getline(ss, cell, ';')) row.push_back(cell);
		while (row.size() < 8) row.push_back("");
		ds.push_back(row);
	}

	in.close();
	vector<int> idxs;
	for (int i = 0; i < (int)ds.size(); ++i) 
	{
		if (ds[i].size() >= 1 && ds[i][0] == maHang) idxs.push_back(i);
	}

	if (idxs.empty()) 
	{
		cout << "\nKhông tìm thấy mã hàng " << maHang << " trong kho!\n";
		return;
	}

	auto dateKey = [](const string& d)->string 
	{
		if (d.size() >= 10 && d[2] == '/' && d[5] == '/') 
		{
			string dd = d.substr(0, 2), mm = d.substr(3, 2), yy = d.substr(6, 4);
			return yy + mm + dd;
		}
		return string("99999999");
		};

	sort(idxs.begin(), idxs.end(), [&](int a, int b) 
	{
		return dateKey(ds[a][3]) < dateKey(ds[b][3]);
	});

	int remaining = soLuongXuat;
	for (int idx : idxs) 
	{
		if (remaining <= 0) break;
		int ton = 0;
		try 
		{
			ton = stoi(ds[idx][5]);
		}
		catch (...) 
		{
			ton = 0;
		}

		if (ton <= 0) continue;

		int giam = std::min(ton, remaining);
		ton -= giam;
		ds[idx][5] = to_string(ton);
		remaining -= giam;
	}

	ofstream out("kho.csv", ios::trunc);
	if (!out.is_open()) 
	{
		cerr << "\nKhông thể mở kho.csv để ghi lại!\n";
		return;
	}
	out << header << "\n";
	for (auto& r : ds) 
	{
		for (size_t j = 0; j < r.size(); ++j) 
		{
			out << r[j];
			if (j + 1 < r.size()) out << ";";
		}
		out << "\n";
	}
	out.close();

	if (remaining > 0) 
	{
		cout << "\nMã hàng " << maHang << " không đủ tồn để xuất thêm " << remaining << " sản phẩm!\n";
	}
	else 
	{
		cout << "\nĐã trừ tồn FIFO cho " << maHang << "!\n";
	}
}

void FileManager::capNhatKhoSauXuat_HoanTra(const std::string& maHang, int soLuongHoan) 
{
	using namespace std;
	if (soLuongHoan <= 0) return;
	ifstream in("kho.csv");
	if (!in.is_open()) 
	{
		cerr << "\nKhông thể mở kho.csv để hoàn trả!\n";
		return;
	}

	string header; getline(in, header);
	vector<vector<string>> ds;
	string line;
	while (getline(in, line)) 
	{
		if (line.empty()) continue;
		stringstream ss(line);
		string cell; vector<string> row;
		while (getline(ss, cell, ';')) row.push_back(cell);
		while (row.size() < 8) row.push_back("");
		ds.push_back(row);
	}

	in.close();
	vector<int> idxs;
	for (int i = 0; i < (int)ds.size(); ++i)
	{
		if (ds[i][0] == maHang) 
		{
			idxs.push_back(i);
		}
	}

	if (idxs.empty()) 
	{
		cout << "\nKhông tìm thấy mã hàng " << maHang << " trong kho để hoàn trả!\n";
		return;
	}

	auto dateKey = [](const string& d)->string 
	{
		if (d.size() >= 10 && d[2] == '/' && d[5] == '/') 
		{
			return d.substr(6, 4) + d.substr(3, 2) + d.substr(0, 2);
		}
		return string("00000000");
		};

	sort(idxs.begin(), idxs.end(), [&](int a, int b) 
	{
		return dateKey(ds[a][3]) > dateKey(ds[b][3]);
	});

	int remaining = soLuongHoan;
	for (int idx : idxs) 
	{
		if (remaining <= 0) break;
		int nhap = 0;
		try 
		{ nhap = stoi(ds[idx][4]); }
		catch (...) 
		{ nhap = 0; }
		int ton = 0;
		try 
		{ ton = stoi(ds[idx][5]); }
		catch (...) 
		{ ton = 0; }

		int canThem = max(0, nhap - ton);
		if (canThem <= 0) continue;
		int cong = std::min(canThem, remaining);
		ton += cong;
		ds[idx][5] = to_string(ton);
		remaining -= cong;
	}

	if (remaining > 0) 
	{
		string today = "01/01/1970";
		vector<string> newRow(8);
		newRow[0] = maHang; newRow[1] = ""; newRow[2] = ""; newRow[3] = today;
		newRow[4] = to_string(remaining); newRow[5] = to_string(remaining); newRow[6] = ""; newRow[7] = "0";
		ds.push_back(newRow);
		remaining = 0;
	}

	ofstream out("kho.csv", ios::trunc);
	if (!out.is_open()) 
	{ cerr << "\nKhông thể mở kho.csv để ghi lại!\n"; return; }
	out << header << "\n";
	for (auto& r : ds) 
	{
		for (size_t j = 0; j < r.size(); ++j) 
		{
			out << r[j];
			if (j + 1 < r.size()) out << ";";
		}
		out << "\n";
	}
	out.close();

	cout << "\nĐã hoàn trả " << maHang << " thành công!\n";
}

void FileManager::docLoaiHang() 
{
	ifstream file("loaihang.csv");
	if (!file.is_open()) 
	{
		cout << "\nKhông tìm thấy file loaihang.csv!\n";
		return;
	}

	string line;
	getline(file, line);
	auto& ds = QuanLyLoaiHang::getInstance()->getDanhSach();
	ds.clear();

	while (getline(file, line)) 
	{
		stringstream ss(line);
		string ma, ten, mota;

		auto trim = [](string& s) {
			while (!s.empty() && (s.front() == ' ' || s.front() == '\r' || s.front() == '\t'))
				s.erase(s.begin());
			while (!s.empty() && (s.back() == ' ' || s.back() == '\r' || s.back() == '\t'))
				s.pop_back();
		};
		getline(ss, ma, ';');
		getline(ss, ten, ';');
		getline(ss, mota);

		trim(ma);
		trim(ten);
		trim(mota);
		
		ds.push_back(LoaiHang(ma, ten, mota));
	}
}

void FileManager::docMatHang() 
{
	ifstream file("mathang.csv");
	if (!file.is_open()) 
	{
		cout << "\nKhông tìm thấy file mathang.csv!\n";
		return;
	}

	string line;
	getline(file, line);
	auto& ds = QuanLyMatHang::getInstance()->getDanhSach();
	ds.clear();

	while (getline(file, line)) 
	{
		stringstream ss(line);
		string ma, ten, congTySX, hanSD, loai;
		getline(ss, ma, ';');
		getline(ss, ten, ';');
		getline(ss, congTySX, ';');
		getline(ss, hanSD, ';');
		getline(ss, loai, ';');
		ds.push_back(MatHang(ma, ten, hanSD, congTySX, loai));
	}
}

void FileManager::docHoaDonNhap() 
{
	ifstream file("hoadonnhap.csv");
	if (!file.is_open()) 
	{
		cout << "\nKhông tìm thấy file hoadonnhap.csv!\n";
		return;
	}

	string line;
	getline(file, line);
	auto& ds = QuanLyHoaDonNhap::getInstance()->getDanhSach();
	ds.clear();
	map<string, HoaDonNhap> mapHD;

	while (getline(file, line)) 
	{
		if (line.empty()) continue;
		stringstream ss(line);
		string maHD, ngayNhap, nhaCungCap, maMH, ngaySX, slStr, dgStr;
		getline(ss, maHD, ';');
		getline(ss, ngayNhap, ';');
		getline(ss, nhaCungCap, ';');
		getline(ss, maMH, ';');
		getline(ss, ngaySX, ';');
		getline(ss, slStr, ';');
		getline(ss, dgStr, ';');

		if (maHD.empty() || maMH.empty()) continue;
		int sl = stoi(slStr);
		int dg = stoi(dgStr);
		ChiTietHoaDonNhap ct(maMH, ngaySX, sl, dg);

		if (!mapHD.count(maHD)) 
		{
			HoaDonNhap hd(maHD, ngayNhap, nhaCungCap);
			hd.themChiTietHoaDon(ct);
			mapHD[maHD] = hd;
		}
		else 
		{
			mapHD[maHD].themChiTietHoaDon(ct);
		}
	}

	for (auto& p : mapHD)
		ds.push_back(p.second);

	cout << "\nĐã đọc file hoadonnhap.csv thành công (" << ds.size() << " hóa đơn)!\n";
}

void FileManager::docHoaDonXuat() 
{
	ifstream file("hoadonxuat.csv");
	if (!file.is_open()) 
	{
		cout << "\nKhông tìm thấy file hoadonxuat.csv!\n";
		return;
	}

	string line;
	getline(file, line);

	auto& ds = QuanLyHoaDonXuat::getInstance()->getDanhSach();
	ds.clear();
	map<string, HoaDonXuat> mapHD;

	while (getline(file, line)) 
	{
		if (line.empty()) continue;

		stringstream ss(line);
		string maHD, ngayXuat, khachHang, maHang, soLuongStr, donGiaStr;

		getline(ss, maHD, ';');
		getline(ss, ngayXuat, ';');
		getline(ss, khachHang, ';');
		getline(ss, maHang, ';');
		getline(ss, soLuongStr, ';');
		getline(ss, donGiaStr, ';');

		if (maHD.empty() || maHang.empty())
			continue;

		int soLuong = stoi(soLuongStr);
		double donGia = stod(donGiaStr);
		ChiTietHoaDonXuat ct(maHang, soLuong, donGia);

		if (mapHD.find(maHD) == mapHD.end()) 
		{
			HoaDonXuat hd(maHD, ngayXuat, khachHang);
			hd.themChiTietHoaDon(ct);
			mapHD.insert(pair<string, HoaDonXuat>(maHD, hd));
		}
		else 
		{
			mapHD[maHD].themChiTietHoaDon(ct);
		}
	}

	for (map<string, HoaDonXuat>::iterator it = mapHD.begin(); it != mapHD.end(); ++it) 
	{
		ds.push_back(it->second);
	}

	file.close();
	cout << "\nĐã đọc file hoadonxuat.csv thành công (" << ds.size() << " hóa đơn)!\n";
}

void FileManager::docKho(vector<vector<string>>& dsKho) 
{
	ifstream file("kho.csv");
	dsKho.clear();

	if (!file.is_open()) 
	{
		cerr << "\nKhông thể mở file kho.csv để đọc!\n";
		return;
	}

	string line;
	if (!getline(file, line)) 
	{
		file.close();
		return;
	}

	while (getline(file, line)) 
	{
		if (line.empty()) continue;
		vector<string> row;
		stringstream ss(line);
		string cell;
		while (getline(ss, cell, ';')) 
		{
			row.push_back(cell);
		}
		if (row.size() < 8) continue;
		dsKho.push_back(row);
	}

	file.close();
}

void FileManager::Update(Subject* subject) 
{
	if (!subject) return;
	const type_info& type = typeid(*subject);

	if (type == typeid(QuanLyLoaiHang)) 
	{
		ghiLoaiHang();
	}
	else if (type == typeid(QuanLyMatHang)) 
	{
		ghiMatHang();
	}
	else if (type == typeid(QuanLyHoaDonNhap)) 
	{
		ghiHoaDonNhap();
		string maHDXoa = QuanLyHoaDonNhap::getMaHoaDonDangXoa();
		if (!maHDXoa.empty()) 
		{
			xoaKhoTheoHoaDon(maHDXoa);
			QuanLyHoaDonNhap::setMaHoaDonDangXoa("");
		}
		else 
		{
			ghiKho();
		}
	}
	else if (type == typeid(QuanLyHoaDonXuat)) 
	{
		ghiHoaDonXuat();
		cout << "\nĐã ghi file hoadonxuat.csv!\n";
	}
}