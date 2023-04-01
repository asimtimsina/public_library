/*
cout << "+-----------------------------------------------+"<<endl;
cout << "|                                               |" << endl;
cout << "|                Asim Timsina                   |" << endl;
cout << "|                                               |" << endl;
cout << "+-----------------------------------------------+ " << endl << endl ; 

 
Asim Timsina
asimtimsina@my.unt.edu
Date :- 09/08/2020
*/


#include <iostream>
#include <string>
#include "patron.h"
#include "patrons.h"
#include "book.h"
#include "books.h"
#include "loan.h"
#include "loans.h"
using namespace std;



  
 patrons pat;  //creating a object of patrons
 books boks;    ////creating a object of books
 loans borrow;    //creating a object of loans


void printmenu(); //function declaration to display the menu
int idcall(); //function declaration to prompt user for patron id
int libidcall();  //function declaration to prompt user for library id
int loanidcall();   //function declaration to prompt user for loan id

int main(){


cout << "+-----------------------------------------------+"<<endl;
cout << "|       Computer Science and Engineering        |" << endl;
cout << "|        CSCE 1040 - Computer Science II        |" << endl;
cout << "|  Asim Timsina    at0733    at0733@my.unt.edu  |" << endl;
cout << "+-----------------------------------------------+ " << endl << endl ; 



  pat.loadPatrons(); //loading patrons data from the file to the Patrons_list vector 
  boks.loadBooks();   //loading books data from the file to the Books_list vector
  borrow.loadLoan();  //loading Loans data from the file to the Loans_list vector

int choice = -5;
 cout <<endl << "Welcome to the Library" << endl;
do{

printmenu();
cout << "Enter the number to perform the task as indicated: " ;
cin >> choice;
// prompt user to enter the no to perform any task
while(!(((choice>=11) && (choice <=16) )|| ((choice >=21) && (choice <=29)) || ((choice >=31) && (choice <=39) )|| (choice == 0))){
cout <<"Invalid Choice !" << endl; 
cout << "Re-enter the number to perform the task as indicated: " ;
cin >> choice;
}

int p;
switch (choice){  // switch case to call the function as prompted by the user

// all cases about the patron
  case 11 : pat.addPatron(); break;
  case 12: pat.editPatron(); break;
  case 13: pat.deletePatron();break;
  case 14: pat.payfine(); break;
  case 15: p = idcall(); pat.printapatron( p);break;
  case 16 : pat.printallpatron(); break;

// all cases about the book
  case 21: boks.addBook();break ; 
  case 22: boks.editBook();break;
  case 23: boks.searchBook();break;
  case 24: boks.deleteBook();break;
  case 25: p=libidcall(); boks.printbyid(p);break;
  case 26: boks.printbyname();break;
  case 27: boks.printbyISBN();break;
  case 28:  boks.printbyauthor();break;
  case 29: boks.printallbook();break;

// all cases about the loan
  case 31: borrow.Checkout(); break;
  case 32: borrow.Checking(); break;
  case 33: p = loanidcall(); borrow.recheck(p); break;
  case 34: borrow.changeLoanStatus(); break;
  case 35: borrow.reportlost(); break;
  case 36: borrow.Printalldue(); break;
  case 37: p = loanidcall(); borrow.Printapatronloan(p) ; break;
  case 38: p = loanidcall(); borrow.Printaid(p); break;
  case 39: borrow.Printallloan();break;

}

}  while (choice != 0);
  
// storing the vector files into the file
  pat.storePatrons(); 
  boks.storeBooks();
  borrow.storeLoan();
  
}

void printmenu(){ // function to print the menu 
 cout <<endl << "----------------------------------------------" << endl;
  
  cout << "Patrons Menu"<<endl;
  cout <<"11: Add a Patron" << endl ;
  cout <<"12: Edit Patron's detail"<<endl;
  cout <<"13: Delete a Patron detail" << endl;
  cout <<"14: Pay Fine " << endl;
  cout <<"15: Print a Patron's detail " << endl;
  cout <<"16: Print all Patrons' detail " << endl<< endl;

  cout <<"Book Menu " << endl;
  cout <<"21: Add a new Book " << endl;
  cout <<"22: Edit a existing Book " << endl;
  cout <<"23: Search a Book " << endl;
  cout <<"24: Delete a Book " << endl;
  cout <<"25: Print Book details by Library ID " << endl;
  cout <<"26: Print Book details by Book Name " << endl;
  cout <<"27: Print Book details by ISBN Number " << endl;
  cout <<"28: Print Book details by Author Namne " << endl;
  cout <<"29: Print all Books detail " << endl << endl;

  cout <<"Loan Menu " << endl;
  cout <<"31: Check out a Book " << endl;
  cout <<"32: Check in a Book " << endl;
  cout <<"33: Recheck a borrowed Book " << endl;
  cout <<"34: Change Loan Status " << endl;
  cout <<"35: Report a lost Book " << endl;
  cout <<"36: Print all Due Loans " << endl;
  cout <<"37: Print all Loan details of a Patron Id " << endl;
  cout <<"38: Print a Loan details by Loan Id " << endl;
  cout <<"39: Print all Loan details " << endl << endl;

cout << "0: To close the Program" << endl ;
cout << "----------------------------------------------" << endl << endl; 
}


int idcall(){ //function defination to prompt user for patron id
  int id;
  cout <<"Enter your Patron's Id: " ;
  cin >> id;
  return id;
}

int libidcall(){ //function defination to prompt user for library id
  int id;
  cout <<"Enter your Book's Library Id: " ;
  cin >> id;
  return id;
}

int loanidcall(){ //function defination to prompt user for loan id
  int id;
  cout <<"Enter your Loan's Id: " ;
  cin >> id;
  return id;
}


