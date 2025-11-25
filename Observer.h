#ifndef OBSERVER_H
#define OBSERVER_H
#include <iostream>
#include <string>
using namespace std;

class Observer
{
    private:

    public:
    Observer();
    ~Observer();
    virtual void Update() = 0;
};

#endif