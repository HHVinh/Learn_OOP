#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include "quanLyMatHang.h"
#include "chiTietHoaDonXuat.h"
#include "hoaDonXuat.h"
#include "Validator.h"
#include "fileManager.h"
#include "menu.h"
#include "quanLyHoaDonXuat.h"

QuanLyHoaDonXuat* QuanLyHoaDonXuat::instance = nullptr;
QuanLyHoaDonXuat::QuanLyHoaDonXuat() 
{

}

QuanLyHoaDonXuat* QuanLyHoaDonXuat::getInstance() 
{
	if (!instance)
	{
		instance = new QuanLyHoaDonXuat();
	}
	return instance;
}

string QuanLyHoaDonXuat::sinhMaHoaDonXuat() 
{
	int maxNum = 0;
	vector<int> used;
	for (const auto& hd : ds) 
	{
		string ma = hd.getMaHD();
		if (ma.size() >= 5 && ma.substr(0, 3) == "HDX") 
		{
			int num = stoi(ma.substr(3));
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
			ss << "HDX" << setw(3) << setfill('0') << i;
			return ss.str();
		}
	}

	stringstream ss;
	ss << "HDX" << setw(3) << setfill('0') << (maxNum + 1);
	return ss.str();
}

void QuanLyHoaDonXuat::themHoaDon(const HoaDonXuat& hd) 
{
	ds.push_back(hd);
	FileManager* fm = FileManager::getInstance();

	cout << "\n==== Cập nhật kho t sau khi xuất hàng ====\n";
	for (const auto& ct : hd.getChiTiet()) 
	{
		cout << "Mặt hàng " << ct.getMaHang() << ": xuất " << ct.getSoLuong() << " sản phẩm!\n";
		fm->capNhatKhoSauXuat(ct.getMaHang(), ct.getSoLuong());
	}

	Notify();
	cout << "\nĐã thêm hóa đơn xuất mã " << hd.getMaHD() << " và cập nhật kho thành công!\n";
}

bool QuanLyHoaDonXuat::xoaHoaDon(const string& maHD) 
{
	auto it = find_if(ds.begin(), ds.end(), [&](const HoaDonXuat& h) 
	{
		return h.getMaHD() == maHD; 
	});

	if (it == ds.end()) 
	{
		cout << "\nKhông tìm thấy hóa đơn xuất có mã: " << maHD << "!\n";
		return false;
	}

	FileManager* fm = FileManager::getInstance();
	for (const auto& ct : it->getChiTiet()) 
	{
		fm->capNhatKhoSauXuat_HoanTra(ct.getMaHang(), ct.getSoLuong());
	}

	ds.erase(it);
	Notify();

	cout << "\nĐã xóa hóa đơn xuất " << maHD << " và hoàn lại tồn kho thành công!\n";
	return true;
}

bool QuanLyHoaDonXuat::suaHoaDon(const string& maHD) 
{
	auto it = find_if(ds.begin(), ds.end(), [&](const HoaDonXuat& h) 
	{
		return h.getMaHD() == maHD; 
	});

	if (it == ds.end()) 
	{
		cout << "\nKhông tìm thấy hóa đơn xuất có mã: " << maHD << "!\n";
		return false;
	}

	HoaDonXuat& hd = *it;
	int chon;
	do 
	{
		system("clear");
		cout << "\n";
		cout << "   ============================================\n";
		cout << "   ||       SỬA HÓA ĐƠN XUẤT '" << hd.getMaHD() << "'        ||\n";
		cout << "   ||========================================||\n";
		cout << "   || 1. Sửa thông tin hóa đơn xuất          ||\n";
		cout << "   || 2. Sửa chi tiết hóa đơn xuất           ||\n";
		cout << "   || 3. Thêm chi tiết hóa đơn xuất          ||\n";
		cout << "   || 4. Xóa chi tiết hóa đơn xuất           ||\n";
		cout << "   || 0. Quay lại                            ||\n";
		cout << "   ============================================\n\n";

		chon = safeInputIntMenu("Nhập lựa chọn của bạn: ");
		switch (chon) 
		{
			case 1: 
			{
				suaThongTinHoaDon(hd);
				system("pause");
				break;
			}
			case 2:
			{
				suaChiTietHoaDon(hd);
				system("pause");
				break;
			}
			case 3:
			{
				themChiTietHoaDon(hd);
				system("pause");
				break;
			}
			case 4: 
			{
				xoaChiTietHoaDon(hd);
				system("pause");
				break;
			}	
			case 0: 
			{
				break;
			}
			default:
			{
				cout << "\n[Lỗi] Lựa chọn không hợp lệ!\n";
			}
		}
	} while (chon != 0);

	return true;
}

