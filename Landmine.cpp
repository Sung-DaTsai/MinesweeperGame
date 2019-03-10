#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Landmine.h"
using namespace std;


Landmine::Landmine()
{
	for(int i=0;i<18;i++)
	{
		srand(time(0));
		setx(i,rand()%12);
		sety(i,rand()%7);
		for(int j=0;j<i;j++)
		{
			while(getx(i)==getx(j)&&gety(i)==gety(j))
			{
				setx(i,rand()%12);
				sety(i,rand()%7);
				j=0;
			}			
		}
	}
}


int Landmine::getx(int a) const
{
	return positionx[a];
}
int Landmine::gety(int a) const
{
	return positiony[a];
}

void Landmine::setx(int a,int b)
{
	positionx[a]=b;
}

void Landmine::sety(int a,int b)
{
	positiony[a]=b;
}

int checkover(int x,int y,Landmine &landmine) 
{
	int check=0;
	for(int i=0;i<18;i++)
	{
		if(landmine.positionx[i]==x&&landmine.positiony[i]==y)
		{
			check++;
		}
	}
	if(check==1)
		return 0;
    else
		return 1;
}



