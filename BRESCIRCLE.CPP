 #include <iostream.h>
 #include <conio.h>
 #include <graphics.h>
 #include <dos.h>


	// Part of Cosmos by OpenGenus Foundation
	class BresenhamCircle
	{
	public:
	    BresenhamCircle(int radius) : radius(radius)
	    {
	    }
	    void getRadiusCenter();
	    void drawBresenhamCircle();
	    void displayBresenhmCircle(int xc,int yc, int x, int y);
	private:
	    int radius;
	    int xc;
	    int yc;
	};

	void BresenhamCircle::drawBresenhamCircle()
	{
	    int x = 0, y = radius;
	    int decesionParameter = 3 - 2 * radius;
	    displayBresenhmCircle(xc, yc, x, y);
	    while (y >= x)
	    {
		x++;
		if (decesionParameter > 0)
		{
		    y--;
		    decesionParameter = decesionParameter + 4 * (x - y) + 10;
		}
		else
		    decesionParameter = decesionParameter + 4 * x + 6;
		displayBresenhmCircle(xc, yc, x, y); //displaying all the Eight Pixels of (x,y)
		delay(30);
	    }
	}
	void BresenhamCircle::getRadiusCenter()
	{
	    cout << "\nEnter Radius of the Circle : ";
	    cin >> radius;
	    cout << "\nEnter X-Coordinate of Center of Circle : ";
	    cin >> xc;
	    cout << "\nEnter Y-Coordinate of Center of Circle : ";
	    cin >> yc;
	}
	void BresenhamCircle::displayBresenhmCircle(int xc,int yc, int x, int y)
	{
	    //displaying all 8 coordinates of(x,y) residing in 8-octants
	    putpixel(xc+x, yc+y, WHITE);
	    putpixel(xc-x, yc+y, WHITE);
	    putpixel(xc+x, yc-y, WHITE);
	    putpixel(xc-x, yc-y, WHITE);
	    putpixel(xc+y, yc+x, WHITE);
	    putpixel(xc-y, yc+x, WHITE);
	    putpixel(xc+y, yc-x, WHITE);
	    putpixel(xc-y, yc-x, WHITE);
	}

	int main()
	{
	    int gd = DETECT, gm;

	    BresenhamCircle b(0);
	    //accepting the radius and the centre coordinates of the circle
	    b.getRadiusCenter();

	    initgraph(&gd, &gm,"c:\\TURBOC3\\BGI");

	    /*
	     * selecting the nearest pixel and displaying all the corresponding
	     * points of the nearest pixel point lying in 8-octants.
	     *
	     */
	    b.drawBresenhamCircle();
	    delay(200);
	    getch();
	    closegraph();
	    return 0;
        }
   