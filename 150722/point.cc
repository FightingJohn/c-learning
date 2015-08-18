#include<iostream>

class Point
{
public:
	void print()
	{
		std::cout<<"("<<ix<<","<<iy<<")"<<std::endl;
	}

	void setPoint(int x,int y)
	{
		ix=x;
		iy=y;	
	}

private:
     int ix;
	int iy;
};

struct X
{
	int ix;
	int iy;
};

int main(void)
{
	Point p1;
	//std::cout<<p1.ix;
	p1.setPoint(3,4);
	p1.print();
	return 0;
}
