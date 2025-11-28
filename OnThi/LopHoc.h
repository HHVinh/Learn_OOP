#ifndef LOPHOC_H
#define LOPHOC_H
#include <iostream>
#include <string>
#include <vector>
#include "SinhVien.h"
using namespace std;

class LopHoc
{
private:
    vector<SinhVien> m_DanhSachSV;

public:
    LopHoc();
    ~LopHoc();
    void nhapThongTin();
    void xuatThongTin();
    void xuatSVGioi();
};



#endif