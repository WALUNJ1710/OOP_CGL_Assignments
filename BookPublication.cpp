/*
Imagine a publishing company that markets both book and audiocassette versions of its
works. Create a class publication that stores the title (a string) and price (type float)
of a publication. From this class derive two classes: Book, which adds a page count (type
int), and Tape, which adds a playing time in minutes (type float). Each of these three
classes should have a getdata() function to get its data from the user at the keyboard,
and a putdata() function to display its data.
Write a main() program to test the book and tape classes by creating instances of them,
asking the user to fill in data with getdata(), and then displaying the data with putdata()*/

#include <iostream>
#include<string>
using namespace std;
class publication
{
    protected:
    string title;
    float price;
   
    public:
    publication()
    {
        title=" ";
        price=0.0;
        
        }
        publication(string t,float p)
        {
            title=t;
            price=p;
            
            }
           
            
    public:
    
 void getdata(void)
 {
  cout << "Enter title of publication: ";
  cin >> title;
  cout << "Enter price of publication: ";
  cin >> price;
   }
   
 void putdata(void)
 {
  cout << "Publication title: " << title << endl;
  cout << "Publication price: " << price<<endl;
 }
 
};

    class book : public publication
    {
        int pagecount;
        public:
        book()
        {
            pagecount=0;
            
        }
        //After : base class constructor is called
        book(string t,float p,int pc):publication(t,p)
        {
            
            pagecount=pc;
            
        }
        void getdata(void)
        {
        publication::getdata(); //call publication class function to get data
        cout << "Enter Book Page Count: "; //Acquire book data from user
        cin >> pagecount;
        }
     
        void putdata(void)
        {
        publication::putdata();  //Show Publication data
        cout << "Book page count: " << pagecount << endl; //Show book data
        } 
    };

    class CD : public publication
    {
        float time;
        public:
        CD()
        {
            time=0.0;
            
        }
        //After : base class constructor is called
        CD(string t,float p,float tim):publication(t,p)
        {
            
            time=tim;
            
        }
     
        void getdata(void)
        {
        publication::getdata();
        cout << "Enter tape's playing time: ";
        cin >> time;
        }
      
        void putdata(void)
        {
         publication::putdata();
         cout << "Tape's playing time: " << time << endl;
         }      
    };
    
int main()
{
    cout<<endl<<"Book data"<<endl;
    book b("C++",230,300);
    b.putdata();
    cout<<endl<<"CD Data"<<endl;
    CD c("C++",100,120.5);
    c.putdata();
    
    cout<<"\nEnter New Details of book\n";
    b.getdata();
    cout<<"Enter CD Data\n";
    c.getdata();
    cout<<"\n\nBook data entered by user:\n";
    b.putdata();
    cout<<"CD data entered by user: \n";
    c.putdata();
    return 0;
}

