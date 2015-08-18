#ifndef _LYL_THREAD_H
#define _LYL_THREAD_H

#include<pthread.h>
#include"Noncopyable.h"
#include <functional>

class Thread : private Noncopyable 
{
public:
	typedef std::function<void()> ThreadCallback;
	Thread(ThreadCallback cb)
		:pthId_(0),
		isRunning_(false),
		cb_(cb)
	{}

	void start();
	void join();

//	virtual void run() = 0;
	~Thread();

	static void * runInThread(void *arg);

private:
	pthread_t pthId_;
	bool isRunning_;
	ThreadCallback cb_;
};

#endif
