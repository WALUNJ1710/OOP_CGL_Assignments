#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<stdio.h>

float oldx=10+0.7,oldy=340-0.5;

void drawkoch(float dir,float len,int iter)
{
	double dirRad = 3.142/180 * dir;
	float newX = oldx + len * cos(dirRad);
	float newY = oldy + len * sin(dirRad);
	if (iter==0)
	{       setcolor(RED);
		line(int(oldx),int(oldy),int(newX),int(newY));
		oldx = newX;
		oldy = newY;
	}
	else
	{
		iter--;
		//draw the four parts of the side _/\_
		drawkoch(dir, len, iter);
		dir += 60.0;
		drawkoch(dir, len, iter);
		dir -= 120.0;
		drawkoch(dir, len, iter);
		dir += 60.0;
		drawkoch(dir, len, iter);
	}
}


int main(void)
{
 int gd = DETECT, gm;

 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

 drawkoch(0.0,90,1);
 drawkoch(-120.0, 90, 1);
 drawkoch(120.0,90,1);
 flushall();
 getch();
 cleardevice();

 drawkoch(0.0,30,2);
 drawkoch(-120.0, 30, 2);
 drawkoch(120.0,30,2);
 flushall();
 getch();
 cleardevice();

 drawkoch(0.0,10,3);
 drawkoch(-120.0, 10, 3);
 drawkoch(120.0,10,3);
 flushall();
 getch();
 cleardevice();

 closegraph();
 return 0;
}