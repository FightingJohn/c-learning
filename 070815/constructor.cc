#include<iostream>

using namespace std;

class A
{
public:
	A(int ix):ix_(ix)
	{
		cout<<"A():A(int x)"<<endl;
	}
	
	~A()
	{
		cout<<"A():~A()"<<endl;
	}

private:
	int ix_;
};

class B : public A
{
public:
	B(int ix):A(ix)
	{
		cout<<"B():B(int x)"<<endl;
	}
	
	~B()
	{	
		cout<<"B()::~B()"<<endl;
	}
};

class C : public 
