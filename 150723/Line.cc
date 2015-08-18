#include<iostream>

using namespace std;

class Point
{
public:
	Point(int ix=0,int iy=0):ix_(ix),iy_(iy)
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

class Line
{
private:
	Point pt1;
	Point pt2;
public:
	Line(int x1, int y1, int x2, int y2)
	:pt1(x1, y1),pt2(x2, y2)
	{
		cout<<"Line(x1,y1,x2,y2)"<<endl;
	}

	void draw()
	{
		pt1.print();
		cout<<"to"<<endl;
		pt2.print();
	}
};

int main(void)
{	
	Line l1(1,2,3,4);
	l1.draw();

	return 0;
}
