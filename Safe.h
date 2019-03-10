#include "Landmine.h"
#include "Landmineinterface.h"
#include "Safeinterface.h"

#ifndef SAFE_H
#define SAFE_H
using namespace std;
class Safe:public Landmine
{
	friend void printmap(int,int,Landmineinterface &,Safeinterface &,int [][7]);
 public:
 	Safe();
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
 private:
	int positionx[66];
	int positiony[66];
	int numtoshow[66];
	int mineplace[12][7];
	int realmap[12][7];

};

#endif