bool QuanLyHoaDonXuat::suaThongTinHoaDon(HoaDonXuat& hd) 
{
	string ngayMoi, khMoi;
	cout << "\n==== SỬA THÔNG TIN HÓA ĐƠN XUẤT ====\n";
	cout << "\n==== THÔNG TIN HIỆN TẠI ====\n";

	const int wMa = 12;
	const int wNgay = 14;
	const int wKH = 20;

	cout << "   +" << string(wMa, '-')
		<< "+" << string(wNgay, '-')
		<< "+" << string(wKH - 1, '-') << "+\n";

	cout << "   | " << left << setw(wMa) << "Mã hóa đơn"
		<< " | " << left << setw(wNgay) << "Ngày xuất HĐ"
		<< " |    " << left << setw(wKH - 4) << "Khách hàng" << " |\n";

	cout << "   +" << string(wMa, '-')
		<< "+" << string(wNgay, '-')
		<< "+" << string(wKH - 1, '-') << "+\n";

	cout << "   |   " << left << setw(wMa - 4) << hd.getMaHD()
		<< " |  " << left << setw(wNgay - 3) << hd.getNgayXuat()
		<< " | " << left << setw(wKH - 2) << hd.getKhachHang()
		<< "|\n";

	cout << "   +" << string(wMa, '-')
		<< "+" << string(wNgay, '-')
		<< "+" << string(wKH - 1, '-') << "+\n";

	while (true) 
	{
		cout << "\nNhập ngày xuất hóa đơn mới (định dạng 'dd/mm/yyyy', hoặc bấm 'Enter' để giữ nguyên): ";
		getline(cin, ngayMoi);
		if (ngayMoi.empty()) 
		{
			ngayMoi = hd.getNgayXuat();
			cout << "\nNgày xuất hóa đơn giữ nguyên!\n";
			break;
		}

		if (!isValidDateFormat(ngayMoi) || !isDateNotFuture(ngayMoi)) 
		{
			cout << "\nNgày không hợp lệ!\n";
			continue;
		}

		break;
	}

	while (true) 
	{
		cout << "\nNhập tên khách hàng mới (hoặc bấm 'Enter' để giữ nguyên): ";
		getline(cin, khMoi);
		if (khMoi.empty()) 
		{
			khMoi = hd.getKhachHang();
			cout << "\nTên khách hàng giữ nguyên!\n";
			break;
		}

		if (isEmpty(khMoi)) 
		{
			cout << "\nTên khách hàng không được để trống!\n";
			continue;
		}

		break;
	}

	hd.setNgayXuat(ngayMoi);
	hd.setKhachHang(khMoi);
	Notify();
	cout << "\nĐã sửa thông tin hóa đơn xuất thành công!\n";
	return true;
}

