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
    
	~Computer()
	{
		cout<<"~computer()"<<endl;
		delete []pBrand_;
	}
private:
	char *pBrand_;
	float fPrice_;
};

Computer getComputer()
{
         Computer pc("mac",10000);
		return pc;
}
int main(void)
{
	Computer pc1("dell",6000);
	pc1.print();

	Computer pc2=pc1;
	pc2.print();
	
	getComputer();
}
