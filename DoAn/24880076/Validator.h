#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include "loaiHang.h"
#include "matHang.h"
#include "hoaDonNhap.h"
#include "hoaDonXuat.h"
using namespace std;

bool isEmpty(const string& s);
int safeInputIntMenu(const string& message);
string toLowerTrim(const string& s);
string toUpper(const string& s);
bool isDuplicateMaLoai(const vector<LoaiHang>& ds, const string& maLoai);
bool isValidFormatMaLoai(const string& maLoai);
bool isDuplicateMaMatHang(const vector<MatHang>& ds, const string& maLoai);
bool isValidFormatMaMatHang(const string& maLoai);
bool isValidDateFormat(const string& date);
bool isFutureDate(const string& date);
bool isValidYear(int year);
bool isPositiveInt(int n);
bool isPositiveDouble(double n);
int safeInputInt(const string& message);
bool isDuplicateMaHDNhap(const vector<HoaDonNhap>& ds, const string& maLoai);
bool isValidFormatMaHDNhap(const string& maLoai);
bool isDateNotFuture(const string& dateStr);
bool isDuplicateMaMHDXuat(const vector<HoaDonXuat>& ds, const string& maHD);
bool isValidFormatMaHDXuat(const string& maLoai);
bool isDateLessOrEqual(const string& ngaySanXuat, const string& ngayNhap);
bool isExpired(const string& ngaySanXuat, const string& hanSuDung);

#endif
