#include"Buffer.h"

Buffer::Buffer(int size)
		:mutex_(),notfull_(mutex_),notempty_(mutex_),size_(size)
	{}

bool Buffer::empty()
{
	return (que_.size() == 0);
}

bool Buffer::full()
{
	return (que_.size() == size_);
}

void Buffer::push(int num)
{
	mutex_.lock();			//防止多线程同时请求wait（）
	while(full())
		notfull_.wait();
	que_.push(num);
	mutex_.unlock();
	notempty_.notify();	
}

int Buffer::pop()
{
	mutex_.lock();
	while(empty())
		notempty_.wait();
	int num = que_.front();
	que_.pop();
	mutex_.unlock();
	notfull_.notify();
	return num;
}



