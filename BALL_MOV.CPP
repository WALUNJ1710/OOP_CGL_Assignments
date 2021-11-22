#include "graphics.h"
#include<process.h>
#include<dos.h>
#include<conio.h>
#include<iostream.h>

class Animate
{
	public:
		void animation(int r);
		void animation(int xr, int yr);
		
};

void Animate ::animation(int r)
{
	int i=250,j=250,x=0,y=-1,ch;

	while(1)                                                               //infinite
	{
		circle(i,j,r);
		outtextxy(400,400,"Press Esc to Exit");
	       //	flushall();
		if(kbhit())          //check
		{
		      ch=getch();
		      if(ch==49)     //move upward
		      {
			x=0;
			y=-1;
		      }
		      if(ch==50)     //move left
		      {
			x=-1;
			y=0;
		      }
		      if(ch==51)    //move right
		      {
			x=1;
			y=0;
		      }
		      if(ch==52)                           //move down
		      {
			x=0;
			y=1;
		      }
		      if(ch==27)                     //exit when esc pressed                                                                               exit(0);
			exit(0);
		}
		i=i+x;
		j=j+y;
		delay(50);
		cleardevice();
	}
}

void Animate ::animation(int xr, int yr)
{
	int i=250,j=250,x=0,y=-1,ch;
	while(1)                                                               //infinite
	{
		ellipse(i,j,0,360,xr,yr);
		outtextxy(400,400,"Press Esc to Exit");
	       //	flushall();
		if(kbhit())          //check
		{
		      ch=getch();
		      if(ch==49)     //move upward
		      {
			x=0;
			y=-1;
		      }
		      if(ch==50)     //move left
		      {
			x=-1;
			y=0;
		      }
		      if(ch==51)    //move right
		      {
			x=1;
			y=0;
		      }
		      if(ch==52)                           //move down
		      {
			x=0;
			y=1;
		      }
		      if(ch==27)                     //exit when esc pressed                                                                               exit(0);
			exit(0);
		}
		i=i+x;
		j=j+y;
		delay(50);
		cleardevice();
	}
}

void main()
{
	Animate a1;
	int ch,r,xr,yr,gd=DETECT,gm;
	char ans;
	do
	{
		clrscr();
		cout<<"\nAnimation";
		cout<<"\n 1. Circle Animation";
		cout<<"\n 2. Ellipse Animation";
		cout<<"\n 3. Exit";
		cout<<"\nEnter your choice";
		cin>>ch;
		initgraph(&gd,&gm,"c:\\turboc3\\bgi");
		switch(ch)
		{
			case 1: cout<<"\nEnter the radius of circle:";
				cin>>r;
				a1.animation(r);
				break;
			case 2: cout<<"\nEnter the xradius and yradius of ellipse:";
				cin>>xr>>yr;
				a1.animation(xr,yr);
				break;
			case 3: exit(0);
			default: cout<<"\nWrong Input";
		}
		getch();
		closegraph();
                cout<<"\n Do you wish to continue(Y/N):";
		cin>>ans;
	}while(ans=='Y' || ans == 'y');
}
