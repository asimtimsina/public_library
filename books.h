#ifndef BOOKS_H
#define BOOKS_H

#include <string>
#include <vector>
#include "book.h"
using namespace std;

class books{
  //private variable to store the data
  private:
      vector <book> Books_list;
      int Book_count;
  public:
  // declaration of all functions
      void addBook();
      void editBook();
      void searchBook();
      void deleteBook();
      void printbyid(int id);
      void printbyname();
      void printbyISBN();
      void printbyauthor();
      void printallbook();
      bool checkBook(int id);
      bool bookin(int id);
      void bookstatuschange(int id , Bookstatus status );
      float getcostofbook(int id);
      void storeBooks();
      void loadBooks();

books();
~books();
      
};


#endif
