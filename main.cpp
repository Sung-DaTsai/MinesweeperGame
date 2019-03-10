#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Safeinterface.h"
#include "Landmineinterface.h"
#include "interface.h"
const int num=4;
using namespace std;

int checklegal(int guess,int array[num]);
void checkABnum(Interface &,int array[num],int &);
const int num_mine=18;
const int totalx=12;
const int totaly=7;
int processingmap[totalx][totaly];  

void setmap();
void printmap(int,int,Landmineinterface &,Safeinterface &,int [][7]);
int main()
{
	int game;
	start:
	cout<<"Enter 1 to play Minesweeper, 2 to play A&B, instructions are given after your decision:";
	cin>>game;
	switch(game)
	{
	case 2:
	{
	char space;
	cout<<"Welcome to THE GAME of A&B\n";
	cout<<"Your goal is to figure out the four-digit number in order!!!\n";
	cout<<"However, it is anything but an easy task, you have to try as less time as possible\n"<<endl;
	cout<<"For example, you enter ""2348"" and get the result of 1A1B\n";
	cout<<"which means the number you enter has 1+1=2 numbers the same as the answer\n";
	cout<<"However, only one of them is at the right digit, another one is wrong\n";
	cout<<"Most important of all, the other two numbers don't exist in the answer!!!\nGood luck!!!\n\n";
	cout<<"\nNow press space twice and then enter button to start the game!!!";
	while((space=cin.get())!=32)
	{
		cout<<"Please press space twice and then enter button to start the game!!!";
		space=cin.get();
	}
	
	cout<<"\nGAME START"<<endl;
	cout<<"Please enter a four-digit number without any number repeated:\n";
		
	Interface problem;
	srand(time(0));
	int checkproblem;
	for(int i=0;i<num;i++)
	{
		do
		{
	 		checkproblem=0;
			problem.setprob(i,rand()%9+1);
			for(int j=0;j<i;j++)
			{
				if(problem.getprob(i)==problem.getprob(j))
					checkproblem++;
			}
		}
		while(checkproblem!=0);
	}
	int checkwin=0;
	int array[num];
	int guess=0;int countguess=0;
	while(checkwin!=1)
	{
		countguess++;
		do 
		{
			cout<<"\n("<<countguess<<"try): ";
			cin>>guess;
		}
		while(checklegal(guess,array)==0);
		checkABnum(problem,array,checkwin);			
	}
	cout<<"It takes you "<<countguess<<" times to get the answer!\n";	
	system("pause");
	return 0;
	}
	case 1:
	{
	int checkwin2=0;
	char space;
	int array[totalx][totaly];
	for(int i=0;i<12;i++)
	{
		for(int j=0;j<7;j++)
		{
			processingmap[i][j]=-2;
		}
	}
	Landmineinterface landmine;
	Safeinterface safe;
	cout<<"Welcome to THE GAME OF MINESWEEPER!!!\n\n";
	cout<<"The game will start briefly, now you can take a look at the array below:\n\n";
	setmap();
	cout<<"\nAs you can see, there are 12 rows and 7 columns, now you are going to "; 
	cout<<"go to great length to step on the position that doesn't have landmine. ";
	cout<<"However, there are 18 positions have landmines, you can't step on any of them,";
	cout<<" or the game will over!\nGood luck!!!";
	cout<<"\n\nHint:If you are tired of playing this game and you no longer want to play,";
	cout<<" input position row=-1, column=-1\n";
	cout<<"\nNow press space twice and then enter button to start the game!!!";
	while((space=cin.get())!=32)
	{
		cout<<"Please press space twice and then enter button to start the game!!!";
		space=cin.get();
	}

	cout<<"\nGAME START"<<endl;

	int over=1;
	while(over==1)
	{
		int a=15;
		int b=15;
		int number=0;

		cout<<"\nPlease enter the place you want to step, first enter which row (0~11):";  
		cin>>a;
		
		cout<<"Then enter which column (0~6):";  
		cin>>b;
		cout<<endl;

		if(a==-1&&b==-1)
		{
			cout<<"You terminate the game~\nWish you play again in the future!\a\n\n";
			system("pause");
			exit(1);
		}

		while(a>11||b>6||a<0||b<0)
		{
		    cout<<"The position is not valid,please enter another place again, first enter which row (0~11):";
			cin>>a;
			cout<<"Then enter which column (0~6):";  
			cin>>b;
			cout<<endl;

			if(a==-1&&b==-1)
			{
				cout<<"You terminate the game~\nWish you play again in the future!\a\n\n";
				a=1;
				b=1;
				system("pause");
				exit(1);
			}
		}

		printmap(a,b,landmine,safe,processingmap);
		checkwin2=0;
		
		if(checkover(a,b,landmine)==0)
		{
		    cout<<"\nHa Ha you lose~\nGAME OVER\a\n\n";
			over=0;
		}
		number++;

		for(int i=0;i<12;i++)
		{
			for(int j=0;j<7;j++)
			{
				if(processingmap[i][j]==-2)
			    checkwin2++;
			}
		}

		if(checkwin2==18)
		{
			cout<<"\nYou win!!!\n\n\a"<<endl;
		    over=0;	
		}
		
	}
	system("pause");
	return 0;
	}
    default:
    	cout<<"Invalid input, please enter 1 or 2 instead.\a\n\n";
	goto start;
	}
}

