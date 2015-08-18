#ifndef _LYL_NONCOPYABLE_
#define _LYL_NONCOPYABLE_

class Noncopyable
{
protected:
	Noncopyable(){}
private:
	Noncopyable(const Noncopyable & rhs);
	Noncopyable & operator=(const Noncopyable & rhs);
};

#endif
