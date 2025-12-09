#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;

class Observer
{
protected:
	Subject* subject = nullptr;
	
public:
	virtual void Update(Subject* subject) = 0;
	virtual void setSubject(Subject* s);
	virtual ~Observer() = default;
};

#endif
