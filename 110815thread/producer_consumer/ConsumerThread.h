#ifndef _LYL_CONSUMERTHEAD_H
#define _LYL_CONSUMERTHEAD_H


class Buffer;
class Consumer
{
public:
	Consumer(Buffer & buff);
	void consumeNum();
private:
	Buffer & buff_;

};

#endif
