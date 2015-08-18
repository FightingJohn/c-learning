#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>

#include"Thread.h"

class WorkThread : public Thread
{
public:
	void run()
	{
		srand(time(NULL));
		while(1)
		{
			int num = rand() % 100;
			std::cout<<"num = "<<num<<std::endl;
			sleep(1);
		}
	}

};

int main(void)
{
	Thread *pthread = new WorkThread;
	pthread->start();

	pthread->join();
	return 0;
}
