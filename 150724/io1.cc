#include<iostream>

using namespace std;

void printCin()
{
	cout<<"bad="<<cin.bad()<<endl;
	cout<<"fail="<<cin.fail()<<endl;
	cout<<"eof="<<cin.eof()<<endl;
	cout<<"good="<<cin.good()<<endl;
}

int main(void)
{
	printCin();
}
