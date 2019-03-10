#include <iostream>

using namespace std;

#ifndef INTERFACE_H
#define INTERFACE_H

class Problem;

class Interface
{
 public:
	Interface();
	void setprob(int,int);
	int getprob(int);
	~Interface();
 private:
	Problem *ptr;
};
#endif
