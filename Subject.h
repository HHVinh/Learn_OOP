#ifndef SUBJECT_H
#define SUBJECT_H
#include <iostream>
#include <string>
#include "Observer.h"
using namespace std;

class Subject : public Observer
{
    private:
        Observer* m_danhSach[100];
        int m_soLuong;
    public:
    Subject();
    ~Subject();

    virtual void Attach(Observer* observer);
    virtual void Detach(Observer* observer);
    virtual void Notify() = 0;
};

#endif