int checklegal(int guess,int array[num])
{
	for(int i=num-1;i>=0;i--)
	{
		array[i]=guess % 10;
		guess=(guess-array[i])/10;
		if(i==0)
		{
			if(guess!=0)
			{
				cout<<"Invalid number input,\a";
		    	cout<<" please enter a "<<'"'<<"four"<<'"'<<" digit number:\n";
            	return 0;
			}
		}
	}
	for(int i=0;i<num;i++)
	{
		if(array[i]==0||array[i]>9)
		{
			cout<<"Invalid number input,\a";
		    cout<<" please enter a"<<'"'<<"four"<<'"'<<" digit number without 0:\n";
            return 0;
		}
		for(int j=0;j<num;j++)
		{
			if(i!=j)
			{
				if(array[i]==array[j])
				{
					cout<<"Invalid number input,\a";
		            cout<<" please enter a four digit number without number repeated:\n";
				    return 0; 
				}
			}
		}
	}
}

void checkABnum(Interface &problem,int array[num],int &checkwin)
{
	int countA=0,countB=0;
	for(int i=0;i<num;i++)
	{
		if(problem.getprob(i)==array[i])
        countA++;
	}
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<num;j++)
		{
			if(i!=j)
			{
				if(problem.getprob(i)==array[j])
				countB++;
			}
		}
	}
	switch (countA)
    {
	 	case 4:
			cout << "BINGO!!\a\n"; 
			checkwin=1;
			break;
		default:
			cout <<"The result of this guessing:"<< countA << "A" << countB << "B\nTry again, please enter a four-digit number";
			break; 
	} 		
}

void setmap()
{
	cout<<" ";
	for(int i=0;i<7;i++)
	{
		cout<<setw(3)<<i;
	}
	cout<<"\n";
	for(int i=0;i<totalx;i++)
	{
		cout<<setw(2)<<i;
		for(int j=0;j<totaly;j++)
		{
			cout<<" - ";
		}
		cout<<"\n";
	}
}

void printmap(int x,int y,Landmineinterface &landmine,Safeinterface &safe,int processingmap[][7])
{
	cout<<" ";
	for(int i=0;i<7;i++)
	{
		cout<<setw(3)<<i;
	}
	cout<<"\n";
	
	int check=0;
	for(int i=0;i<num_mine;i++)
	{
		if(landmine.getx(i)==x&&landmine.gety(i)==y)
		{
			check++;
		}
	}
	
	processingmap[x][y]=safe.getrealmap(x,y);
		
	for(int i=0;i<totalx;i++)
	{
		cout<<setw(2)<<i;
		for(int j=0;j<totaly;j++)
		{
		    if(processingmap[i][j]==-2)
		    cout<<" - ";
			if(processingmap[i][j]!=-2&&processingmap[i][j]!=-1)
			{
				cout<<" "<<processingmap[i][j]<<" ";
			}
			if(processingmap[i][j]==-1)
			{
				cout<<" X ";
			}
		}
		cout<<"\n";
    }
	
}


