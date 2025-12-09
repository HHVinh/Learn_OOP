#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include "quanLyMatHang.h"
#include "chiTietHoaDonNhap.h"
#include "quanLyHoaDonNhap.h"
#include "hoaDonNhap.h"
#include "Validator.h"
#include "fileManager.h"
#include "menu.h"

QuanLyHoaDonNhap* QuanLyHoaDonNhap::instance = nullptr;
QuanLyHoaDonNhap::QuanLyHoaDonNhap() 
{

}

QuanLyHoaDonNhap* QuanLyHoaDonNhap::getInstance() 
{
	if (!instance) 
	{
		instance = new QuanLyHoaDonNhap();
	}
	return instance;
}

string QuanLyHoaDonNhap::sinhMaHoaDonNhap() 
{
	int maxNum = 0;
	vector<int> used;
	for (const auto& hd : ds) 
	{
		string ma = hd.getMaHD();
		if (ma.size() >= 5 && ma.substr(0, 3) == "HDN") 
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
			ss << "HDN" << setw(3) << setfill('0') << i;
			return ss.str();
		}
	}

	stringstream ss;
	ss << "HDN" << setw(3) << setfill('0') << (maxNum + 1);
	return ss.str();
}

void QuanLyHoaDonNhap::themHoaDon(const HoaDonNhap& hd) 
{
	for (const auto& item : ds)
	{
		if (item.getMaHD() == hd.getMaHD()) 
		{
			cout << "\n   [Lỗi] Mã hóa đơn " << hd.getMaHD() << " đã tồn tại!\n";
			return;
		}
	}

	auto pos = lower_bound(ds.begin(), ds.end(), hd,
		[](const HoaDonNhap& a, const HoaDonNhap& b) 
		{
			return a.getMaHD() < b.getMaHD();
		});
	ds.insert(pos, hd);


	Notify();
	cout << "\nĐã thêm hóa đơn " << hd.getMaHD() << " thành công!\n";
}

string QuanLyHoaDonNhap::maHoaDonDangXoa = "";
string QuanLyHoaDonNhap::getMaHoaDonDangXoa() 
{
	return maHoaDonDangXoa;
}

bool QuanLyHoaDonNhap::xoaHoaDon(const std::string& maHD) 
{
	auto it = std::find_if(ds.begin(), ds.end(),
		[&](const HoaDonNhap& h) 
		{ return h.getMaHD() == maHD; });

	if (it == ds.end()) 
	{
		std::cout << "\nKhông tìm thấy hóa đơn " << maHD << "!\n";
		return false;
	}

	std::string confirm;
	std::cout << "\nBạn có chắc muốn xóa hóa đơn '" << maHD << "' không? (y/n): ";
	std::getline(std::cin >> std::ws, confirm);
	if (confirm != "y" && confirm != "Y") return false;
	
	ds.erase(it);
	maHoaDonDangXoa = maHD;
	Notify();
	maHoaDonDangXoa.clear();
	std::cout << "\nĐã xóa hóa đơn " << maHD << " và cập nhật kho.csv!\n";
	return true;
}

bool QuanLyHoaDonNhap::suaHoaDon(const string& maHD) 
{
	auto it = find_if(ds.begin(), ds.end(),
		[&](const HoaDonNhap& h) 
		{ return h.getMaHD() == maHD; });

	if (it == ds.end()) 
	{
		cout << "\nKhông tìm thấy hóa đơn có mã: " << maHD << "\n";
		return false;
	}

	HoaDonNhap& hd = *it;
	int chon;
	do 
	{
		system("clear");
		cout << "\n";
		cout << "   ============================================\n";
		cout << "   ||            SỬA HÓA ĐƠN NHẬP            ||\n";
		cout << "   ||========================================||\n";
		cout << "   || 1/ Sửa ngày nhập / nhà cung cấp        ||\n";
		cout << "   || 2/ Sửa số lượng / đơn giá              ||\n";
		cout << "   || 3/ Xóa một mặt hàng khỏi hóa đơn       ||\n";
		cout << "   || 0/ Quay lại                            ||\n";
		cout << "   ============================================\n\n";

		chon = safeInputIntMenu("Nhập lựa chọn: ");
		switch (chon) 
		{
			case 1:
			{
				suaThongTinHoaDon(hd);
				break;
			}
			case 2:
			{
				suaChiTietHoaDon(hd);
				break;
			}
			case 3:
			{
				xoaChiTietHoaDon(hd);
				break;
			}
			case 0:
			{
				return true;
			}
			default:
			{
				cout << "\nLựa chọn không hợp lệ!\n";
				break;
			}
		}
		system("pause");
	} while (chon != 0);

	return true;
}

