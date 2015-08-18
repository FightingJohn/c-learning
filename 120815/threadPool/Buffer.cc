#include "Buffer.h"

Buffer::Buffer(int size)
		:mutex_(),
		notfull_(mutex_),
		notempty_(mutex_),
		size_(size)
{}

bool Buffer::empty()
{
	return (que_.size() == 0);
}

bool Buffer::full()
{
	return (que_.size() == size_);
}

void Buffer::push(Task task)
{
	MutexLockGuard guard(mutex_);
	while(full())
		notfull_.wait();
	que_.push(task);
	notempty_.notify();
}

Buffer::Task Buffer::pop()
{
	MutexLockGuard guard(mutex_);
	while(empty())
		notempty_.wait();

	Task task = que_.front();
	que_.pop();
	notfull_.notify();
	return task;

}



