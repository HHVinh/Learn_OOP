#ifndef HINHTRON_H
#define HINHTRON_H
#include "LOPDIEM3.h"
#include "HINH.h"


class HINHTRON : public HINH
{
    private:
        double banKinh;
    public:
        HINHTRON();
        ~HINHTRON();
        void nhapHinh() override;
        double tinhChuVi() override;

};

#endif