#include <iostream>
#include "Landmine.h"
#include "Landmineinterface.h"
using namespace std;


Landmineinterface::Landmineinterface()
 :ptr(new Landmine())
{

}


int Landmineinterface::getx(int a) const
{
	return ptr->getx(a);
}

int Landmineinterface::gety(int a) const
{
	return ptr->gety(a);
}

void Landmineinterface::setx(int a,int b)
{
	ptr->setx(a,b);
}

void Landmineinterface::sety(int a,int b)
{
	ptr->sety(a,b);
}


Landmineinterface::~Landmineinterface()
{
	delete ptr;
}


int checkover(int x,int y,Landmineinterface &landmine) 
{
	int check=0;
	for(int i=0;i<18;i++)
	{
		if(landmine.ptr->getx(i)==x&&landmine.ptr->gety(i)==y)
		{
			check++;
		}
	}
	if(check==1)
		return 0;
	else
		return 1;
}

