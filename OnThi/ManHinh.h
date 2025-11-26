#ifndef MANHINH_H
#define MANHINH_H

#include <iostream>
#include <string>
#include "ThongTinChung.h"
using namespace std;

class ManHinh : public ThongTinChung
{
    private:
        string m_doPhanGiai;
        int m_tangSoQuet;

    public:
        ManHinh();
        ~ManHinh();

        void getDeviceType() override;
        void displayInfo() override;
};

#endif