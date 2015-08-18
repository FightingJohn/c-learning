#include<iostream>
#include<list>

using namespace std;

int main(void)
{
	int arr[5] = {1,2,3,45,5};
	list<int> listInt(arr, arr+5);
	listInt.push_front(9);
	list<int>::iterator it;
	for(it=listInt.begin(); it!=listInt.end();++it)
	{
		cout<<*it<<' ';
	}
	cout<<endl;
}
