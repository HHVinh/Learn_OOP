#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include <iostream>
#include "Observer.h"
using namespace std;

class Subject
{
private:
	vector<Observer*> observers;

public:
	void Attach(Observer* observer);
	void Detach(Observer* observer);
	virtual void Notify();
	virtual ~Subject();
};

#endif