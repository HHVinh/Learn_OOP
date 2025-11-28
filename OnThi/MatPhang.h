#ifndef MATPHANG_H
#define MATPHANG_H
#include <iostream>
#include <string>
using namespace std;

class MatPhang
{
private:

public:
    MatPhang();
    virtual ~MatPhang();

    virtual void themHinh() = 0;
    virtual double tinhChuVi() const = 0;
    virtual double tinhDienTich() const = 0;
    virtual void xuatHinh() const = 0;
};

#endif