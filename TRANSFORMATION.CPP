#include<iostream.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>

class Matrix
{
	float A[20][3];
	int n,tx,ty,sx,sy,th;
	public:
		void getdata();
		void unit();
		Matrix operator*(Matrix x);
		void translation();
		void scaling();
		void rotation();
		void display();
};

void Matrix :: getdata()
{
	int i;
	cout<<"\nEnter the number of vertices";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\n enter the values of (x"<<i+1<<",y"<<i+1<<"):";
		cin>>A[i][0]>>A[i][1];
		A[i][2] = 1;
	}
}

Matrix Matrix :: operator*(Matrix x)
{
	Matrix t;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			t.A[i][j] = 0;
			for (int k = 0; k < 3; k++)
			{
				t.A[i][j] = t.A[i][j] + (A[i][k] * (x.A[k][j]));
			}
		}
	}
	t.n = n;
	return  t;
}

void Matrix :: unit()
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==j)
				A[i][j] = 1;
			else
				A[i][j] = 0;
		}
	}
}

void Matrix :: translation()
{
	cout<<"\nEnter the value of tx and ty";
	cin>>tx>>ty;
	A[2][0] = tx;
	A[2][1] = ty;
}

void Matrix :: scaling()
{
	cout<<"\nEnter the value of sx and sy";
	cin>>sx>>sy;
	A[0][0]=sx;
	A[1][1]=sy;
}

void Matrix :: rotation()
{
	float rth;
	cout<<"\nEnter the value of angle";
	cin>>th;
	rth = (3.142/180) * th;
	A[0][0] = A[1][1] = cos(rth);
	A[1][0] = -sin(rth);
	A[0][1] = sin(rth);
}

void Matrix :: display()
{
	int i;

	line(320,0,320,480);
	line(0,240,640,240);
	for(i=0;i<n-1;i++)
		line(A[i][0]+320,240-A[i][1],A[i+1][0]+320,240-A[i+1][1]);
	line(A[n-1][0]+320,240-A[n-1][1],A[0][0]+320,240-A[0][1]);
}

int main()
{
	Matrix obj,trf,res;
	int gd = DETECT, gm,i,ch;
	char ans;
	do
	{
		clrscr();
		cout<<"\nTRANSFORMATIONS";
		cout<<"\n 1. Translation";
		cout<<"\n 2. Scaling";
		cout<<"\n 3. Rotation";
		cout<<"\n 4. Exit;";
		cout<<"\nEnter your choice";
		cin>>ch;
		initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
		obj.getdata();
		cleardevice();
		cout<<"\nBefore transformation";
		obj.display();
		getch();
		cleardevice();
		switch(ch)
		{
			case 1: trf.unit();
				trf.translation();
				res = obj * trf;
				res.display();
				break;
			case 2: trf.unit();
				trf.scaling();
				res = obj * trf;
				res.display();
				break;
			case 3: trf.unit();
				trf.rotation();
				res = obj * trf;
				res.display();
				break;
			case 4:
			default: cout<<"\nWrong Input";
		}
		getch();
		closegraph();
                cout<<"\n Do you wish to continue(Y/N):";
		cin>>ans;
	}while(ans=='Y' || ans == 'y');
	return 0;
}


