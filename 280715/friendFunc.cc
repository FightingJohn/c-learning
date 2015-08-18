#include<iostream>
#include<math.h>
using namespace std;

class Point
{
	friend float dis(const Point &p1, const Point &p2);
	
public:
	Point():ix_(0),iy_(0){}
	Point(int ix, int iy):ix_(ix),iy_(iy){}
private:
	int ix_;
	int iy_;
};

float dis(const Point &p1, const Point &p2)
{
	float d = sqrt((p1.ix_-p2.ix_)*(p1.ix_-p2.ix_)+(p1.iy_-p2.iy_)*(p1.iy_-p2.iy_));
	return d;
}


int main(void)
{
	Point p1(1,2),p2(3,4);
	cout<<dis(p1,p2)<<endl;
	return 0;
}
