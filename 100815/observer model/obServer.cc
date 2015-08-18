#include<iostream>
#include<algorithm>

#include"obServer.h"

void Subject::attach(Observer *pObserver)
{
	std::cout<<"Attach an Observer"<<std::endl;
	m_ListObserver.push_back(pObserver);
		
}

void Subject::detach(Observer *pObserver)
{
	std::list<Observer*>::iterator it;
	it = std::find(m_ListObserver.begin(), m_ListObserver.end(), pObserver);
	if(m_ListObserver.end() != it)
	{
		m_ListObserver.erase(it);
	}
	std::cout<<"Detach an Observer"<<std::endl;
}

void Subject::notify()
{
	std::cout<<"Notify Observer's State"<<std::endl;
	std::list<Observer*>::iterator it;
	for(it = m_ListObserver.begin(); it != m_ListObserver.end(); ++it)
	{
		(*it)->update(this);
	}
}

void Subject::setState(STATE nState)
{
	std::cout<<"setState by Object"<<std::endl;
	m_nSubjectState = nState;
}

STATE Subject::getState()
{
	std::cout<<"getState by Object"<<std::endl;
	return m_nSubjectState;
}

Subject::~Subject()
{
	std::list<Observer*>::iterator it,temp;
	for(it = m_ListObserver.begin(); it != m_ListObserver.end(); ++it)
	{
		temp = it;
		delete(*temp);
	}
	m_ListObserver.clear();
}

void ConcreateSubject::setState(STATE nState)
{
	std::cout<<"setState by ConcreateSubject"<<std::endl;
	m_nSubjectState = nState;
}

STATE ConcreateSubject::getState()
{
	std::cout<<"getState by ConcreateObject"<<std::endl;
	return m_nSubjectState;
}

void ConcreateObserver::update(Subject *pSubject)
{
	if(pSubject == NULL)
		return;
	m_nObserverState = pSubject->getState();
	std::cout<<"The ObserverState is"<<m_nObserverState<<std::endl;
}
