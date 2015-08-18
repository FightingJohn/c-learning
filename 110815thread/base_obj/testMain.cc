#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>

#include"Thread.h"

class X
{
public:
	void getRandomNum()
	{
		srand(time(NULL));
		while(1)
		{
			int num = rand() % 100;
			std::cout<<"num(base_obj) = "<<num<<std::endl;
			sleep(1);
		}
	}

};

int main(void)
{
	X x;
	Thread thread(std::bind(&X::getRandomNum, x));
	thread.start();

	thread.join();
	return 0;
}
