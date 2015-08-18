#include<iostream>

using namespace std;

class Complex
{
	friend ostream & operator <<(ostream &os, const Complex &rhs);
public:
	 Complex(double dreal = 0.0, double dimag = 0.0):
     dreal_(dreal),dimag_(dimag){}

	void disp()
	{
		cout<<dreal_<<"+"<<"*i"<<dimag_<<endl;
	}

	double dreal_;
	double dimag_;
};

ostream & operator <<(ostream &os, const Complex &rhs)
{
	cout<<rhs.dreal_<<"+"<<rhs.dimag_<<"*i"<<endl;
	return os;
}
int main(void)
{
	Complex c1(2,3);
	cout<< c1 ;	
}
