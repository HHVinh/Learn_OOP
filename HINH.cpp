#include <iostream>
#include <string>
using namespace std;
#include "HINH.h"

// Hàm tạo k đối số
HINH::HINH()
{

}

// Hàm hủy
HINH::~HINH()
{

}

void HINH::nhapHinh()
{
    cout << "Hàm nhập của HINH\n";
    cout << "Nhập tên: ";
    cin.ignore();
    getline(cin, tenHinh);
    cout << "Nhập màu sắc: ";
    cin.ignore();
    getline(cin, mauSac);
}