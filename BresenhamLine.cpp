

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
	
	void drawLine(int x1,int y1,int x2,int y2,char d)//bresenham
	{
		int x,y,i;
		float dx,dy,g;
		x = x1;
		y = y1;
		plotPixel(x,y);
		dx = abs(x2-x1);
		dy = abs(y2-y1);

		if(dx>dy) //gentle
		{
			g = 2*dy-dx;
			for(i = 1; i<= dx ; i++)
			{
				if(x1<x2)  //forward
				{
					x = x + 1;
					if(g>0)
					{
						if(y1<y2)
						   y = y + 1;
						else
						   y = y - 1;
						g = g + 2 * dy - 2 * dx;
					}
					else
					{
						g = g + 2 * dy;
					}
					plotPixel(x,y);
					delay(50);
				}
				else  //backward
				{
					x = x - 1;
					if(g>0)
					{
					      if(y1<y2)
						    y = y + 1;
					      else
						    y = y - 1;

						g = g + 2 * dy - 2 * dx;
					}
					else
					{
						g = g + 2 * dy;
					}
					plotPixel(x,y);
					delay(50);
				}

			}

		}
		else  //steep
		{
			g = 2*dx-dy;
			for(i = 1; i<= dy ; i++)
			{
				if(y1<y2)  //forward
				{
					y = y + 1;
					if(g>0)
					{
						if(x1<x2)
						    x = x + 1;
						else
						    x = x - 1;
						g = g + 2 * dx - 2 * dy;
					}
					else
					{
						g = g + 2 * dx;
					}
					plotPixel(x,y);
					delay(50);
				}
				else  //backward
				{
					y = y - 1;
					if(g>0)
					{
						if(x1<x2)
						   x = x + 1;
						else
						   x = x - 1;
						g = g + 2 * dx - 2 * dy;
					}
					else
					{
						g = g + 2 * dx;
					}
					plotPixel(x,y);
					delay(50);
				}

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
	
	l.drawLine(x1+10,y1+10,x2+10,y2+10,'b'); 

	getch();
	closegraph();
	return 0;

}


