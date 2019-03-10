#include <iostream>
#include <iomanip>
#include "Safe.h"
using namespace std;

Safe::Safe()
:Landmine()
{
	int i,j,k,c,d,r;
	int z=0;
	
	for(int i=0;i<12;i++)
	{
		for(j=0;j<7;j++)
		{
			setmineplace(i,j,0);
			for(k=0;k<18;k++)
			{
				if(Landmine::getx(k)==i&&Landmine::gety(k)==j)
				setmineplace(i,j,1);
			}
		}
	}
	
	for(int i=0;i<12;i++)
	{
		for(int j=0;j<7;j++)
		{
			if(getmineplace(i,j)==1)
			{
			    setrealmap(i,j,-1);
		    }
		    else 
			{
				if(getmineplace(0,0)==0)
			    	setrealmap(0,0,getmineplace(0,1)+getmineplace(1,1)+getmineplace(1,0));
			    	
    	        if(getmineplace(0,6)==0)
			    	setrealmap(0,6,getmineplace(0,5)+getmineplace(1,6)+getmineplace(1,5));
			    	
		   		if(getmineplace(11,0)==0)
		    		setrealmap(11,0,getmineplace(11,1)+getmineplace(10,0)+getmineplace(10,1));
		    		
		    	if(getmineplace(11,6)==0)
		    	    setrealmap(11,6,getmineplace(11,5)+getmineplace(10,6)+getmineplace(10,5));
			    	
				if(i==0&&j!=0&&j!=6)
					setrealmap(i,j,getmineplace(i,j+1)+getmineplace(i+1,j+1)+getmineplace(i+1,j)+getmineplace(i+1,j-1)+getmineplace(i,j-1));
								
				if(i==11&&j!=0&&j!=6)
					setrealmap(i,j,getmineplace(i,j+1)+getmineplace(i-1,j+1)+getmineplace(i-1,j)+getmineplace(i-1,j-1)+getmineplace(i,j-1));
				
				if(j==0&&i!=0&&i!=11)
					setrealmap(i,j,getmineplace(i,j+1)+getmineplace(i+1,j+1)+getmineplace(i+1,j)+getmineplace(i-1,j)+getmineplace(i-1,j+1));
				
				if(j==6&&i!=0&&i!=11)
					setrealmap(i,j,getmineplace(i,j-1)+getmineplace(i+1,j-1)+getmineplace(i+1,j)+getmineplace(i-1,j)+getmineplace(i-1,j-1));
				
				if(i!=0&&j!=0&&i!=11&&j!=6)
					setrealmap(i,j,getmineplace(i-1,j-1)+getmineplace(i-1,j)+getmineplace(i-1,j+1)+getmineplace(i,j-1)+getmineplace(i,j+1)+getmineplace(i+1,j-1)+getmineplace(i+1,j)+getmineplace(i+1,j+1));
			}			  
	    }
    }

	for(i=0;i<12;i++)
	{
		for(j=0;j<7;j++)
		{
			if(getrealmap(i,j)>=0)
			{
				setarrayx(z,i);
				setarrayy(z,j);
				setnumtoshow(z,getrealmap(i,j));
				z=z+1;
			}
		}
	}
	
	
}

int Safe::getarrayx(int a) const
{
	return positionx[a];
}
int Safe::getarrayy(int a) const
{
	return positiony[a];
}
int Safe::getarraynum(int a) const
{
	return numtoshow[a];
}

int Safe::getrealmap(int a,int b) const
{
	return realmap[a][b];
}
int Safe::getmineplace(int a,int b) const
{
	return mineplace[a][b];
}

void Safe::setmineplace(int a,int b,int c)
{
	mineplace[a][b]=c;
}

void Safe::setrealmap(int a,int b,int c)
{
	realmap[a][b]=c;
}

void Safe::setarrayx(int a,int b)
{
	positionx[a]=b;
}
void Safe::setarrayy(int a,int b)
{
	positiony[a]=b;
}
void Safe::setnumtoshow(int a,int b)
{
	numtoshow[a]=b;
}
