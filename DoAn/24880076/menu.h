#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "fileManager.h"

class Menu 
{
private:
    void menuLoaiHang();
    void menuMatHang();
    void menuHoaDonNhap();
    void menuThemHoaDonNhap();
    void menuHoaDonXuat();
    void myPause();
    
public:
    void docDuLieu();
    void hienThiMenu();

};

#endif