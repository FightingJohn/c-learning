#include<iostream>
#include<vector>
#include<list>
#include<deque>

using namespace std;

int main(void)
{
	vector<int> vecInt;
	cout<<"vecInt的元素个数是："<<vecInt.size()<<endl;

	double darr[5] = {1,2,3,4,5};
	deque<double> deqDbl(darr, darr+5);

	for(size_t idx = 0; idx!=deqDbl.size(); ++idx)
	{
		cout<<deqDbl[idx]<<" ";
	}
	cout<<endl;

	deque<double>::iterator it = deqDbl.begin();
	cout<<"deqDbl = ";
	for(;it!=deqDbl.end(); ++it)
	{
		cout<< *it <<' ';
	}
	cout<<endl;
	
	list<float> listFlt(3,5);
	cout<<"listFlt = ";
	for(auto fval:listFlt)
	{
		cout<<fval<<' ';
	}
	cout<<endl;
	
	list<float> listFlt2(4,9);
	cout<<"listFlt2 = ";
	for(auto fval2:listFlt2)
	{
		cout<<fval2<<' ';
	}
	cout<<endl<<"交换数据后："<<endl;
	listFlt.swap(listFlt2);
	cout<<"listFlt2 = ";
	for(auto fval3:listFlt2)
	{
		cout<<fval3<<' ';
	}
	cout<<endl;
}
