#ifndef _LYL_THREAD_H
#define _LYL_THREAD_H

#include<pthread.h>

class Thread
{
public:
	Thread():pthId_(0), isRunning_(false)
	{}

	void start();
	void join();
	virtual void run() = 0;
	
	~Thread();

	static void * runInThread(void *arg);

private:
	pthread_t pthId_;
	bool isRunning_;
};

#endif
