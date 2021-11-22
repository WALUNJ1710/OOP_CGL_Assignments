

#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
class Pixel
{
  public:
	void plotPixel(int x,int y)
	{
		putpixel(x,y,WHITE);
	}
};


class Line : public Pixel
{
public:
	void drawLine(int x1,int y1,int x2,int y2,int d)//dda
	{
		int steps,i;
		float dx,dy,xinc,yinc,x,y;
		dx = abs(x2-x1);
		dy = abs(y2-y1);
		if(dx>dy) //gentle
		{
			steps = dx;
			xinc = dx/steps;
			yinc = dy/steps;
			plotPixel(x1,y1);
			x = x1;
			y = y1;

			for(i=1 ;i <= steps; i++)
			{
			  if(x1<x2)  //forward
			  {
			     x = x + xinc;
			     if(y1>y2)
				 y = y - yinc;
			     else
				 y = y + yinc;
			     plotPixel(x,y+0.5);
			  }
			  else   //backward
			  {
			     x = x - xinc;
			     if(y1>y2)
				  y = y - yinc;
			     else
				  y = y + yinc;
			     plotPixel(x,y+0.5);
			  }
			  delay(50);
			}

		}
		else   //steep
		{
			steps = dy;
			xinc = dx/steps;
			yinc = dy/steps;
			plotPixel(x1,y1);
			x = x1;
			y = y1;
			for(i=1 ;i <= steps; i++)
			{
			  if(y1<y2)  //forward
			  {
			     if(x1<x2)
				 x = x + xinc;
			     else
				 x = x - xinc;
			     y = y + yinc;
			     plotPixel(x+0.5,y);
			  }
			  else   //backward
			  {
			    if(x1<x2)
				x = x + xinc;
			    else
				x = x - xinc;
			     y = y - yinc;
			     plotPixel(x+0.5,y);
			  }
			  delay(50);
			}
		}
	}//end
	

};



int main()
{
	int gd = DETECT, gm,x1,x2,y1,y2;

initgraph(&gd,&gm,"c:/turboc3/bgi");
   Line l;
   cout<<"Enter line coordinates";
	cin>>x1>>y1>>x2>>y2;
	l.drawLine(x1,y1,x2,y2,1); //dda
	
	getch();
	closegraph();
	return 0;

}


