#include<iostream>

using namespace std;

class Point
{
public:
	Point(int ix = 0, int iy = 0):ix_(ix),iy_(iy)
	{
		cout<<"Point(int x, int y)"<<endl;
	}

	void print()
	{
		cout<<"("<<ix_<<" , "<<iy_<<")"<<endl;
	}
	
	int getX()
	{
		return ix_;
	}
	int getY()
	{
		return iy_;
	}
private:
	int ix_;
	int iy_;
	
};

class Print3D : private Point
{
public:
	Print3D(int x, int y, int z):Point(x , y),iz_(z){}
	
	void print()
	{
		cout<<"("<<getX()<<" , "<<getY()<<" , "<<iz_<<")"<<endl;
	}

	int sum()
	{
		return getX()+getY()+iz_;
	}
private:
	int iz_;
};

int main(void)
{
	Print3D p(3,4,5);
	cout<<"p.getX() = "<<p.getX()<<endl;
	cout<<"p.sum() = "<<p.sum()<<endl;
	p.print();
}
