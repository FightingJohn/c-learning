#include<iostream>
#include"ProducerThread.h"
#include"Buffer.h"

Producer::Producer(Buffer & buff):buff_(buff)
{}

void Producer::productNum()
{
	srand(time(NULL));
	while(1)
	{
		int num = rand() % 100;
		buff_.push(num);
		std::cout<<"Producer product a num : "
				<<num<<std::endl;
		sleep(1);
	}
}
