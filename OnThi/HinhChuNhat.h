#ifndef HINHCHUNHAT_H
#define HINHCHUNHAT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "ToaDo.h"
#include "HinhHoc.h"

class HinhChuNhat : public HinhHoc
{
private:
    ToaDo m_A;
    ToaDo m_B;
    ToaDo m_C;
    ToaDo m_D;
public:
    HinhChuNhat(/* args */);
    ~HinhChuNhat();
    void nhapHinh() override;
    bool hinhYeuCau() override;
};

#endif