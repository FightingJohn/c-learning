#ifndef _LYL_BUFFER_H
#define _LYL_BUFFER_H

#include<queue>
#include"Condition.h"
#include"MutexLock.h"

class Buffer
{
public:
	Buffer(int size);

	void push(int);
	int pop();
	
	bool empty();
	bool full();

private:
	MutexLock mutex_;
	Condition notfull_;
	Condition notempty_;
	int size_;
	std::queue<int> que_;
};

#endif
