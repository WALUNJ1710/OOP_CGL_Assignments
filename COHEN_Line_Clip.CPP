#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>

const int a=8, b=4, r=2, l=1;
int  xmin, ymin, xmax, ymax;

int calcode (int x,int y)
{
  int code = 0;
  if(y > ymax) 
	code |= a; //code = code | a;
  else if(y < ymin) 
	code |= b;
  else if(x>xmax) 
	code |= r;
  else if(x<xmin) 
	code |= l;
  return(code);
}

void lineclip(int x1,int y1,int x2,int y2)
{
   unsigned int code1,code2,codeout;
   int accept = 0, done=0;
   int cnt = 0;
   code1 = calcode(x1,y1);
   code2 = calcode(x2,y2);
   do
  {
    cnt++;
    if((code1 | code2) == 0)
    {
      accept =1 ;
      done =1;
    }
    else if((code1 & code2)!=0)
    {
        done = 1;
    }    
    else
    {
       float x,y;
       codeout = code1 ? code1 : code2;
       if(codeout & a)
      {
	 x = x1 + (ymax-y1)*(float)(x2-x1)/(y2-y1);
	 y = ymax;
      }
      else if(codeout & b)
     {
	 x=x1+(ymin-y1)*(float)(x2-x1)/(y2-y1);
	 y=ymin;
     }
     else if (codeout & r)
     {
	 y=y1+(xmax-x1)*(float)(y2-y1)/(x2-x1);
	 x=xmax;
     }
     else
     {
	 y=y1+(xmin-x1)*(float)(y2-y1)/(x2-x1);
	 x=xmin;
     }
     if(codeout == code1)
     {
	  x1 = x;
	  y1 = y;
	  code1=calcode(x1,y1);
     }
     else
     {
	  x2 = x; y2 = y;
	  code2 = calcode(x2,y2);}
     }
     cleardevice();
     cout << "Iteration:"<<cnt;
     cout << "\nLine portion processed till this iteration";
     rectangle(xmin,ymin,xmax,ymax);
     line(x1,y1,x2,y2);
     getch();
     cleardevice();
  } while( done == 0);
  if(accept)
  {
  	line(x1,y1,x2,y2);
  }
  rectangle(xmin,ymin,xmax,ymax);
}

void main()
{
     int x1,y1,x2,y2;
     int gd=DETECT,gm;
     clrscr();
     initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
     cout << "\nEnter the co-ordinates of Line:";
     cin >> x1 >> y1 >> x2 >> y2;
     cout << "\n\tEnter the co_ordinates of window:::\n ";
     cin >> xmin >> ymin >> xmax >> ymax;
     cleardevice();

     line(x1,y1,x2,y2);
     rectangle(xmin,ymin,xmax,ymax);
     getch();
     cleardevice();
     lineclip(x1,y1,x2,y2);
     getch();
     closegraph();
}
