#include <algorithm>
#include <string>
#include <sstream>
#include <ctime>
#include <iostream>
#include <limits>
#include <vector>
#include <iomanip>
#include "Validator.h"
#include "loaiHang.h"
#include "matHang.h"
#include "hoaDonNhap.h"
#include "hoaDonXuat.h"

bool isEmpty(const string& s) 
{
	return s.empty();
}

int safeInputIntMenu(const string& message) 
{
    int val;
    while (true) 
    {
        cout << message;
        cin >> val;
        if (cin.fail()) 
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nVui lòng nhập số hợp lệ!\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return val;
    }
}

bool isDuplicateMaLoai(const vector<LoaiHang>& ds, const string& maLoai) 
{
    for (const auto& lh : ds) 
    {
        if (lh.getMaLoai() == maLoai)
            return true;
    }
    return false;
}

bool isValidFormatMaLoai(const string& maLoai) 
{
    if (maLoai.size() != 5)
    {
        return false;
    }

    if (maLoai[0] != 'L' || maLoai[1] != 'H') 
    {
        return false;
    }

    for (size_t i = 2; i < maLoai.size(); ++i) 
    {
        if(!isdigit(maLoai[i]))
        {
            return false;
        }
    }
    return true;
}

bool isDuplicateMaMatHang(const vector<MatHang>& ds, const string& maLoai) 
{
    for (const auto& lh : ds) 
    {
        if (lh.getMa() == maLoai)
        {
            return true;
        }
    }
    return false;
}

bool isValidFormatMaMatHang(const string& maLoai) 
{
    if (maLoai.size() != 5) 
    {
        return false;
    }

    if (maLoai[0] != 'M' || maLoai[1] != 'H') 
    {
        return false;
    }

    for (size_t i = 2; i < maLoai.size(); ++i) 
    {
        if (!isdigit(maLoai[i]))
        {
            return false;
        }
    }

    return true;
}


bool isValidDateFormat(const string& date) 
{
	if (date.size() != 10 || date[2] != '/' || date[5] != '/') 
    {
		return false;
	}

    int d, m, y;
    char sep1, sep2;
    stringstream ss(date);
    ss >> d >> sep1 >> m >> sep2 >> y;

    if (ss.fail() || sep1 != '/' || sep2 != '/')
    {
        return false;
    }

    if (d < 1 || m < 1 || y < 1 || m > 12)
    {
        return false;
    }

    int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
    daysInMonth[1] = 29;
    return d <= daysInMonth[m - 1];
}

bool isFutureDate(const string& date) 
{
    int d, m, y;
    char sep;
    stringstream ss(date);
    ss >> d >> sep >> m >> sep >> y;

    time_t now = time(nullptr);
    tm local
    {};
    localtime_r(&now, &local);

    int dayNow = local.tm_mday;
    int monNow = local.tm_mon + 1;
    int yearNow = local. tm_year + 1900;

    if (y > yearNow)
    {
        return true;
    }

    if (y == yearNow && m > monNow)
    {
        return true;
    }

    if (y == yearNow && m == monNow && d > dayNow)
    {
        return true;
    }

    return false;
}

bool isValidYear(int year)
{
    time_t now = time(nullptr);
    tm local
    {};
    localtime_r(&now, &local);
    int currentYear = local.tm_year + 1900;
    return year <= currentYear && year >= 1900;
}

bool isPositiveInt(int n) 
{
    return n >= 0;
}

bool isPositiveDouble(double n) 
{
    return n >= 0.0;
}

