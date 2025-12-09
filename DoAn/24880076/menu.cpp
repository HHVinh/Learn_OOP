#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "menu.h"
#include "fileManager.h"
#include "quanLyMatHang.h"
#include "quanLyLoaiHang.h"
#include "quanLyHoaDonNhap.h"
#include "quanLyHoaDonXuat.h"
#include "thongKeHangTonKho.h"
#include "thongKeHangHetHan.h"
#include "Validator.h"

void Menu::docDuLieu() 
{
	FileManager* fm = FileManager::getInstance();
	QuanLyLoaiHang::getInstance()->Attach(fm);
	QuanLyMatHang::getInstance()->Attach(fm);
	QuanLyHoaDonNhap::getInstance()->Attach(fm);
	QuanLyHoaDonXuat::getInstance()->Attach(fm);

	fm->docLoaiHang();     
	fm->docMatHang();      
	fm->docHoaDonNhap();  
	fm->docHoaDonXuat();
}

void Menu::myPause()
{
    cout << "Nhấn Enter để quay lại...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void Menu::hienThiMenu() 
{
	int chon;

	do 
	{
		system("clear");
		cout << "\n";
		cout << "   ========================================\n";
		cout << "   ||          QUẢN LÝ CỬA HÀNG          ||\n";
		cout << "   ||====================================||\n";
		cout << "   || 1/ Quản lý loại hàng               ||\n";
		cout << "   || 2/ Quản lý mặt hàng                ||\n";
		cout << "   || 3/ Quản lý hóa đơn nhập            ||\n";
		cout << "   || 4/ Quản lý hóa đơn xuất            ||\n";
		cout << "   || 5/ Thống kê hàng tồn kho           ||\n";
		cout << "   || 6/ Thống kê hàng hết hạn           ||\n";
		cout << "   || 0/ Thoát                           ||\n";
		cout << "   ========================================\n\n";

		chon = safeInputIntMenu("Nhập lựa chọn của bạn: ");

		switch (chon) 
		{
			case 1: 
			{
				system("clear");
				menuLoaiHang();
				break;
			}
			case 2: 
			{
				system("clear");
				menuMatHang();
				break;
			}
			case 3: 
			{
				system("clear");
				menuHoaDonNhap();
				break;
			}
			case 4: 
			{
				system("clear");
				menuHoaDonXuat();
				break;
			}
			case 5: 
			{
				ThongKeHangTonKho tk;
				system("clear");
				tk.XuatThongKe();
				myPause();
				break;
			}
			case 6: 
			{
				ThongKeHangHetHan tk;
				system("clear");
				tk.XuatThongKe();
				myPause();
				break;
			}
			case 0:
			{
				cout << "Thoát chương trình!\n";
				break;
			}
			default:
			{
				cout << "Lựa chọn không hợp lệ!\n";
				myPause();
			}
		}
	} while (chon != 0);
}

void Menu::menuLoaiHang() 
{
	QuanLyLoaiHang* ql = QuanLyLoaiHang::getInstance();
	int chon;
	do 
	{
		system("clear");
		cout << "\n";
		cout << "   =======================================\n";
		cout << "   ||         QUẢN LÝ LOẠI HÀNG         ||\n";
		cout << "   ||===================================||\n";
		cout << "   || 1/ Thêm loại hàng                 ||\n";
		cout << "   || 2/ Xóa loại hàng                  ||\n";
		cout << "   || 3/ Sửa loại hàng                  ||\n";
		cout << "   || 4/ Tìm kiếm loại hàng theo tên    ||\n";
		cout << "   || 5/ Hiển thị danh sách loại hàng   ||\n";
		cout << "   || 0/ Quay lại menu chính            ||\n";
		cout << "   =======================================\n\n";

		chon = safeInputIntMenu("Nhập lựa chọn của bạn: ");

		switch (chon) 
		{
			case 1: 
			{
				LoaiHang lh;
				system("clear");
				if (lh.nhap())
				{
					ql->themLoaiHang(lh);
				}

				myPause();
				break;
			}
			case 2: 
			{
				auto& ds = ql->getDanhSach();
				system("clear");
				if (ds.empty()) 
				{
					cout << "\nDanh sách loại hàng trống! Không thể xóa!\n";
					break;
				}

				string ma;
				while (true) 
				{
					cout << "Nhập mã loại hàng cần xóa: ";
					getline(cin >> ws, ma);

					if (ma == "0") 
					{
						cout << "\nĐã hủy xóa loại hàng!\n";
						break;
					}

					if (isEmpty(ma)) 
					{
						cout << "\nMã loại hàng không được để trống!\n";
						continue;
					}
					else if (!isValidFormatMaLoai(ma)) 
					{
						cout << "\nMã loại hàng phải có dạng LHxxx (Ví dụ LH001, LH002,...) hoặc nhập 0 để hủy thao tác!\n";
						continue;
					}

					ql->xoaLoaiHang(ma);
					break;
				}

				myPause();
				break;
			}
			case 3: 
			{
				auto& ds = ql->getDanhSach();
				system("clear");

				if (ds.empty()) 
				{
					cout << "\nDanh sách loại hàng trống! Không thể sửa!\n";
					break;
				}

				string ma;
				while (true) 
				{
					cout << "Nhập mã loại hàng cần sửa: ";
					getline(cin >> ws, ma);

					if (ma == "0") 
					{
						cout << "\nĐã hủy sửa loại hàng!\n";
						break;
					}

					if (isEmpty(ma)) 
					{
						cout << "\nMã loại hàng không được để trống!\n";
						continue;
					}
					else if (!isValidFormatMaLoai(ma)) 
					{
						cout << "\nMã loại hàng phải có dạng LHxxx (Ví dụ LH001, LH002,...) hoặc nhập 0 để hủy thao tác!\n";
						continue;
					}

					ql->suaLoaiHang(ma);
					break;
				}

				myPause();
				break;
			}
			case 4: 
			{
				auto& ds = ql->getDanhSach();
				system("clear");
				if (ds.empty()) 
				{
					cout << "\nDanh sách loại hàng trống! Không thể tìm kiếm!\n";
					break;
				}

				string tuKhoa;
				while (true) 
				{
					cout << "Nhập tên tên loại hàng cần tìm hoặc nhập 0 để hủy thao tác: ";
					getline(cin >> ws, tuKhoa);

					if (tuKhoa == "0") 
					{
						cout << "\nĐã hủy tìm kiếm loại hàng!\n";
						break;
					}

					if (isEmpty(tuKhoa)) 
					{
						cout << "\nTên loại hàng không được để trống!\n";
						continue;
					}

					ql->timKiemTheoTen(tuKhoa);
					break;
				}

				myPause();
				break;
			}
			case 5:
			{
				system("clear");
				ql->hienThiDanhSach();
				myPause();
				break;
			}
			case 0:
			{
				break;
			}
			default:
			{
				cout << "\nLựa chọn của bạn không hợp lệ!\n";
				myPause();
			}
		}
	} while (chon != 0);
}

void Menu::menuMatHang() 
{
	QuanLyMatHang* ql = QuanLyMatHang::getInstance();
	int chon;
	do 
	{
		system("clear");
		cout << "\n";
		cout << "   ======================================\n";
		cout << "   ||         QUẢN LÝ MẶT HÀNG         ||\n";
		cout << "   ||==================================||\n";
		cout << "   || 1/ Thêm mặt hàng                 ||\n";
		cout << "   || 2/ Xóa mặt hàng                  ||\n";
		cout << "   || 3/ Sửa mặt hàng                  ||\n";
		cout << "   || 4/ Tìm kiếm mặt hàng             ||\n";
		cout << "   || 5/ Hiển thị danh sách mặt hàng   ||\n";
		cout << "   || 0/ Quay lại menu chính           ||\n";
		cout << "   ======================================\n\n";

		chon = safeInputIntMenu("Nhập lựa chọn của bạn: ");

		switch (chon) 
		{
			case 1:
			{
				MatHang mh;
				system("clear");
				if (mh.nhap())
				{
					ql->themMatHang(mh);
				}
				myPause();
				break;
			}
			case 2: 
			{
				auto& ds = ql->getDanhSach();
				system("clear");
				if (ds.empty()) 
				{
					cout << "\nDanh sách mặt hàng trống! Không thể xóa!\n";
					break;
				}

				string ma;
				while (true) 
				{
					cout << "\nNhập mã mặt hàng cần xóa: ";
					getline(cin >> ws, ma);

					if (ma == "0") 
					{
						cout << "\nĐã hủy xóa mặt hàng!\n";
						break;
					}

					if (isEmpty(ma)) 
					{
						cout << "\nMã mặt hàng không được để trống!\n";
						continue;
					}
					else if (!isValidFormatMaMatHang(ma)) 
					{
						cout << "\nMã mặt hàng phải có dạng LHxxx (ví dụ MH001, MH002,...) hoặc nhập 0 để hủy thao tác!\n";
						continue;
					}

					ql->xoaMatHang(ma);
					break;
				}

				myPause();
				break;
			}
			case 3: 
			{
				auto& ds = ql->getDanhSach();
				system("clear");
				if (ds.empty()) 
				{
					cout << "\nDanh sách mặt hàng hiện đang trống! Không thể sửa!\n";
					break;
				}

				string ma;
				while (true) 
				{
					cout << "\nNhập mã mặt hàng cần sửa hoặc nhập 0 để hủy thao tác: ";
					getline(cin >> ws, ma);

					if (ma == "0") 
					{
						cout << "\nĐã hủy sửa mặt hàng!\n";
						break;
					}

					if (isEmpty(ma)) 
					{
						cout << "\nMã mặt hàng không được để trống!\n";
						continue;
					}
					else if (!isValidFormatMaMatHang(ma)) 
					{
						cout << "\nMã mặt hàng phải có dạng 'LHxxx' (ví dụ MH001, MH002,...) hoặc '0'\n";
						continue;
					}

					ql->suaMatHang(ma);
					break;
				}

				myPause();
				break;
			}
			case 4: 
			{
				auto& ds = ql->getDanhSach();
				system("clear");
				if (ds.empty()) 
				{
					cout << "\nDanh sách mặt hàng hiện đang trống! Không thể tìm kiếm!\n";
					break;
				}

				string tuKhoa;

				while (true) 
				{
					cout << "\nNhập tên hoặc một phần tên loại hàng cần tìm hoặc nhập 0 để hủy thao tác: ";
					getline(cin >> ws, tuKhoa);

					if (tuKhoa == "0") 
					{
						cout << "\nĐã hủy tìm kiếm loại hàng!\n";
						break;
					}

					if (isEmpty(tuKhoa)) 
					{
						cout << "\nTừ khóa tìm kiếm không được để trống!\n";
						continue;
					}

					ql->timKiemTheoTen(tuKhoa);
					break;
				}

				myPause();
				break;
			}
			case 5:
			{
				system("clear");
				ql->hienThiDanhSach();
				myPause();
				break;
			}
			case 0:
			{
				break;
			}
			default:
			{
				cout << "\nLựa chọn của bạn không hợp lệ!\n";
				myPause();
			}
		}
	} while (chon != 0);
}

void Menu::menuHoaDonNhap() 
{
	QuanLyHoaDonNhap* ql = QuanLyHoaDonNhap::getInstance();
	QuanLyMatHang* qlMH = QuanLyMatHang::getInstance();
	int chon;
	do 
	{
		system("clear");
		cout << "\n";
		cout << "   ============================================\n";
		cout << "   ||          QUẢN LÝ HÓA ĐƠN NHẬP          ||\n";
		cout << "   ||========================================||\n";
		cout << "   || 1/ Thêm hóa đơn nhập                   ||\n";
		cout << "   || 2/ Xóa hóa đơn nhập                    ||\n";
		cout << "   || 3/ Sửa hóa đơn nhập                    ||\n";
		cout << "   || 4/ Tìm kiếm hóa đơn theo nhà cung cấp  ||\n";
		cout << "   || 5/ Hiển thị danh sách hóa đơn nhập     ||\n";
		cout << "   || 0/ Quay lại menu chính                 ||\n";
		cout << "   ============================================\n\n";

		chon = safeInputIntMenu("Nhập lựa chọn của bạn: ");
		switch (chon) 
		{
		case 1: 
		{
			system("clear");
			menuThemHoaDonNhap();
			myPause();
			break;
		}
		case 2: 
		{
			auto& ds = ql->getDanhSach();
			system("clear");
			if (ds.empty()) 
			{
				cout << "\nDanh sách hóa đơn nhập trống! Không thể xóa!\n";
				break;
			}

			string ma;
			while (true) 
			{
				cout << "\nNhập mã hóa đơn nhập cần xóa: ";
				getline(cin >> ws, ma);

				if (ma == "0") 
				{
					cout << "\nĐã hủy xóa hóa đơn nhập!\n";
					break;
				}

				if (isEmpty(ma)) 
				{
					cout << "\nMã hóa đơn nhập không được để trống!\n";
					continue;
				}
				else if (!isValidFormatMaHDNhap(ma)) 
				{
					cout << "\nMã hóa đơn nhập phải có dạng 'HDNxxx' (Ví dụ HDN001, HDN002,...) hoặc nhập 0 để hủy thao tác!\n";
					continue;
				}

				ql->xoaHoaDon(ma);
				break;
			}

			myPause();
			break;
		}
		case 3: 
		{
			auto& ds = ql->getDanhSach();
			system("clear");
			if (ds.empty()) 
			{
				cout << "\nDanh sách hóa đơn nhập trống! Không thể xóa!\n";
				break;
			}

			string ma;
			while (true) 
			{
				cout << "\nNhập mã hóa đơn nhập cần sửa: ";
				getline(cin >> ws, ma);

				if (ma == "0") 
				{
					cout << "\nĐã hủy sửa hóa đơn nhập!\n";
					break;
				}

				if (isEmpty(ma)) 
				{
					cout << "\nMã hóa đơn nhập không được để trống!\n";
					continue;
				}
				else if (!isValidFormatMaHDNhap(ma)) 
				{
					cout << "\nMã hóa đơn nhập phải có dạng 'HDNxxx' (Ví dụ HDN001, HDN002,...) hoặc nhập 0 để hủy thao tác!\n";
					continue;
				}

				ql->suaHoaDon(ma);
				break;
			}

			myPause();
			break;
		}
		case 4:
		{
			auto& ds = ql->getDanhSach();
			system("clear");
			if (ds.empty()) 
			{
				cout << "\nDanh sách hóa đơn nhập trống! Không thể tìm kiếm!\n";
				break;
			}

			string tuKhoa;
			while (true) 
			{
				cout << "Nhập tên nhà cung cấp cần tìm hoặc nhập 0 để hủy thao tác: ";
				getline(cin >> ws, tuKhoa);

				if (tuKhoa == "0") 
				{
					cout << "\nĐã hủy tìm kiếm hóa đơn nhập!\n";
					break;
				}

				if (isEmpty(tuKhoa)) 
				{
					cout << "\nTên nhà cung cấp không được để trống!\n";
					continue;
				}

				ql->timKiemHoaDonTheoNhaCungCap(tuKhoa);
				break;
			}

			myPause();
			break;
		}
		case 5:
		{
			system("clear");
			ql->hienThiDanhSach();
			myPause();
			break;
		}
		case 0:
		{
			break;
		}
		default:
		{
			cout << "\n[Lỗi] Lựa chọn của bạn không hợp lệ!\n";
			myPause();
		}
		}

	} while (chon != 0);
}

void Menu::menuThemHoaDonNhap() 
{
	QuanLyHoaDonNhap* qlHD = QuanLyHoaDonNhap::getInstance();
	auto& dsLoai = QuanLyLoaiHang::getInstance()->getDanhSach();
	auto& dsMatHang = QuanLyMatHang::getInstance()->getDanhSach();

	cout << "\n";
	cout << "   ==========================================================================\n";
	cout << "   ||                        THÊM HÓA ĐƠN NHẬP HÀNG                        ||\n";
	cout << "   ||======================================================================||\n";
	cout << "   || 1/ Thêm hóa đơn nhập hàng với nhà cung cấp và mặt hàng đã có         ||\n";
	cout << "   || 2/ Thêm hóa đơn nhập hàng với nhà cung cấp đã có và mặt hàng mới     ||\n";
	cout << "   || 3/ Thêm hóa đơn nhập hàng với nhà cung cấp mới                       ||\n";
	cout << "   || 0/ Hủy thêm hóa đơn                                                  ||\n";
	cout << "   ==========================================================================\n\n";

	if (dsLoai.empty()) 
	{
		cout << "\nChưa có loại hàng!\n";
		cout << "\nHãy thêm loại hàng trước khi nhập hóa đơn!\n";
		myPause();
		return;
	}

	if (dsMatHang.empty()) 
	{
		cout << "\nChưa có mặt hàng!\n";
		cout << "\nHãy thêm mặt hàng trước khi nhập hóa đơn!\n";
		myPause();
		return;
	}

	int mode = safeInputInt("\nNhập lựa chọn của bạn: ");
	if (mode == 0) 
	{
		cout << "\nĐã hủy thao tác nhập hóa đơn!\n";
		myPause();
		return;
	}

	HoaDonNhap hd;
	bool thanhCong = false;

	switch (mode) 
	{
		case 1:
		{
			system("clear");
			cout << "\nTHÊM HÓA ĐƠN NHẬP HÀNG VỚI NHÀ CUNG CẤP VÀ MẶT HÀNG ĐÃ CÓ!\n";
			thanhCong = hd.nhapHoaDonNhap_MatHangCoSan();
			break;
		}
		case 2:
		{
			system("clear");
			cout << "\nTHÊM HÓA ĐƠN NHẬP HÀNG VỚI NHÀ CUNG CẤP ĐÃ CÓ VÀ MẶT HÀNG MỚI!\n";
			thanhCong = hd.nhapHoaDonNhap_MatHangMoi();
			break;
		}
		case 3:
		{
			system("clear");
			cout << "\nTHÊM HÓA ĐƠN NHẬP HÀNG VỚI NHÀ CUNG CẤP MỚI!\n";
			thanhCong = hd.nhapHoaDonNhap_NhaCungCapMoi();
			break;
		}
		default:
		{
			cout << "\nLựa chọn không hợp lệ!\n";
			break;
		}
	}

	if (thanhCong) 
	{
		qlHD->themHoaDon(hd);
		cout << "\nĐã thêm hóa đơn thành công và cập nhật kho!\n";
	}
	else 
	{
		cout << "\nHủy thêm hóa đơn!\n";
	}

}

void Menu::menuHoaDonXuat() 
{
	QuanLyHoaDonXuat* ql = QuanLyHoaDonXuat::getInstance();
	QuanLyMatHang* qlMH = QuanLyMatHang::getInstance();
	int chon;
	do 
	{
		system("clear");
		cout << "\n";
		cout << "   ============================================\n";
		cout << "   ||          QUẢN LÝ HÓA ĐƠN XUẤT          ||\n";
		cout << "   ||========================================||\n";
		cout << "   || 1/ Thêm hóa đơn xuất                   ||\n";
		cout << "   || 2/ Xóa hóa đơn xuất                    ||\n";
		cout << "   || 3/ Sửa hóa đơn xuất                    ||\n";
		cout << "   || 4/ Tìm kiếm hóa đơn theo khách hàng    ||\n";
		cout << "   || 5/ Hiển thị danh sách hóa đơn xuất     ||\n";
		cout << "   || 0/ Quay lại menu chính                 ||\n";
		cout << "   ===========================================\n\n";

		chon = safeInputIntMenu("Nhập lựa chọn của bạn: ");
		switch (chon) 
		{
			case 1: 
			{
				auto& dsLoai = QuanLyLoaiHang::getInstance()->getDanhSach();				
				system("clear");
				if (dsLoai.empty()) 
				{
					cout << "\nChưa có loại hàng!\n";
					cout << "\nHãy thêm loại hàng trước khi xuất hóa đơn!\n";
					myPause();
					break;
				}

				auto& dsMatHang = QuanLyMatHang::getInstance()->getDanhSach();
				if (dsMatHang.empty()) 
				{
					cout << "\nChưa có mặt hàng!\n";
					cout << "\nHãy thêm mặt hàng trước khi xuất hóa đơn!\n";
					myPause();
					break;
				}

				vector<vector<string>> dsKho;
				FileManager::getInstance()->docKho(dsKho);
				if (dsKho.empty()) 
				{
					cout << "\nKho hiện tại đang trống! Không thể xuất hóa đơn!\n";
					myPause();
					break;
				}

				HoaDonXuat hd;
				if (hd.nhapHoaDonXuat()) 
				{
					ql->themHoaDon(hd);
					cout << "\nĐã xuất hóa đơn thành công và cập nhật kho!\n";
				}
				else 
				{
					cout << "\nĐã hủy xuất hóa đơn!\n";
				}

				myPause();
				break;
			}
			case 2: 
			{
				auto& ds = ql->getDanhSach();
				system("clear");
				if (ds.empty()) 
				{
					cout << "\nDanh sách hóa đơn xuất hiện đang trống! Không thể xóa!\n";
					myPause();
					break;
				}

				string ma;
				while (true) 
				{
					cout << "\nNhập mã hóa đơn xuất cần xóa: ";
					getline(cin >> ws, ma);

					if (ma == "0") 
					{
						cout << "\nĐã hủy thao tác xóa hóa đơn!\n";
						break;
					}
					if (isEmpty(ma)) 
					{
						cout << "\nMã hóa đơn xuất không được để trống!\n";
						continue;
					}
					else if (!isValidFormatMaHDXuat(ma)) 
					{
						cout << "\nMã hóa đơn xuất phải có dạng HDxxx (Ví dụ HDX001, HDX002,...) hoặc nhập 0 để hủy thao tác!\n";
						continue;
					}

					ql->xoaHoaDon(ma);
					break;
				}

				myPause();
				break;
			}
			case 3: 
			{
				auto& ds = ql->getDanhSach();	
				system("clear");
				if (ds.empty()) 
				{
					cout << "\nDanh sách hóa đơn xuất hiện đang trống! Không thể sửa!\n";
					myPause();
					break;
				}

				string ma;
				while (true) 
				{
					cout << "\nNhập mã hóa đơn xuất cần sửa: ";
					getline(cin >> ws, ma);

					if (ma == "0") 
					{
						cout << "\nĐã hủy thao tác sửa hóa đơn!\n";
						break;
					}

					if (isEmpty(ma)) 
					{
						cout << "\nMã hóa đơn xuất không được để trống!\n";
						continue;
					}

					else if (!isValidFormatMaHDXuat(ma)) 
					{
						cout << "\nMã hóa đơn xuất phải có dạng HDxxx (Ví dụ HDX001, HDX002,...) hoặc nhập 0 để hủy thao tác!\n";
						continue;
					}

					ql->suaHoaDon(ma);
					break;
				}

				myPause();
				break;
			}
			case 4: 
			{
				auto& ds = ql->getDanhSach();
				system("clear");
				if (ds.empty()) 
				{
					cout << "\nDanh sách hóa đơn xuất hiện đang trống! Không thể tìm kiếm!\n";
					myPause();
					break;
				}

				string tuKhoa;
				while (true) 
				{
					cout << "Nhập tên khách hàng cần tìm kiếm hoặc nhập 0 để hủy thao tác: ";
					getline(cin >> ws, tuKhoa);

					if (tuKhoa == "0") 
					{
						cout << "\nĐã hủy tìm kiếm hóa đơn xuất!\n";
						break;
					}

					if (isEmpty(tuKhoa)) 
					{
						cout << "\nTừ khóa tìm kiếm không được để trống!\n";
						continue;
					}

					ql->timKiemHoaDonTheoKhachHang(tuKhoa);
					break;
				}
				
				myPause();
				break;
			}
			case 5:
			{
				system("clear");
				ql->hienThiDanhSach();
				myPause();
				break;
			}
			case 0:
			{
				break;
			}	
			default:
			{
				cout << "\n[Lỗi] Lựa chọn của bạn không hợp lệ!\n";
				myPause();
			}
		}
	} while (chon != 0);
}

