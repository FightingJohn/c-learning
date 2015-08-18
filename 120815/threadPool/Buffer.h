#ifndef _LYL_BUFFER_H
#define _LYL_BUFFER_H

#include "Condition.h"
#include "MutexLock.h"
#include <queue>
#include <functional>

class Buffer 
{
public:
	typedef std::function<void()> Task;
	Buffer(int size);

	void push(Task task);
	Task pop();
	
	bool empty();
	bool full();

private:
	MutexLock mutex_;
	Condition notfull_;
	Condition notempty_;
	int size_;
	std::queue<Task>que_;
};

#endif
