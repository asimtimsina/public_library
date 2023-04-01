
#include <iostream>
#include <string>
#include "book.h"
using namespace std;

// defination of accessors and mutators
    void book:: setAuthor(string author){Author = author;}
    string book:: getAuthor(){return Author;}

    void book::setTitle(string title){Title = title;}
    string book::getTitle(){return Title;}

    void book::setISBN(string isbn){ISBN_no = isbn;}
    string book::getISBN(){return ISBN_no;}

    void book::setLibId(int id){LibID = id;}
    int book::getLibId(){return LibID;}

    void book::setCost(float cost){Cost = cost;}
    float book::getCost(){return Cost;}

      
    
    void book::setBookStatus(Bookstatus status){ Status = status;}
    Bookstatus book::getBookStatus(){return Status;}
    
    //default constructor
  book:: book(){
      Author = "None";
     Title= "None";
     ISBN_no = "None";
     LibID = 0;
     Cost = 0; 
    
     Status = In;
  }

  //parametarized constructor
  book:: book(string author, string title, string isbn, int id, float cost, Bookstatus status ){
    Author = author;
     Title= title;
     ISBN_no = isbn;
     LibID = id;
     Cost = cost; 
     Status = status;

  }


