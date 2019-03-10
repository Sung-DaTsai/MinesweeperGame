#include <iostream>
#include <iomanip>
#include "Safe.h"
#include "Safeinterface.h"
#include "Landmineinterface.h"
using namespace std;

Safeinterface::Safeinterface()
 :ptr1(new Safe())
{
	
}

int Safeinterface::getarrayx(int a) const
{
	return ptr1->getarrayx(a);
}

int Safeinterface::getarrayy(int a) const
{
	return ptr1->getarrayy(a);
}

int Safeinterface::getarraynum(int a) const
{
	return ptr1->getarraynum(a);
}

int Safeinterface::getrealmap(int a,int b) const
{
	return ptr1->getrealmap(a,b);
}

int Safeinterface::getmineplace(int a,int b) const
{
	return ptr1->getmineplace(a,b);
}

Safeinterface::~Safeinterface()
{
	delete ptr1;
}

void Safeinterface::setmineplace(int a,int b,int c)
{
	ptr1->setmineplace(a,b,c);
}

void Safeinterface::setrealmap(int a,int b,int c)
{
	ptr1->setrealmap(a,b,c);
}

void Safeinterface::setarrayx(int a,int b)
{
	ptr1->setarrayx(a,b);
}
void Safeinterface::setarrayy(int a,int b)
{
	ptr1->setarrayy(a,b);
}
void Safeinterface::setnumtoshow(int a,int b)
{
	ptr1->setnumtoshow(a,b);
}
