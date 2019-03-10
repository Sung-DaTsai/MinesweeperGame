#include <iostream>

using namespace std;

#ifndef PROBLEM_H
#define PROBLEM_H

const int num=4;
class Problem
{
 public:
	Problem();
	void setprob(int,int);
	int getprob(int);
 private:
	int prob[num];
};
#endif
