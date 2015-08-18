#include<iostream>

using namespace std;

template <class T, int num>
class Stack
{
private:
	T sz[num];
	int point;

public:
	Stack():point(0){}
	bool isEmpty();
	bool isFull();
	bool push(const T &data);
	bool pop(T &data);
	int &getPos()
	{
		return point;
	}
};

template<class T, int num>
bool Stack<T,num>::isFull()
{
	return point == num;
}


template<class T, int num>
bool Stack<T,num>::isEmpty()
{
	return point == 0;
}

template<class T, int num>
bool Stack<T,num>::push(const T &data)
{
	if(isFull())
		return false;
	else
	{
		sz[point] = data;
		point++;
		return true;
	}		
}

template<class T, int num>
bool Stack<T,num>::pop(T &data)
{
	if(isEmpty())	
		return false;
	else
	{
		point--;
		data = sz[point];
		return true;
	}
}

int main(void)
{
	Stack<int, 10>st;
	cout<<"st is null?"<<st.isEmpty()<<endl;

	st.push(5);
	cout<<"st is null?"<<st.isEmpty()<<endl;

	for(int i = 1;i<10; i++)
		st.push(i);
	
	cout<<"st is full?"<<st.isFull()<<endl;
	int rec = 0;
	while(st.pop(rec))
	{
		cout<<rec<<" ";
	}
	cout<<endl;
	return 0;
}
