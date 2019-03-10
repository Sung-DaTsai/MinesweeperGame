#include <iostream>
using namespace std;

#ifndef LANDMINEINTERFACE_H
#define LANDMINEINTERFACE_H

class Landmine;

class Landmineinterface
{
	friend int checkover(int,int,Landmineinterface &);

 public:
 	Landmineinterface();
 	int getx(int) const;
 	int gety(int) const;
 	void setx(int,int);
 	void sety(int,int);
 	~Landmineinterface();
 private:
	Landmine *ptr;
	
};

#endif 
