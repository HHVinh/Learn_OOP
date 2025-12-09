#include <algorithm>
#include <iostream>
#include "subject.h"
#include "Observer.h"

void Subject::Attach(Observer* observer) 
{
    if (std::find(observers.begin(), observers.end(), observer) == observers.end()) 
    {
        observers.push_back(observer);
    }
}

void Subject::Detach(Observer* observer) 
{
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) 
    {
        observers.erase(it);
    }
}

void Subject::Notify() 
{
    for (auto* obs : observers)
    {
        if (obs) obs->Update(this);
    }
}

Subject::~Subject() 
{
    observers.clear();
}