bool QuanLyHoaDonNhap::suaThongTinHoaDon(HoaDonNhap& hd) 
{
	string ngayMoi, nccMoi;
	cout << "\n==== SỬA THÔNG TIN HÓA ĐƠN " << hd.getMaHD() << " ====\n";

	do 
	{
		cout << "\nNhập ngày nhập mới (dd/mm/yyyy): ";
		getline(cin >> ws, ngayMoi);
		if (isEmpty(ngayMoi) || !isValidDateFormat(ngayMoi) || !isDateNotFuture(ngayMoi)) 
		{
			cout << "\nNgày nhập không hợp lệ!\n";
			continue;
		}
		break;
	} while (true);

	do 
	{
		cout << "\nNhập tên nhà cung cấp mới: ";
		getline(cin >> ws, nccMoi);
		if (isEmpty(nccMoi)) 
		{
			cout << "\nNhà cung cấp không được để trống!\n";
			continue;
		}
		break;
	} while (true);

	hd.setNgayNhap(ngayMoi);
	hd.setNhaCungCap(nccMoi);
	Notify();
	cout << "\nĐã cập nhật thông tin hóa đơn thành công!\n";
	return true;
}

bool QuanLyHoaDonNhap::suaChiTietHoaDon(HoaDonNhap& hd) 
{
	auto& chiTiet = hd.getChiTiet();
	if (chiTiet.empty()) 
	{
		cout << "\nHóa đơn không có chi tiết để sửa!\n";
		return false;
	}

	string maHang;
	cout << "\nNhập mã mặt hàng cần sửa: ";
	getline(cin >> ws, maHang);

	auto it = find_if(chiTiet.begin(), chiTiet.end(),
		[&](const ChiTietHoaDonNhap& ct) 
		{ return ct.getMaHang() == maHang; });

	if (it == chiTiet.end()) 
	{
		cout << "\nMã hàng không tồn tại trong hóa đơn!\n";
		return false;
	}

	int slMoi = safeInputInt("\nNhập số lượng mới: ");
	int dgMoi = safeInputInt("\nNhập đơn giá mới: ");

	it->setSoLuong(slMoi);
	it->setDonGia(dgMoi);
	Notify();
	cout << "\nĐã sửa chi tiết hóa đơn thành công!\n";
	return true;
}


