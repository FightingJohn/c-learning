#include<iostream>

using namespace std;

class Complex
{
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

Complex operator + (const Complex & lhs, const Complex & rhs)
{
	return Complex(lhs.dreal_+rhs.dreal_, lhs.dimag_+ rhs.dimag_);
}

int main(void)
{
	Complex c1(1,2),c2(3,4),c3;
	c1.disp();
	c2.disp();
	cout<<"执行完加法后："<<endl;
	c3=c1+c2;
	c3.disp();
	
}
