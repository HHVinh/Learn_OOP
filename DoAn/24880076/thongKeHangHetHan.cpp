#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
#include "thongKeHangHetHan.h"
#include "fileManager.h"
#include "quanLyMatHang.h"
#include "Validator.h"

void ThongKeHangHetHan::Update() 
{

}

void ThongKeHangHetHan::XuatThongKe() 
{
    auto& dsMH = QuanLyMatHang::getInstance()->getDanhSach();
    vector<vector<string>> dsKho;
    FileManager::getInstance()->docKho(dsKho);

    if (dsKho.empty() || dsMH.empty()) 
    {
        cout << "\nDữ liệu trống. Không thể thống kê hàng hết hạn!\n";
        return;
    }

    const int wMaMH = 8, wMaHD = 8, wTen = 28, wNCC = 25, wNgay = 12, wHan = 12, wTon = 10;
    const int totalWidth = wMaMH + wMaHD + wTen + wNCC + wNgay + wHan + wTon + 8 * 3 - 2;

    time_t now = time(nullptr);
    tm local
    {};
    localtime_r(&now, &local);

    char buf[20];
    strftime(buf, sizeof(buf), "%d/%m/%Y", &local);
    cout << "\nNgày thống kê: " << buf << "\n";

    cout << "\n==== THỐNG KÊ HÀNG HẾT HẠN ====\n";
    cout << "   " << string(totalWidth, '=') << "\n";
    cout << left
        << "   | " << setw(wMaMH) << "MaMH"
        << " | " << setw(wMaHD) << "MaHD"
        << " | " << setw(wTen) << "Ten Mat Hang"
        << " | " << setw(wNCC) << "Nha Cung Cap"
        << " | " << setw(wNgay) << "Ngay Nhap"
        << " | " << setw(wHan) << "Han SD"
        << " | " << right << setw(wTon) << "SL Ton" << " |\n";
    cout << "   " << string(totalWidth, '-') << "\n";

    bool found = false;
    long long tongTon = 0;
    (void) tongTon;

    for (const auto& mh : dsMH) 
    {
        string hanSD = mh.getHanSD();
        for (const auto& row : dsKho) 
        {
            if (row.size() < 8) continue;

            string maMH = row[0];
            string maHD = row[1];
            string ten = row[2];
            string ngayNhap = row[3];
            string slTon = row[5];
            string ncc = row[6];

            if (maMH != mh.getMa()) 
            {
                continue;
            }

            int ton = stoi(slTon);
            if (ton == 0) 
            {
                continue;
            }

            if (isExpired(ngayNhap, hanSD)) 
            {
                cout << left
                    << "   | " << setw(wMaMH) << maMH
                    << " | " << setw(wMaHD) << maHD
                    << " | " << setw(wTen) << ten
                    << " | " << setw(wNCC) << ncc
                    << " | " << setw(wNgay) << ngayNhap
                    << " | " << setw(wHan) << hanSD
                    << " | " << right << setw(wTon) << ton << " |\n";

                found = true;
            }
        }
    }

    if (!found) 
    {
        cout << "\nKhông có mặt hàng nào hết hạn còn tồn kho!\n";
    }
    else 
    {
        cout << "   " << string(totalWidth, '=') << "\n";
    }
}
