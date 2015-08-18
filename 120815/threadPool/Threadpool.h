#ifndef _LYL_THREADPOOL_H
#define _LYL_THREADPOOL_H

#include <vector>
#include "Buffer.h"
#include <functional>

class Thread;

class Threadpool
{
public:
	typedef std::function<void()> Task;
	
	Threadpool(int bufsize, int threadNum);
	~Threadpool();

	void start();
	void stop();
	
	void addTask(Task task);
	Task getTask();
	
	void threadFunc();

private:
	int size_;
	Buffer buffer_;
	int threadNum_;
	std::vector<Thread*> vecThreads_;
	bool isExit_;
};

#endif
