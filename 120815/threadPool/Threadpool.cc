#include "Threadpool.h"
#include "Thread.h"

Threadpool::Threadpool(int bufsize, int threadNum)
		:size_(bufsize),
		buffer_(size_),
		threadNum_(threadNum),
		vecThreads_(threadNum_),
		isExit_(false)
{}

Threadpool::~Threadpool()
{
	stop();
}

void Threadpool::start()
{
	for(int idx = 0; idx != threadNum_; ++idx)
	{
		Thread *pthread = new Thread(
				std::bind(&Threadpool::threadFunc, this));
		vecThreads_.push_back(pthread);
		pthread->start();
	}
}

void Threadpool::stop()
{
	if(!isExit_)
	{
		isExit_ = true;
		std::vector<Thread*>::iterator iter;
		for(iter = vecThreads_.begin(); iter != vecThreads_.end(); ++iter)
		{
			(*iter)->join();
			delete *iter;
		}
		vecThreads_.clear();

	}
}

void Threadpool::addTask(Task task)
{
	buffer_.push(task);
}

Threadpool::Task Threadpool::getTask()
{
	return buffer_.pop();
}

void Threadpool::threadFunc()
{
	while(!isExit_)
	{
		Task task = getTask();
		if(task != NULL)
		{
			task();
		}
	}
}
