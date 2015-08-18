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
	Point(AnotherPoint ap)
	{
		ix_ = ap.dx_;
		iy_ = ap.dy_;
	}
private:
	int ix_;
	int iy_;
};
ostream & operator <<(ostream &os, const AnotherPoint &ap)
{
	os<<"("<<ap.dx_<<","<<ap.dy_<<")"<<endl;
}
ostream & operator <<(ostream &os, const Point &p)
{
	os<<"("<<p.ix_<<","<<p.iy_<<")"<<endl;
}

int main(void)
{
	Point p;
	p=5;
	cout<<5<<"转化为："<<p;

	double dx=1.2;
	p = dx;
	cout<<dx<<"转化为："<<p;

	AnotherPoint ap(12.34,56.78);
	p = ap;
	cout<<ap<<"转化为："<<p;
	return 0;
}
