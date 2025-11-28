#ifndef TOADO_H
#define TOADO_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ToaDo
{
private:
    int m_X;
    int m_Y;
public:
    ToaDo(/* args */);
    ~ToaDo();
    void NhapToaDo();
    void InToaDo();
    double KhoangCach(const ToaDo& b);
    bool DiemTrenTrai();
    bool DiemTrenPhai();
    bool DiemDuoiTrai();
    bool DiemDuoiPhai();
    bool DiemToaDo();
    bool DiemTrucXTrai();
    bool DiemTrucXPhai();
    bool DiemTrucYTren();
    bool DiemTrucYDuoi();
};

#endif