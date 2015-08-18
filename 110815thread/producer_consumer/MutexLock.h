#ifndef _LYL_MUTEXLOCK_H
#define _LYL_MUTEXLOCK_H

#include<pthread.h>
#include"Noncopyable.h"

class MutexLock : private Noncopyable
{
public:
	MutexLock();
	~MutexLock();

	void lock();
	void unlock();

	pthread_mutex_t * getMutexPtr();

private:
	pthread_mutex_t mutex_;
};

#endif
