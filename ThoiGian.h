#ifndef THOIGIAN_H
#define THOIGIAN_H
#include <iostream>
#include <string>
#include "Subject.h"
using namespace std;

class ThoiGian : public Subject
{
    private:
        int m_gio;
        int m_phut;
        int m_giay;
    public:
    ThoiGian();
    ~ThoiGian();

    void SetTime(int gio, int phut, int giay);
    void Notify() override;
    int GetHour();
    void Update() override;
};

#endif