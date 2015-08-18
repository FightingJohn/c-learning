#include<iostream>
#include<string.h>
#include<set>
#include<iterator>

using namespace std;

#pragma warning(disable:4996)//消除strcpy()的不安全警告

class CFlight
{
private:
	char m_flightNo[7];		//航班编号
	char m_fromCity[8];		//起飞城市
	char m_toCity[8];		//到达城市
	double m_distance;		//航线距离
	double m_price;			//机票单价

public:
	CFlight();				//默认构造函数

	char* getFlightNo();
	char* getFromCity();
	char* getToCity();
	double getDistance();
	double getPrice();

	void setFlightNo(char* p_szNo);
	void setFromCity(char* p_szFromCity);
	void setToCity(char* p_szToCity);
	void setDistance(double distance);
	void setPrice(double price);

	friend ostream& operator <<(ostream &os, const CFlight &oth);
	bool operator ==(const CFlight &oth);
	bool operator <(const CFlight &oth) const;

};

CFlight::CFlight()
{
	strcpy(this->m_flightNo, "");
	strcpy(this->m_fromCity, "");
	strcpy(this->m_toCity, "");
	this->m_distance = 0;
	this->m_price = 0;
}

char* CFlight::getFlightNo()
{
	return this->m_flightNo;
}
char* CFlight::getFromCity()
{
	return this->m_fromCity;
}
char* CFlight::getToCity()
{
	return this->m_toCity;
}
double CFlight::getDistance()
{
	return this->m_distance;
}
double CFlight::getPrice()
{
	return this->m_price;
}

void CFlight::setFlightNo(char* p_szNo)
{
	strcpy(this->m_flightNo, p_szNo);
}

void CFlight::setFromCity(char* p_szFromCity)
{
	strcpy(this->m_fromCity, p_szFromCity);
}

void CFlight::setToCity(char* p_szToCity)
{
	strcpy(this->m_toCity, p_szToCity);
}

void CFlight::setDistance(double distance)
{
	this->m_distance = distance;
}

void CFlight::setPrice(double price)
{
	this->m_price = price;
}

ostream& operator <<(ostream& os, const CFlight& oth)
{
	os.setf(ios::left, ios::adjustfield);		//设置为左对齐
	os<<" "<<oth.m_flightNo<<"     ";
	os<<oth.m_fromCity<<"     ";
	os<<oth.m_toCity<<"     ";
	os<<oth.m_distance<<"     ";
	os<<oth.m_price;
	return os;
}

bool CFlight::operator ==(const CFlight &oth)
{
	return (strcmp(this->m_flightNo, oth.m_flightNo) == 0);
}

bool CFlight::operator <(const CFlight &oth) const
{
	return (strcmp(this->m_flightNo, oth.m_flightNo) < 0);
}

void InputFlight(set<CFlight> &sf)
{
	char cChoose = '\0';
	cout<<"请录入航班信息！"<<endl;
	while(1)
	{
		CFlight flight;
		char flightNo[7] = {'\0'};
		char fromCity[8] = {'\0'};
		char toCity[8] = {'\0'};
		double distance = 0.0;
		double price = 0.0;
		cout<<"请输入航班编号：";
		cin.clear();				//清除状态
		cin.sync();					//清除缓冲区
		cin>>flightNo;
		while(flightNo[0]==' ')
				strcpy(flightNo, flightNo + 1);
		if(strlen(flightNo) <= 0)
		{
			cout<<"航班号不能为空，请重新输入！"<<endl;
			continue;
		}
		cout<<"请输入起飞城市：";
		cin.clear();
		cin.sync();
		cin>>fromCity;
		cout<<"请输入到达城市：";
		cin.clear();
		cin.sync();
		cin>>toCity;
		cout<<"请输入航线距离：";
		cin>>distance;
		cout<<"请输入机票单价：";
		cin>>price;
		flight.setFlightNo(flightNo);
		flight.setFromCity(fromCity);
		flight.setToCity(toCity);
		flight.setDistance(distance);
		flight.setPrice(price);
		if(sf.find(flight) != sf.end())
		{
			cout<<"该航班已经存在了，请重新输入！"<<endl;
			continue;
		}
		sf.insert(flight);
		cout<<"录入航班成功！是否继续录入？（Y/N）：";
		cin>>cChoose;
		if(cChoose != 'y' && cChoose != 'Y')
			break;
	}	
	
}

void showAllFlight(set<CFlight> &sf)
{
	cout<<endl;
	cout<<"\t\t<航班信息如下>"<<endl;
	cout<<"------------------------------------"<<endl;
	cout<<" 航班编号 "<<" 起飞城市 "<<" 到达城市 "<<" 航线距离 "<<" 机票单价 "<<endl;
	set<CFlight>::iterator it;
	for(it = sf.begin(); it != sf.end(); it++)
	{
		cout<<(*it)<<endl;
	}
	cout<<"------------------------------------"<<endl;

}

int main()
{
	set<CFlight> sf;
	InputFlight(sf);

	showAllFlight(sf);
	return 0;
}
