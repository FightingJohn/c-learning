#include<iostream>
#include"obServer.h"

int main(void)
{
	Observer *p1 = new ConcreateObserver;
	Observer *p2 = new ConcreateObserver;
	
	Subject *ps = new ConcreateSubject;
	ps->attach(p1);
	ps->attach(p2);
	ps->setState(4);
	ps->notify();
	
	ps->detach(p1);
	ps->setState(10);
	ps->notify();

	delete ps;
	return 0;
}