bool QuanLyHoaDonNhap::xoaChiTietHoaDon(HoaDonNhap& hd) 
{
    auto& chiTiets = hd.getChiTiet();
    if (chiTiets.empty()) 
	{
        cout << "\nHóa đơn này chưa có chi tiết hàng hóa để xóa!\n";
        return false;
    }

    cout << "\n==== XÓA CHI TIẾT HÓA ĐƠN " << hd.getMaHD() << " ====\n";
    HoaDonNhap::inTieuDe();
    hd.xuatDuLieu();
    while (true) 
	{
        string maHang;
        cout << "\nNhập mã mặt hàng cần xóa hoặc nhập 0 để hủy thao tác: ";
        getline(cin >> ws, maHang);

        if (maHang == "0") 
		{
            cout << "\nĐã hủy thao tác xóa chi tiết hóa đơn!\n";
            return false;
        }

        auto it = find_if(chiTiets.begin(), chiTiets.end(),
            [&](const ChiTietHoaDonNhap& ct) 
			{ return ct.getMaHang() == maHang; });

        if (it == chiTiets.end()) 
		{
            cout << "\nKhông tìm thấy mã hàng cần xóa trong hóa đơn. Vui lòng thử lại!\n";
            continue;
        }

        if (chiTiets.size() == 1) 
		{
            string xacNhan;
            cout << "\nHóa đơn này chỉ còn 1 mặt hàng!\n";
            cout << "\nXóa mặt hàng này sẽ xóa luôn hóa đơn " << hd.getMaHD() << "!\n";
            cout << "Bạn có muốn tiếp tục? (y/n): ";
            getline(cin >> ws, xacNhan);

            if (xacNhan == "y" || xacNhan == "Y") 
			{
                auto itHD = find_if(ds.begin(), ds.end(),
                    [&](const HoaDonNhap& h) 
					{ return h.getMaHD() == hd.getMaHD(); });

                if (itHD != ds.end()) 
				{
                    maHoaDonDangXoa = hd.getMaHD();
                    ds.erase(itHD);
                    Notify();
                    maHoaDonDangXoa.clear();
                    cout << "\nĐã xóa toàn bộ hóa đơn " << hd.getMaHD() << "!\n";
                    return true;
                }
                else 
				{
                    cout << "\nKhông tìm thấy hóa đơn để xóa (bất ngờ)!\n";
                    return false;
                }
            }
            else 
			{
                cout << "\nĐã hủy thao tác!\n";
                return false;
            }
        }

        chiTiets.erase(it);
        Notify();
        cout << "\nĐã xóa chi tiết hàng '" << maHang << "' khỏi hóa đơn " << hd.getMaHD() << "!\n";
        string tiepTuc;
        do 
		{
            cout << "Bạn có muốn xóa thêm mặt hàng khác từ hóa đơn này không? (y/n): ";
            getline(cin >> ws, tiepTuc);
            if (tiepTuc == "y" || tiepTuc == "Y") 
			{
                // hiển thị lại hóa đơn đã cập nhật
                cout << "\n==== HÓA ĐƠN SAU KHI XÓA ====\n";
                HoaDonNhap::inTieuDe();
                hd.xuatDuLieu();
                break;
            }
            else if (tiepTuc == "n" || tiepTuc == "N") 
			{
                cout << "\nHoàn tất thao tác xóa chi tiết!\n";
                return true;
            }
            else 
			{
                cout << "\nChỉ được nhập 'y' hoặc 'n'. Vui lòng thử lại!\n";
            }
        } while (true);
    }
}

void QuanLyHoaDonNhap::setMaHoaDonDangXoa(const string& maHD) 
{
    maHoaDonDangXoa = maHD;
}

vector<HoaDonNhap>& QuanLyHoaDonNhap::getDanhSach() 
{
	return ds;
}

void QuanLyHoaDonNhap::timKiemHoaDonTheoNhaCungCap(const string& tuKhoa) 
{
	string key = tuKhoa;
	transform(key.begin(), key.end(), key.begin(), ::tolower);
	bool found = false;
	cout << "\n==== KẾT QUẢ TÌM KIẾM HÓA ĐƠN NHẬP ====\n";

	for (const auto& hd : ds) 
	{
		string ncc = hd.getNhaCungCap();
		string lowerNCC = ncc;
		transform(lowerNCC.begin(), lowerNCC.end(), lowerNCC.begin(), ::tolower);

		if (lowerNCC.find(key) != string::npos) 
		{
			HoaDonNhap::inTieuDe();
			hd.xuatDuLieu();
			found = true;
		}
	}

	if (!found) 
	{
		cout << "\nKhông tìm thấy hóa đơn nào có nhà cung cấp chứa \"" << tuKhoa << "\"!\n";
	}

	cout << endl;
}

void QuanLyHoaDonNhap::hienThiDanhSach() 
{
	auto& hd = getDanhSach();
	if (ds.empty()) 
	{
		cout << "\nDanh sách hóa đơn nhập hiện đang trống!\n";
		return;
	}

	cout << "\n==== DANH SÁCH HÓA ĐƠN NHẬP ====\n";
	for (const auto& hd : ds) 
	{
		HoaDonNhap::inTieuDe();
		hd.xuatDuLieu();
	}
};

QuanLyHoaDonNhap::~QuanLyHoaDonNhap() 
{
	ds.clear();
}
