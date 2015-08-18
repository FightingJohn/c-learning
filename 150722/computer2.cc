#include<iostream>
#include<string.h>

using namespace std;

class Computer
{
public:
	Computer(const char *pBrand, float fPrice)
	:fPrice_(fPrice)
	{
		pBrand_ = new char[strlen(pBrand)+1];
		strcpy(pBrand_,pBrand);
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
int main(void)
{
	{
	Computer pc1("lenovo",7000);
	pc1.print();
	}
	Computer *pc2 = new Computer("mac",10000);
	pc2->print();
	delete pc2;
}
