#ifndef _LYL_CONDITION_H
#define _LYL_CONDITION_H

#include<pthread.h>
#include"Noncopyable.h"

class MutexLock;
class Condition : public Noncopyable
{
public:
	Condition(MutexLock & mutex);

	void wait();
	void notify();
	void notifyall();

	~Condition();

private:
	pthread_cond_t cond_;
	MutexLock & mutex_;
};

#endif
