#ifndef _WD_NESTED_H
#define _WD_NESTED_H

class Line
{
	class Impl;
public:
	Line(int x1, int y1, int x2, int y2);
	void printline();
private:
	Impl *pImpl;

};
#endif
