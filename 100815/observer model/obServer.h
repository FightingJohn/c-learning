#ifndef _MY_OBSERVER_
#define _MY_OBSERVER_

#include<list>

typedef int STATE;

class Observer;

class Subject
{
public:
	Subject():m_nSubjectState(-1){}
	virtual ~Subject();

	void notify();
	void attach(Observer *pObserver);	
	void detach(Observer *pObserver);
	
	virtual void setState(STATE nState);
	virtual STATE getState();	

protected:
	STATE m_nSubjectState;
	std::list<Observer*> m_ListObserver;
};

class Observer
{
public:
	Observer():m_nObserverState(-1){}
	virtual ~Observer(){};

	virtual void update(Subject *pSubject) = 0;

protected:
	STATE m_nObserverState;
};

class ConcreateSubject : public Subject
{
public:
	ConcreateSubject():Subject(){}
	virtual ~ConcreateSubject(){}

	virtual void setState(STATE nState);
	virtual STATE getState();
};

class ConcreateObserver : public Observer
{
public:
	ConcreateObserver():Observer(){}
	virtual ~ConcreateObserver(){}
	
	virtual void update(Subject *pSuject);
};

#endif
