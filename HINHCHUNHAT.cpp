#include <iostream>
#include <string>
using namespace std;
#include "HINHCHUNHAT.h"

HINHCHUNHAT::HINHCHUNHAT()
{
    chieuDai = 0;
    chieuRong = 0;
}

HINHCHUNHAT::~HINHCHUNHAT()
{

}

void HINHCHUNHAT::nhapHinh()
{
    HINH::nhapHinh();
    cout << "Hàm nhập của HINHCHUNHAT\n";
    cout << "Nhập chiều dài: ";
    cin >> chieuDai;
    cout << "Nhập chiều : ";
    cin >> chieuRong;
}

double HINHCHUNHAT::tinhChuVi()
{
    return (chieuDai + chieuRong) * 2;
}