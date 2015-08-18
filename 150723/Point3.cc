#include<iostream>

using namespace std;

class Point
{
public:
	Point(int ix=0,int iy=0):ix_(ix),iy_(iy)
	{
		cout<<"Point(x,y)"<<endl;
	}

	void print()const
	{
		ix_=3;
		cout<<"("<<ix_<<","<<iy_<<")"<<endl;
	}
private:
	int ix_;
	int iy_;
};

int main(void)
{
	Point p(6,7);
	p.print();

	return 0;
}
