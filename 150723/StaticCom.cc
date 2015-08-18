#include<iostream>

using namespace std;

class StaticCom
{
private:
	float price_;
	static float total_price;

public:
	StaticCom(const float price)
	{
		price_=price;
		total_price+=price;
	}
	~StaticCom()
	{
		cout<<"退回一台电脑"<<endl;
		total_price-=price_;
	}

	void print()
	{
		cout<<"总价为："<<total_price<<endl;
	}

};

float StaticCom::total_price=0;

int main(void)
{
	StaticCom pc1(4500);
	cout<<"买入第一台电脑后"<<endl;
	pc1.print();

	StaticCom pc2(5500);
	cout<<"买入第二台电脑后"<<endl;
	pc2.print();
	pc2.~StaticCom();

	StaticCom pc3(3000);
	cout<<"买入第三台电脑后"<<endl;
	pc3.print();
	
	

	return 0;
}
