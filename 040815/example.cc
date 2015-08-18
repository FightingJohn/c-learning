#include<iostream>

using namespace std;

class SomeResource
{};

class Example
{
public:
	//如果p1_能顺利构造，而p2_不能顺利构造的情况下，
	//Example类对象就会构造失败，p1_会造成内存泄漏
	Example():p1_(new SomeResource()),p2_(new SomeResource())
	{
		cout<<"Creating Example, allocationg SomeResource"<<endl;
	}
	
	Example(const Example & other)
		:p1_(new SomeResource(*other.p1_)),
		 p2_(new SomeResource(*other.p2_))
	{
	}
	
	Example &operator=(const Example &other)
	{
		
	}
};
