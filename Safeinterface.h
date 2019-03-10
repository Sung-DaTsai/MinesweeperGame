#include <iostream>
#include "Landmineinterface.h"
using namespace std;

#ifndef SAFEINTERFACE_H
#define SAFEINTERFACE_H

class Safe;

class Safeinterface:public Landmineinterface
{
	friend void printmap(int,int,Landmineinterface &,Safeinterface &,int *[][7]);
 public:
 	Safeinterface();
    int getarrayx(int) const;
    int getarrayy(int) const;
    int getarraynum(int) const;
    int getrealmap(int,int) const;
    int getmineplace(int,int) const;
    void setmineplace(int,int,int);
    void setrealmap(int,int,int);
    void setarrayx(int,int);
    void setarrayy(int,int);
    void setnumtoshow(int,int);
    ~Safeinterface();
 private:
 	Safe *ptr1;
};

#endif
