#ifndef BOOK_H
#define BOOK_H


#include <string>
using namespace std;

enum Bookstatus {In , Out , Repair , Lost };

class book{
//defining all of the data in private
  private: 
    string Author;
    string Title;
    string ISBN_no;
    int LibID;
    float Cost; 
    Bookstatus Status;
    
// functions including accssors and mutators in public
  public :
    void setAuthor(string author);
    string getAuthor();
    void setTitle(string title);
    string getTitle();
    void setISBN(string isbn);
    string getISBN();
    void setLibId(int id);
    int getLibId();
    void setCost(float cost);
    float getCost();
   
    void setBookStatus(Bookstatus status);
    Bookstatus getBookStatus();
    // declaration of default and parametrized constructor
  book();
  book(string author, string title, string isbn, int id, float cost, Bookstatus status );

};


  
  
  

#endif