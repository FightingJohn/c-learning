#include<iostream>
#include<stdio.h>
//1.Singleton不能为栈对象，只能通过堆对象
//2.不能直接通过new表达式来创建对象
//3.位于public区域func()不能是普通成员函数
using namespace std;

class Singleton
{
public:
	static Singleton * getInstance()
	{
		if(pInstance == NULL)
		{
			pInstance = new Singleton;
		}
		return pInstance;
	}
private:
	Singleton()
	{
		cout<<"Singleton"<<endl;
	}
private:
	static Singleton *pInstance;
};

Singleton* Singleton::pInstance = NULL;

int main(void)
{
	Singleton *s1 = Singleton::getInstance();
	Singleton *s2 = Singleton::getInstance();
	printf("%x\n",s1);
	printf("%x\n",s2);
}