bool QuanLyHoaDonXuat::suaChiTietHoaDon(HoaDonXuat& hd) 
{
	auto& chiTiets = hd.getChiTiet();
	if (chiTiets.empty()) 
	{
		cout << "\nHóa đơn này chưa có chi tiết để sửa!\n";
		return false;
	}

	cout << "\n==== CÁC CHI TIẾT HIỆN CÓ TRONG HÓA ĐƠN ====\n";

	hd.inTieuDe();
	hd.xuatChiTietHoaDonSua();
	string maHang;
	FileManager* fm = FileManager::getInstance();

	while (true) 
	{
		cout << "\nNhập mã mặt hàng cần sửa hoặc nhập 0 để hủy thao tác: ";
		getline(cin >> ws, maHang);

		if (maHang == "0") 
		{
			cout << "\nĐã hủy thao tác sửa chi tiết hóa đơn!\n";
			return false;
		}

		if (!isValidFormatMaMatHang(maHang)) 
		{
			cout << "\nMã mặt hàng phải có dạng MHxxx!\n";
			continue;
		}

		auto it = find_if(chiTiets.begin(), chiTiets.end(), [&](const ChiTietHoaDonXuat& ct) 
		{
			return ct.getMaHang() == maHang; 
		});

		if (it == chiTiets.end()) 
		{
			cout << "\nMã hàng không tồn tại trong hóa đơn!\n";
			continue;
		}

		int soLuongCu = it->getSoLuong();
		int donGiaCu = it->getDonGia();
		vector<vector<string>> dsKho;
		fm->docKho(dsKho);

		vector<vector<string>> loNhap;
		int tongTon = 0;

		for (auto& row : dsKho) 
		{
			if (row.size() >= 8 && row[0] == maHang) 
			{
				loNhap.push_back(row);
				tongTon += stoi(row[5]);
			}
		}

		sort(loNhap.begin(), loNhap.end(), [](const vector<string>& a, const vector<string>& b) 
		{
			string A = a[3].substr(6, 4) + a[3].substr(3, 2) + a[3].substr(0, 2);
			string B = b[3].substr(6, 4) + b[3].substr(3, 2) + b[3].substr(0, 2);
			return A < B;
		});

		cout << "\n=============================================\n";
		cout << "   |  TỒN KHO HIỆN TẠI CỦA " << maHang << " : "
			<< setw(5) << tongTon << " sản phẩm |\n";
		cout << "=============================================\n";

		int soLuongMoi;
		while (true) 
		{
			cout << "\nNhập số lượng xuất mới: ";
			string input;
			getline(cin, input);

			if (input.empty()) 
			{
				soLuongMoi = soLuongCu;
				cout << "\nGiữ nguyên số lượng!\n";
				break;
			}

			if (!all_of(input.begin(), input.end(), ::isdigit)) 
			{
				cout << "\nChỉ được nhập số!\n";
				continue;
			}

			soLuongMoi = stoi(input);
			if (soLuongMoi <= 0) 
			{
				cout << "\nSố lượng phải > 0!\n";
				continue;
			}

			int delta = soLuongMoi - soLuongCu;
			if (delta > 0 && delta > tongTon) 
			{
				cout << "\nXuất thêm " << delta << " nhưng kho chỉ còn " << tongTon << "!\n";
				continue;
			}

			break;
		}

		long long tongTien = 0;
		int tongSL = 0;
		int canLay = soLuongCu;

		for (auto& row : loNhap) 
		{
			if (canLay <= 0) break;

			int slNhap = stoi(row[4]);
			int giaNhap = stoi(row[7]);
			int lay = min(slNhap, canLay);

			tongTien += 1LL * lay * giaNhap;
			tongSL += lay;
			canLay -= lay;
		}

		int giaNhapBinhQuan = (tongSL > 0 ? tongTien / tongSL : 0);
		cout << "\nGiá nhập trung bình gốc: " << giaNhapBinhQuan << " VNĐ\n";

		int donGiaMoi;
		while (true) 
		{
			cout << "\nNhập đơn giá mới: ";
			string input;
			getline(cin, input);

			if (input.empty()) 
			{
				donGiaMoi = donGiaCu;
				cout << "\nGiữ nguyên đơn giá!\n";
				break;
			}

			if (!all_of(input.begin(), input.end(), ::isdigit)) 
			{
				cout << "\nĐơn giá phải là số!\n";
				continue;
			}

			donGiaMoi = stoi(input);

			if (donGiaMoi < giaNhapBinhQuan) 
			{
				cout << "\nĐơn giá phải ≥ giá nhập (" << giaNhapBinhQuan << ")!\n";
				continue;
			}

			break;
		}

		if (soLuongMoi == soLuongCu && donGiaMoi == donGiaCu) 
		{
			cout << "\nKhông có thay đổi nào!\n";
			continue;
		}

		int delta = soLuongMoi - soLuongCu;
		it->setSoLuong(soLuongMoi);
		it->setDonGia(donGiaMoi);

		if (delta > 0) 
		{
			fm->capNhatKhoSauXuat(maHang, delta);
		}
		else if (delta < 0) 
		{
			fm->capNhatKhoSauXuat_HoanTra(maHang, -delta);
		}

		Notify();
		cout << "\nSửa chi tiết hóa đơn thành công!\n";
		return true;
	}

	return false;
}

