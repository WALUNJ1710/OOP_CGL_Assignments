#include<iostream.h>
#include<fstream.h>
#include<conio.h>
int main() 
{ 
clrscr();
char name[20];
fstream file; file.open("sample.txt",ios::out);
if(!file)
{ cout<<"Error in creating file!!!"<<endl;  
}
 cout<<"File created successfully."<<endl;
 cout<<"Enter string to enter in file:"<<endl;
 cin>>name;
  file<<"ABCD.";
  file<<name;
file.close();

file.open("sample.txt",ios::in);
if(!file)
{ cout<<"Error in opening file!!!"<<endl; }

char ch;
cout<<"File content: ";
while(!file.eof())
{ file>>ch;
cout<<ch; }
file.close();
getch();
return 0;
}
