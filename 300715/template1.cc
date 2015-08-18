#include<iostream>
#include<string.h>
using namespace std;

template<typename T>
T add(const T &a, const T &b)
{
	return a+b;
}
template<>
const char* add(const char* const &a, const char* const &b)
{
	char* temp = new char[strlen(a)+strlen(b)+1];
	strcpy(temp, a);
	strcat(temp, b);
	return temp;
}


int main(void)
{
	cout<<"10 + 20 = "<<add(10,20)<<endl;
	cout<<"1.0 + 3.0 = "<<add(1.0,3.0)<<endl;
	string s1 = "hello",s2 = ",world";
	cout<<"s1+s2 = "<<add(s1, s2)<<endl;
	const char* const pstr1 = "welcome";
	const char* const pstr2 = " to chaina";
	cout<<"pstr1 + pstr2 = "<<add(pstr1, pstr2)<<endl;
	
	return 0;
}