int safeInputInt(const string& message) 
{
    int val;
    while (true) 
    {
        cout << message;
        cin >> val;
        if (cin.fail() || val < 0) 
        {
            cout << "\nGiá trị không hợp lệ! Nhập lại!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else 
        {
            cin.ignore();
            return val;
        }
    }
}

bool isDuplicateMaHDNhap(const vector<HoaDonNhap>& ds, const string& maHD) 
{
    for (const auto& hd : ds) 
    {
        if (hd.getMaHD() == maHD)
            return true;
    }
    return false;
}

bool isValidFormatMaHDNhap(const string& maHD) 
{
    if (maHD.size() != 6) 
    {
        return false;
    }

    if (maHD[0] != 'H' || maHD[1] != 'D' || maHD[2] != 'N') 
    {
        return false;
    }

    for (size_t i = 3; i < maHD.size(); ++i) 
    {
        if (!isdigit(maHD[i]))
        {
            return false;
        }
    }

    return true;
}

bool isDateNotFuture(const string& dateStr) 
{
    int day, month, year;
    char sep1, sep2;
    stringstream ss(dateStr);
    if (!(ss >> day >> sep1 >> month >> sep2 >> year) || sep1 != '/' || sep2 != '/') 
    {
        cout << "\nĐịnh dạng ngày không hợp lệ! (dd/mm/yyyy)\n";
        return false;
    }

    time_t now = time(nullptr);
    tm local
    {};
    localtime_r(&now, &local);

    int currentYear = local.tm_year + 1900;
    int currentMonth = local.tm_mon + 1;
    int currentDay = local.tm_mday;

    if (year > currentYear) 
    {
        return false;
    }

    if (year == currentYear && month > currentMonth) 
    {
        return false;
    }

    if (year == currentYear && month == currentMonth && day > currentDay) 
    {
        return false;
    }

    return true;
}

bool isDuplicateMaMHDXuat(const vector<HoaDonXuat>& ds, const string& maHD) 
{
    for (const auto& hd : ds) 
    {
        if (hd.getMaHD() == maHD)
        {
            return true;
        }
    }
    return false;
}

bool isValidFormatMaHDXuat(const string& maHD) 
{

    if (maHD.size() != 6) 
    {
        return false;
    }

    if (maHD[0] != 'H' || maHD[1] != 'D' || maHD[2] != 'X')
    {
        return false;
    }

    for (size_t i = 3; i < maHD.size(); ++i) 
    {
        if (!isdigit(maHD[i]))
        {
            return false;
        }
    }

    return true;
}

string toLowerTrim(const string& s) 
{
    string result = s;
    result.erase(result.begin(), find_if(result.begin(), result.end(), [](unsigned char ch) 
    { return !isspace(ch); }));
    result.erase(find_if(result.rbegin(), result.rend(), [](unsigned char ch) 
    { return !isspace(ch); }).base(), result.end());
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

string toUpper(const string& s) 
{
    string result = s;
    transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

bool isDateLessOrEqual(const string& ngaySanXuat, const string& ngayNhap) 
{
    if (!isValidDateFormat(ngaySanXuat) || !isValidDateFormat(ngayNhap))
    {
        return false;
    }

    int d11 = stoi(ngaySanXuat.substr(0, 2));
    int m11 = stoi(ngaySanXuat.substr(3, 2));
    int y11 = stoi(ngaySanXuat.substr(6, 4));

    int d22 = stoi(ngayNhap.substr(0, 2));
    int m22 = stoi(ngayNhap.substr(3, 2));
    int y22 = stoi(ngayNhap.substr(6, 4));

    if (y11 < y22) return true;
    if (y11 > y22) return false;

    if (m11 < m22) return true;
    if (m11 > m22) return false;

    return d11 <= d22;
}

bool isExpired(const string& ngaySanXuat, const string& hanSuDung) 
{
    int d, m, y;
    char s1, s2;
    stringstream ss(ngaySanXuat);
    ss >> d >> s1 >> m >> s2 >> y;

    if (ss.fail()) 
    {
        return false;
    }

    time_t now = time(nullptr);
    tm local
    {};
    localtime_r(&now, &local);

    int today = local.tm_mday;
    int month = local.tm_mon + 1;
    int year = local.tm_year + 1900;

    int soThang = stoi(hanSuDung);
    int hetNam = y;
    int hetThang = m + soThang;
    int hetNgay = d;

    while (hetThang > 12) 
    {
        hetThang -= 12;
        hetNam++;
    }

    if (hetNam < year) 
    {
        return true;
    }

    if (hetNam == year && hetThang < month) 
    {
        return true;
    }

    if (hetNam == year && hetThang == month && hetNgay < today) 
    {
        return true;
    }
    
    return false;
}
