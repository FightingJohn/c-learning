#include"Thread.h"

void Thread::start()
{
	pthread_create(&pthId_, NULL, runInThread, this);
	isRunning_ = true;
}

void Thread::join()
{
	pthread_join(pthId_, NULL);
	isRunning_ = false;
}

Thread::~Thread()
{
	if(isRunning_)
	{
		pthread_detach(pthId_);
		isRunning_ = false;
	}
}

void *Thread::runInThread(void *arg)
{
	Thread *pThread = static_cast<Thread *>(arg);
	pThread->run();

	return NULL;
}
