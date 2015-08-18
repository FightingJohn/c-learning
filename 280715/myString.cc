#include<iostream>

using namespace std;

class String
{
public:
	String();
	String(const String &rhs);
	String(const char *pstr);
private:
	char *pstr_;
};

String::String()
{
	pstr_ = new char[2];
	pstr_[1] = 1;
}

String::String(const char *pstr)
{
	size_t len = strlen(pstr);
	pstr_ = new char[len + 2];
	pstr_[len+1] = 1;
}

String::String(const String &rhs)
{
	pstr_ = rhs.pstr_;
	
}
