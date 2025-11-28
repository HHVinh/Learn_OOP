#ifndef HTRON_H
#define HTRON_H
#include <iostream>
#include <string>
using namespace std;
#include "MatPhang.h"

class HTron : public MatPhang
{
private:
    double m_banKinh;

public:
    HTron();
    ~HTron();

    void themHinh() override;
    double tinhChuVi() const override;
    double tinhDienTich() const override;
    void xuatHinh() const override;

};

#endif