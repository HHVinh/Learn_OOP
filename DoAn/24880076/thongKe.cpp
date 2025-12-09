#include <iostream>
#include "thongKe.h"
#include "quanLyMatHang.h"
#include "fileManager.h"

ThongKe::ThongKe()
{

}

ThongKe::~ThongKe()
{
    
}

void ThongKe::Update() 
{
    auto ds = QuanLyMatHang::getInstance()->getDanhSach();
    cout << "\nDữ liệu kho hàng đã thay đổi! Hiện có " << ds.size() << " mặt hàng trong kho!\n";
}