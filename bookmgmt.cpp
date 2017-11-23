#include<fstream>
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

class Book
{
  private:
      int bookid;
      char title[20];
      float price;
  public:
      Book()
      {
          bookid=0;
          strcpy(title,"no title");
          price=0;
      }

    void get()
    {

        cout<<"enter bookid,title and price of the book";
        cin>>bookid;
        cin.ignore();
        cin.getline(title,19);
        cin>>price;

    }
    void show()
    {

        cout<<"\n "<<bookid<<" "<<title<<" "<<price;
    }
    int storebook();
    void viewbook();
    void searchbook(char *);
    void deletebook(char *);


};
void Book::deletebook(char *t)
{
  ifstream fin;
  ofstream fout;
  fin.open("file1.dat",ios::in|ios::binary);
  if(!fin)
    cout<< "\nfile not found";
    else{
        fout.open("tempfile.dat",ios::out|ios::binary);
        fin.read((char*)this,sizeof(*this));
         while(!fin.eof()){
           if(strcmp(title,t))
            fout.write((char*)this,sizeof(*this));
            fin.read((char*)this,sizeof(*this));
         }
         fin.close();
         fout.close();
         remove("file1.dat");
         rename("tempfile.dat","file1.dat");
    }
}
int Book::storebook()
{
    if(bookid==0&&price==0)
    {
        cout<<"record can not inserted";
        return(0);
    }
    else
    {
    ofstream fout;
    fout.open("file1.dat",ios::app|ios::binary);
    fout.write((char*)this,sizeof(*this));
    fout.close();
    return(1);
}
}
   void Book::viewbook()
{
   ifstream fin;
   fin.open("file1.dat",ios::in|ios::binary);
   if(!fin)
    cout<<"\n file not found";
   else{
        fin.read((char*)this,sizeof(*this));
   while(!fin.eof())
    {
        show();
        fin.read((char*)this,sizeof(*this));
    }
    fin.close();
   }
}
void Book::searchbook(char *t)
{
     ifstream fin;
   fin.open("file1.dat",ios::in|ios::binary);
   if(!fin)
    cout<<"\n file not found";
     else{
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
    {
        if(!strcmp(t,title))
        show();
        fin.read((char*)this,sizeof(*this));
}
fin.close();
}
}


int main()
{
Book b1;
//b1.get();
//b1.show();
//b1.storebook();
b1.viewbook();
//b1.searchbook("");
//b1.viewbook();
//b1.deletebook("php");
//b1.viewbook();




}
