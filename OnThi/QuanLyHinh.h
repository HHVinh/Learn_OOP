#ifndef QUANLYHINH_H
#define QUANLYHINH_H
#include <iostream>
#include <string>
#include <vector>
#include "MatPhang.h"
using namespace std;

class QuanLyHinh
{
private:
    vector<MatPhang*> danhSachHinh;

public:
    QuanLyHinh();
    ~QuanLyHinh();

    void themHinh();
    void xuatHinh();
    void xoaTatCaHinh();
};

#endif