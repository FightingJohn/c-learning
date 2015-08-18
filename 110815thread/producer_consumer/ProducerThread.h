#include<unistd.h>
#include<stdlib.h>
#include<time.h>

class Buffer;

class Producer
{
public:
	Producer(Buffer & buff);
	void productNum();

private:
	Buffer & buff_;
};
