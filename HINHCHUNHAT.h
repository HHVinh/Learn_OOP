#ifndef HINHCHUNHAT_H
#define HINHCHUNHAT_H
#include "HINH.h"

class HINHCHUNHAT : public HINH
{
    private:
        double chieuDai;
        double chieuRong;
    
    public:
        HINHCHUNHAT();
        ~HINHCHUNHAT();
        void nhapHinh() override;
        double tinhChuVi() override;
};


#endif