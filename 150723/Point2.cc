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
	const int ix_;
	const int iy_;//只能通过初始化列表进行初始化
};

int main(void)
{
	Point p1(4,5);
	p1.print();

	return 0;
}
