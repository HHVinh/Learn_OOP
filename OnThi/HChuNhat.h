#ifndef HCHUNHAT_H
#define HCHUNHAT_H
#include <iostream>
#include <string>
using namespace std;
#include "MatPhang.h"

class HChuNhat : public MatPhang
{
private:
    double m_chieuRong;
    double m_chieuDai;
public:
    HChuNhat();
    ~HChuNhat();

    void themHinh() override;
    double tinhChuVi() const override;
    double tinhDienTich() const override;
    void xuatHinh() const override;

};

#endif