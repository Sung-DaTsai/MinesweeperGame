#include <iostream>
#include "problem.h"
using namespace std;

Problem::Problem()
{
	for(int i=0;i<4;i++)
		setprob(i,0);
}
void Problem::setprob(int a,int b)
{
    prob[a]=b;	
}
int Problem::getprob(int a)
{
    return prob[a];	
}

