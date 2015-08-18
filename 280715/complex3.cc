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
	
	void print()
	{
		cout<<"dreal="<<dreal_<<"  dimag="<<dimag_<<endl;
	}

	Complex & operator ++()
	{
		++dreal_;
		++dimag_;
		return *this;
	}

	Complex operator ++(int)
	{
		Complex temp = *this;
		dreal_++;
		dimag_++;
		return temp;
	}
private:
	double dreal_;
	double dimag_;
};


int main(void)
{
	Complex c1(1,2),c2;
	c1.disp();
	c2=c1++;
	cout<<"x++演示：";
	c2.disp();
	c1.disp();
	c2=++c1;
	cout<<"++x演示：";
	c2.disp();
	c1.disp();
}
