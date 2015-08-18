#ifndef _LYL_NONCOPYABLE
#define _LYL_NONCOPYABLE

class Noncopyable
{
protected:
	Noncopyable(){}

private:
	Noncopyable(const Noncopyable & rhs);
	Noncopyable & operator=(const Noncopyable & rhs);
};

#endif