bool QuanLyHoaDonXuat::themChiTietHoaDon(HoaDonXuat& hd) 
{

	auto& chiTiets = hd.getChiTiet();
	auto& dsMH = QuanLyMatHang::getInstance()->getDanhSach();
	FileManager* fm = FileManager::getInstance();
	vector<vector<string>> dsKho;
	fm->docKho(dsKho);

	cout << "\n==== CÁC CHI TIẾT HIỆN CÓ TRONG HÓA ĐƠN ====\n";
	hd.inTieuDe();
	hd.xuatChiTietHoaDonSua();
	cout << "\n";
	while (true) 
	{

		cout << "\n==== THÊM CHI TIẾT HÓA ĐƠN XUẤT ====\n";

		string maHang;
		cout << "\nNhập mã mặt hàng hoặc nhập 0 để hủy thao tác: ";
		getline(cin >> ws, maHang);

		if (maHang == "0") 
		{
			cout << "\nĐã hủy thao tác thêm chi tiết hóa đơn!\n";
			return false;
		}

		if (!isValidFormatMaMatHang(maHang)) 
		{
			cout << "\nMã mặt hàng phải có dạng MHxxx!\n";
			continue;
		}

		auto itMH = find_if(dsMH.begin(), dsMH.end(), [&](const MatHang& m) 
		{
			return m.getMa() == maHang; 
		});

		if (itMH == dsMH.end()) 
		{
			cout << "\nKhông tồn tại mã mặt hàng này trong hệ thống!\n";
			continue;
		}

		vector<vector<string>> loTon;
		int tongTon = 0;

		for (auto& row : dsKho) 
		{
			if (row.size() >= 8 && row[0] == maHang && stoi(row[5]) > 0) 
			{
				loTon.push_back(row);
				tongTon += stoi(row[5]);
			}
		}

		if (tongTon == 0) 
		{
			cout << "\nMặt hàng này không còn sản phẩm nào trong kho!\n";
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
			{
				tongTonKho += stoi(dong[5]); 
			}
			catch (...) 
			{

			}
		}

		cout << "\n==== THÔNG TIN TỒN KHO MẶT HÀNG ====\n";
		cout << "   Mã hàng        : " << maHang << "\n";
		cout << "   Tên mặt hàng   : " << tenMH << "\n";
		cout << "   Tổng tồn kho   : " << tongTonKho << " sản phẩm\n";

		int soLuongXuat;
		while (true)
		{
			cout << "\nNhập số lượng xuất: ";
			string sl;
			getline(cin >> ws, sl);

			if (!all_of(sl.begin(), sl.end(), ::isdigit)) 
			{
				cout << "\nChỉ được nhập số nguyên dương!\n";
				continue;
			}

			soLuongXuat = stoi(sl);
			if (soLuongXuat <= 0) 
			{
				cout << "\nSố lượng phải lớn hơn 0!\n";
				continue;
			}

			if (soLuongXuat > tongTon) 
			{
				cout << "\nSố lượng trong kho không đủ để xuất!\n";
				continue;
			}

			break;
		}

		sort(loTon.begin(), loTon.end(), [](const vector<string>& a, const vector<string>& b) 
		{
			string A = a[3].substr(6, 4) + a[3].substr(3, 2) + a[3].substr(0, 2);
			string B = b[3].substr(6, 4) + b[3].substr(3, 2) + b[3].substr(0, 2);
			return A < B;
		});

		int canLay = soLuongXuat;
		long long tongGiaTri = 0;
		int tongLay = 0;

		for (auto& row : loTon) 
		{
			if (canLay <= 0) break;

			int soTon = stoi(row[5]);
			int giaNhap = stoi(row[7]);
			int lay = min(canLay, soTon);
			tongGiaTri += 1LL * lay * giaNhap;
			tongLay += lay;
			canLay -= lay;
		}

		int giaNhapBinhQuan = (tongLay > 0 ? tongGiaTri / tongLay : 0);

		cout << "\nGiá nhập trung bình: " << giaNhapBinhQuan << " VNĐ\n";

		int donGiaXuat;
		while (true) 
		{
			donGiaXuat = safeInputInt("\nNhập đơn giá xuất: ");

			if (donGiaXuat < giaNhapBinhQuan) 
			{
				cout << "\nĐơn giá xuất phải lớn hơn hoặc bằng giá nhập trung bình!\n";
				continue;
			}
			else
			{
				break;
			}
		}

		chiTiets.push_back(ChiTietHoaDonXuat(maHang, soLuongXuat, donGiaXuat));
		fm->capNhatKhoSauXuat(maHang, soLuongXuat);

		cout << "\nĐã thêm " << maHang << " vào hóa đơn!\n";
		string tiep;
		cout << "\nThêm mặt hàng khác? (y/n): ";
		getline(cin >> ws, tiep);
		if (tiep != "y" && tiep != "Y") 
		{
			break;
		}
	}

	Notify();
	return true;
}

