#include<iostream>

using namespace std;

class Point;

class AnotherPoint
{
	friend ostream & operator <<(ostream &os,const AnotherPoint &ap);
	friend class Point;
public:
	AnotherPoint(double x=0.0, double y=0.0)
	:dx_(x),dy_(y){}
	
private:
	double dx_;
	double dy_;
};

class Point
{
	friend ostream & operator <<(ostream &os, const Point &p);
public:
	Point(int x=0, int y=0)
	{
		ix_ = x;
		iy_ = y;
	}
	
	operator int()
	{
		return ix_;
	}
	operator double()
	{
		return ix_ * iy_;
	}
	operator AnotherPoint()
	{
		return AnotherPoint(ix_, iy_);
	}

private:
	int ix_;
	int iy_;
};
ostream & operator <<(ostream &os, const AnotherPoint &ap)
{
	os<<"(("<<ap.dx_<<","<<ap.dy_<<")"<<endl;
}
ostream & operator <<(ostream &os, const Point &p)
{
	os<<(p.ix_*100)<<endl;
}

int main(void)
{
	Point p(5,6);
	cout<<"p="<<p;

	int x = p;
	cout<<"int_x="<<x<<endl;

	double dx=p;
	cout<<"double_p="<<dx<<endl;

	AnotherPoint ap;
	ap=p;
	cout<<"AnotherPoint="<<ap;
	return 0;
}
