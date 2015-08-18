#include<iostream>
#include<string.h>

using namespace std;

int main(void)
{
	string str = "hello,world";
	cout<<"strlen() = "<<strlen(str.data())<<endl;
	cout<<"sizeof() = "<<sizeof(str)<<endl;
	return 0;
}
