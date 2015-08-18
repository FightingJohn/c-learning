#include<iostream>

using namespace std;

class CharArr
{
public:
	CharArr(int size):sz_(size),pBuf(new char[size]){}
	
	~CharArr()
	{
		delete []pBuf;
	}
	void getSz()
	{
		return sz_;
	}
private:
	int sz_;
	char *pBuf;
};

char &CharAr
