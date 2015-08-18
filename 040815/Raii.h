#include<iostream>

template<typename T>
class RAII
{
public:
	explicit RAII(T *p):p_(p){}

	~RAII()
	{
		cout<<"~RAII()"<<endl;
		delete p_;
	}
}
