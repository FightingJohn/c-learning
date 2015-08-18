#include<iostream>
#include<string.h>
using namespace std;

class StaticFunc
{
private:
	char *name;
	float price_;
	static float total_price;

public:
	StaticFunc(const char *chr, const float p)
	{
		name = new char[strlen(chr)+1];
		strcpy(name, chr);
		price_=p;
		total_price+=p;
	}

	~StaticFunc()
	{
		if(name)
		{
			delete []name;
			name=NULL;
		}
		total_price-=price_;
	}
	
	static void print_total()
	{
		cout<<"总价为："<<total_price<<endl;
	}

	static void print(StaticFunc &com);
};

void StaticFunc::print(StaticFunc &com)
{
	cout<<"名称"<<com.name<<endl;
	cout<<"价格"<<com.price_<<endl;
}
float StaticFunc::total_price=0;

int main(void)
{
	StaticFunc com1("IBM",6000);
	StaticFunc::print(com1);
	StaticFunc::print_total();

	StaticFunc com2("MSI",10000);
	StaticFunc::print(com2);
	StaticFunc::print_total();
	
	com2.~StaticFunc();
	StaticFunc::print_total();

	return 0;
}
