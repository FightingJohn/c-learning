#include<iostream>

using namespace std;

class BaseClass
{
private:
	int a_;
public:
	BaseClass()
	{
		cout<<"BaseClass()"<<endl;
	}
};

class DerivedClass : public BaseClass
{
public:
	DerivedClass()
	{
		cout<<"DerivedClass()"<<endl;
	}

	DerivedClass(int x)
	{
		cout<<"DerivedClass(int )"<<endl;
	}
};

int main(void)
{
	DerivedClass dd(2);
}
