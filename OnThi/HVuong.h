#ifndef HVUONG_H
#define HVUONG_H
#include <iostream>
#include <string>
using namespace std;
#include "MatPhang.h"

class HVuong : public MatPhang
{
private:
    double m_chieuDaiCanh;

public:
    HVuong();
    ~HVuong();

    void themHinh() override;
    double tinhChuVi() const override;
    double tinhDienTich() const override;
    void xuatHinh() const override;

};

#endif