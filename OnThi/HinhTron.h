#ifndef HINHTRON_H
#define HINHTRON_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "ToaDo.h"
#include "HinhHoc.h"

class HinhTron : public HinhHoc
{
private:
    ToaDo m_Tam;
    double m_BanKinh;
public:
    HinhTron(/* args */);
    ~HinhTron();
    void nhapHinh() override;
    bool hinhYeuCau() override;
};

#endif