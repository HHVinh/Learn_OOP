#ifndef DONGHOKIM_H
#define DONGHOKIM_H
#include <iostream>
#include <string>
#include "Observer.h"
#include "ThoiGian.h"
using namespace std;

class DongHoKim : public Observer
{
    private:
        ThoiGian* m_subject;
    public:
    DongHoKim();
    ~DongHoKim();

    DongHoKim(ThoiGian* t);
    void Update() override;
};

#endif