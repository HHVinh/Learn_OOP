#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <string>
#include "thongKeHangTonKho.h"
#include "fileManager.h"
using namespace std;

string centerText(const string& text, int width) 
{
    if ((int)text.size() >= width)
    {
        return text.substr(0, width);
    }

    int left = (width - text.size()) / 2;
    int right = width - text.size() - left;
    return string(left, ' ') + text + string(right, ' ');
}

void ThongKeHangTonKho::Update() 
{
    cout << "\nDữ liệu kho hàng đã thay đổi, cần thống kê lại!\n";
}

void ThongKeHangTonKho::XuatThongKe() 
{
    vector<vector<string>> dsKho;
    FileManager::getInstance()->docKho(dsKho);
    if (dsKho.empty()) 
    {
        cout << "\nHiện kho hàng trống!\n";
        return;
    }

    map<string, pair<string, pair<string, long long>>> thongKe;
    for (const auto& row : dsKho) 
    {
        if (row.size() < 8) continue;
        string maMH = row[0];
        string tenHang = row[2];
        string ncc = row[6];
        long long ton = stoll(row[5]);

        if (thongKe.find(maMH) == thongKe.end())
        {
            thongKe[maMH] = make_pair(tenHang, make_pair(ncc, ton));
        }
        else
        {
            thongKe[maMH].second.second += ton;
        }
    }

    const int wMaMH = 6, wTen = 35, wNCC = 25, wTon = 8;
    const int totalWidth = wMaMH + wTen + wNCC + wTon + 5 * 3 - 2;

    cout << "\n==== THỐNG KÊ HÀNG TỒN TRONG KHO ====\n";
    cout << "   " << string(totalWidth, '=') << "\n";
    cout << "   | " << centerText("MaMH", wMaMH)
        << " | " << centerText("Ten Mat Hang", wTen)
        << " | " << centerText("Nha Cung Cap", wNCC)
        << " | " << centerText("SL Ton", wTon) << " |\n";
    cout << "   " << string(totalWidth, '-') << "\n";

    long long tongTon = 0;
    (void) tongTon;
    for (auto& p : thongKe) 
    {
        cout << left << "   | " << setw(wMaMH) << p.first
            << " | " << setw(wTen) << p.second.first
            << " | " << setw(wNCC) << p.second.second.first
            << " | " << right << setw(wTon) << p.second.second.second << " |\n";
        tongTon += p.second.second.second;
    }
    cout << "   " << string(totalWidth, '=') << "\n";
}

