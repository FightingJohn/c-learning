#include<iostream>
#include<set>

using namespace std;
int main(void)
{
	int arr[9] = {2, 4, 4, 5, 3, 6, 7, 8, 9};
	multiset<int,greater<int> > setInt(arr, arr+9);
	cout<<"set<int>'size() = "<<setInt.size()<<endl;
	multiset<int>::iterator iter = setInt.begin();
	for(; iter != setInt.end(); ++iter)
	{
		cout<<*iter<<' ';
	}
	cout<<endl;
}
