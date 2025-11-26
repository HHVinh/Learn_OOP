#ifndef MAYCHIEU_H
#define MAYCHIEU_H

#include <iostream>
#include <string>
#include "ThongTinChung.h"
using namespace std;

class MayChieu : public ThongTinChung
{
    private:
        int m_doSang;
        double m_tiLeChieu;

    public:
        MayChieu();
        ~MayChieu();
        
        void getDeviceType() override;
        void displayInfo() override;
};

#endif