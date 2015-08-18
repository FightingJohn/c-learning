#include<unistd.h>
#include<iostream>
#include "ConsumerThread.h"
#include "Buffer.h"

Consumer::Consumer(Buffer & buff):buff_(buff)
{}

void Consumer::consumeNum()
{
	while(1)
	{
		int num = buff_.pop();
		std::cout<<"ConsumerThread get number : "<<num<<std::endl;
	sleep(2);
	}

}
