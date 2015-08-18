#include "ProducerThread.h"
#include "ConsumerThread.h"
#include "Buffer.h"
#include "Thread.h"

int main(void)
{
	Buffer buffer(5);
	Producer producer(buffer);
	Consumer consumer(buffer);
	
	Thread * pProducer = new Thread(
			std::bind(&Producer::productNum, producer));
	Thread * pConsumer = new Thread(
			std::bind(&Consumer::consumeNum, consumer));

	pProducer->start();
	pConsumer->start();

	pProducer->join();
	pConsumer->join();

	return 0;
}
