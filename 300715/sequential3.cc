#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(void)
{
	vector<string> vecstr;
	vecstr.push_back("this is A");
	
	cout<<"vecstr's capacity = "<<vecstr.capacity()<<endl;	
	vector<string>::iterator it;
	int i =9;
	vecstr.reserve(5);
	for(it = vecstr.begin(); it!=vecstr.end(); ++it)
	{
		cout<<*it<<endl;
		if(i==9)
		{
			vecstr.push_back("this is B");
		}	
		i=8;
		cout<<"vecstr's capacity = "<<vecstr.capacity()<<endl;	

	}
	return 0;
}
