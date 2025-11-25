#ifndef DONGHODIENTU_H
#define DONGHODIENTU_H
#include <iostream>
#include <string>
#include "Observer.h"
#include "ThoiGian.h"
using namespace std;

class DongHoDienTu : public Observer
{
    private:
        ThoiGian* m_subject;
    public:
    DongHoDienTu();
    ~DongHoDienTu();

    DongHoDienTu(ThoiGian* t);
    void Update() override;
};

#endif