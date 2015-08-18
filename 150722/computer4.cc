#include<iostream>
#include<string.h>

using namespace std;

class Computer
{
public:
	Computer(const char *pBrand, float fPrice)
	:fPrice_(fPrice)
	{
		cout<<"构造函数"<<endl;
		pBrand_ = new char[strlen(pBrand)+1];
		strcpy(pBrand_,pBrand);
	}
	
	Computer(Computer & res):fPrice_(res.fPrice_)
	{
		cout<<"复制构造函数"<<endl;
		pBrand_ = new char[strlen(res.pBrand_)+1];
		strcpy(pBrand_,res.pBrand_);
	}

	void print()
	{
		cout<< "computer is "<<pBrand_<<endl;
		cout<< "price is "<<fPrice_<<endl;
	}
    
	Computer & operator=(const Computer & rhs)
	{
		if(this == &rhs)//处理发生自复制
			return *this;
		delete []pBrand_;
		pBrand_ = new char[strlen(rhs.pBrand_)+1];
		strcpy(pBrand_,rhs.pBrand_);
		fPrice_=rhs.fPrice_;
		return *this;

	}
	~Computer()
	{
		cout<<"~computer()"<<endl;
		delete []pBrand_;
	}
private:
	char *pBrand_;
	float fPrice_;
};

int main(void)
{
	Computer pc1("dell",6000);
	pc1.print();

	Computer pc2("acer",3000);
	pc2=pc1;
}
