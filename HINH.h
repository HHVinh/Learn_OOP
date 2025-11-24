#ifndef HINH_H
#define HINH_H

#include <string>
using namespace std;

class HINH
{
    private:
        string tenHinh;
        string mauSac;
    
    public:
        HINH();
        ~HINH();
        virtual void nhapHinh();
        virtual double tinhChuVi() = 0;

};
#endif