#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "Threadpool.h"

struct MyTask
{
	void operator()()
	{
		srand(time(NULL));
		int num = rand() % 100;
		std::cout<< "product a num: "<<num<<std::endl;
		sleep(2);
	}

};

int main(void)
{
	Threadpool threadpool(5, 4);
	threadpool.start();

	MyTask task;
	while(1)
	{
		threadpool.addTask(task);
		sleep(1);
	}
	threadpool.stop();
	return 0;
}
