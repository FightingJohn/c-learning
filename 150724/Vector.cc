#include<iostream>
#include<vector>

using namespace std;

char buf[1024];

void print(vector<int> &vec)
{
	cout<<"元素的个数为"<<vec.size()<<endl;
	cout<<"容器的容量为："<<vec.capacity()<<endl;
}

void printAll(vector<int> &vec)
{
	vector<int>::iterator it;
	for(it = vec.begin();it != vec.end();++it)
	{
		cout<< *it <<endl;
	}
}

int main(void)
{
	vector<int> vec;
	vec.push_back(1);
	print(vec);
	vec.push_back(2);
	print(vec);
	vec.push_back(3);
	print(vec);

	for(int i=0;i != vec.size(); ++i)
	{
		cout<<vec[i]<<endl;
	}
	cout<<endl;
	
	vec.pop_back();
	printAll(vec);
}
