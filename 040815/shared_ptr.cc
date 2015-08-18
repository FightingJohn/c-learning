#include<iostream>
#include<memory>

using namespace std;

class Parent;
class Child;

typedef std::shared_ptr<Parent>parent_ptr;
typedef std::shared_ptr<Child>child_ptr;

class Child
{
public:
	Child(){cout<< "Child()..."<<endl;}
	~Child(){cout<< "~Child()..."<<endl;}
	parent_ptr parent_;
};

class Parent
{
public:
	Parent(){cout<< "Parent()..."<<endl;}
	~Parent(){cout<< "~Parent()..."<<endl;}
	weak_ptr<Child> child_;
};

int main(void)
{
	parent_ptr parent(new Parent);
	child_ptr child(new Child);
	parent->child_ = child;
	child->parent_ = parent;
	cout<<"parent.use_count = "<<parent.use_count()<<endl;
	cout<<"child.use_count = "<<child.use_count()<<endl;
}
