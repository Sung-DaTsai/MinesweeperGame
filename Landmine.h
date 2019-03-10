#include <iostream>
using namespace std;

#ifndef LANDMINE_H
#define LANDMINE_H

class Landmine 
{
	friend int checkover(int,int,Landmine &);
 public:
 	Landmine();
 	int getx(int) const;
 	int gety(int) const;
 	void setx(int,int);
 	void sety(int,int);
 private:
	int positionx[18];
	int positiony[18];
};

#endif
