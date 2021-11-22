/* Write a function template selection Sort. Write a program that inputs, sorts and outputs an int array and a float array.*/
#include<iostream>
using namespace std;
template<class T>
void selection(T a[], int n)
{
 int i, j;
for (j = 0; j < n-1; j++)
{
    int iMin = j;
    for ( i = j+1; i < n; i++)
 {
       if (a[i] < a[iMin])
       {
              iMin = i;
          }
    }
    if(iMin != j) {
        swap(a[j], a[iMin]);
    }
}
}
int main()
{
 int a[6]={1,2,6,9,4,7};
 char b[4]={'s','b','d','e'};
 float c[6]={10.2,5.0,6.3,5.2,1.5,1.56};
 selection(a,6);
 cout<<"\nSorted Order Integers: ";
 for(int i=0;i<6;i++)
 cout<<"\n"<<a[i]<<"\t";
 selection(b,4);
 cout<<"\nSorted Order Characters: ";
 for(int j=0;j<4;j++)
    cout<<"\n"<<b[j]<<"\t";
 cout<<"\nSorted Order float: ";
 selection(c,6);
 for(int j=0;j<6;j++)
 cout<<"\n"<<c[j]<<"\t";
 return 0;
 }