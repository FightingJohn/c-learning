#include<iostream>

using namespace std;

class Point
{
public:
	explicit Point(int ix=0,int iy=0):ix_(ix),iy_(iy)
	{
		cout<<"Point(x,y)"<<endl;
	}

	void print()
	{
		cout<<"("<<ix_<<","<<iy_<<")"<<endl;
	}
private:
	int ix_;
	int iy_;
};

int main(void)
{
	Point p = 1;
	p.print();

	return 0;
}
