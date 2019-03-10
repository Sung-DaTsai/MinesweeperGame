#include <iostream>
#include "interface.h"
#include "problem.h"

using namespace std;

Interface::Interface()
 :ptr(new Problem())
{
	
}
void Interface::setprob(int a,int b)
{
    ptr->setprob(a,b);	
}
int Interface::getprob(int a)
{
    return ptr->getprob(a);	
}

Interface::~Interface()
{
	delete ptr;
} 

