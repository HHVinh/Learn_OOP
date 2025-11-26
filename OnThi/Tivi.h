#ifndef TIVI_H
#define TIVI_H

#include <iostream>
#include <string>
#include "ThongTinChung.h"
using namespace std;

class Tivi : public ThongTinChung
{
    private:
        double m_kichThuoc;
        string m_heDieuHanh;
        int m_kenhHienTai;

    public:
        Tivi();
        ~Tivi();
        
        void getDeviceType() override;
        void displayInfo() override;
};

#endif