bool QuanLyHoaDonXuat::xoaChiTietHoaDon(HoaDonXuat& hd) 
{
	auto& chiTiets = hd.getChiTiet();
	if (chiTiets.empty()) 
	{
		cout << "\nHóa đơn này chưa có chi tiết để xóa!\n";
		return false;
	}

	cout << "\n==== CÁC CHI TIẾT HIỆN CÓ TRONG HÓA ĐƠN ====\n";
	hd.inTieuDe();
	hd.xuatChiTietHoaDonSua();
	cout << "\n";
	string maHang;

	while (true) 
	{

		cout << "\nNhập mã mặt hàng cần xóa hoặc nhập 0 để hủy thao tác: ";
		getline(cin >> ws, maHang);

		if (maHang == "0") 
		{
			cout << "\nĐã hủy thao tác xóa chi tiết hóa đơn!\n";
			return false;
		}

		if (!isValidFormatMaMatHang(maHang)) 
		{
			cout << "\nMã mặt hàng phải có dạng MHxxx!\n";
			continue;
		}

		auto it = find_if(chiTiets.begin(), chiTiets.end(), [&](const ChiTietHoaDonXuat& ct) 
		{
			return ct.getMaHang() == maHang;
		});

		if (it == chiTiets.end()) 
		{
			cout << "\nMã hàng không tồn tại trong hóa đơn!\n";
			continue;
		}

		cout << "\nBạn có chắc chắn muốn xóa chi tiết này?\n";
		cout << "   Mã hàng : " << it->getMaHang() << "\n";
		cout << "   SL xuất : " << it->getSoLuong() << "\n";
		cout << "   Đơn giá : " << it->getDonGia() << "\n";

		string xn;
		cout << "Xác nhận xóa? (y/n): ";
		getline(cin >> ws, xn);

		if (xn != "y" && xn != "Y") 
		{
			cout << "\nĐã hủy thao tác xóa!\n";
			return false;
		}

		int soLuongXoa = it->getSoLuong();
		FileManager::getInstance()->capNhatKhoSauXuat_HoanTra(maHang, soLuongXoa);
		chiTiets.erase(it);

		Notify();
		cout << "\nĐã xóa chi tiết hóa đơn & hoàn trả lượng tồn kho!\n";
		return true;
	}

	return false;
}

vector<HoaDonXuat>& QuanLyHoaDonXuat::getDanhSach() 
{
	return ds; 
}

void QuanLyHoaDonXuat::timKiemHoaDonTheoKhachHang(const string& key) 
{
	string k = key; transform(k.begin(), k.end(), k.begin(), ::tolower);
	bool found = false;
	for (const auto& hd : ds) 
	{
		string kh = hd.getKhachHang(); transform(kh.begin(), kh.end(), kh.begin(), ::tolower);
		if (kh.find(k) != string::npos) 
		{
			HoaDonXuat::inTieuDe();
			hd.xuatDuLieu();
			found = true;
		}
	}
	if (!found)
	{
		cout << "\nKhông tìm thấy hóa đơn xuất với khách hàng: " << key << "\n";
	}
}

void QuanLyHoaDonXuat::hienThiDanhSach() 
{
	if (ds.empty()) 
	{
		cout << "\nDanh sách hóa đơn xuất trống!\n";
		return;
	}
	for (const auto& hd : ds) 
	{
		hd.inTieuDe();
		hd.xuatDuLieu();
	}
}

QuanLyHoaDonXuat::~QuanLyHoaDonXuat() 
{
	ds.clear(); 
}
