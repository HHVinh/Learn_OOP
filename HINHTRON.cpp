#include <iostream>
#include <string>
using namespace std;
#include "HINHTRON.h"

HINHTRON::HINHTRON()
{
    banKinh = 0;
}

HINHTRON::~HINHTRON()
{
    
}

void HINHTRON::nhapHinh()
{   
    HINH::nhapHinh();
    cout << "Hàm nhập của HINHTRON\n";
    cout << "Nhập bán kính: ";
    cin >> banKinh;
}

double HINHTRON::tinhChuVi()
{
    return 2 * 3.14 * banKinh;
}