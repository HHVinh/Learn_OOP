#ifndef HINHHOC_H
#define HINHHOC_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class HinhHoc
{
private:

public:
    HinhHoc(/* args */);
    ~HinhHoc();
    virtual void nhapHinh() = 0;
    virtual bool hinhYeuCau() = 0;

};

#endif