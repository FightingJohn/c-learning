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
#if 0
	Complex operator + (const Complex & lhs)
	{
		return Complex(dreal_+lhs.dreal_, dimag_+ lhs.dimag_);
	}
#endif
	Complex & operator += (const Complex &lrh)
	{
		dreal_ += lrh.dreal_;
		dimag_ += lrh.dimag_;
		return *this;
	}
	
private:
	double dreal_;
	double dimag_;
};

Complex operator + (const Complex &lsh, const Complex &rsh)
{
	Complex temp = lsh;
	temp+=rsh;
	return temp;
}


int main(void)
{
	Complex c1(1,2),c2(3,4),c3;
	c1.disp();
	c2.disp();
	cout<<"执行完加法后："<<endl;
	c3=c1+c2;
	c3.disp();
	cout<<"加后c1和c2的值："<<endl;
	c1.disp();
	c2.disp();
}
