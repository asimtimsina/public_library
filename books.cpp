#include<iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "book.h"
#include "books.h"

using namespace std;





void books:: addBook(){ // function to add a new book to the Books_list vector
 string author , title, isbn ;
         int id,cost;
        cin.ignore();
         cout <<"Enter the book name : ";
         getline(cin, title);

        cout <<"Enter the authors name : ";
         getline(cin, author);
         
         cout <<"Enter the ISBN Number : ";
         cin >> isbn;
               
         cout << "Enter your Library Id: ";
         cin >>  id;

          cout <<"Enter the book Price : ";
         cin >> cost;    

         while(checkBook(id)){
           cout <<"Library id matched with another Book." << endl;
             cout << "Enter another Library Id: ";
             cin >>  id;
         }     

          

        book temp (author,title,isbn,id,cost , In); // creating a temp object

        Books_list.push_back(temp); // adding the object to the constuctor
        Book_count ++ ; 

}


/////////////////////////////////////////////////////////////
void books:: editBook(){ //function to edit the details of the book using the book id


               bool check=false; 
               
              int id ;
              string title , author, isbn ;
              int cost;  
              
              cout <<"Please enter your Patron Id: " ; 
              cin >> id;
              


              for (int i = 0 ; i < Book_count ; i ++){
                  if(Books_list[i].getLibId()==id){

                    printbyid(id);
                    cout << endl;

                    check =true;

                   
                      cout << "Enter the edited Book Name: " ;
                      cin.ignore();
                      getline(cin, title);
                      Books_list[i].setTitle(title);

                      cout <<"Enter the edited authors name : ";
                      getline(cin, author);
                      Books_list[i].setAuthor(author);
                                            
                      cout <<"Enter the edited ISBN Number : ";
                      cin >> isbn;
                      Books_list[i].setISBN(isbn);
                            
                      cout <<"Enter the edited book Price : ";
                      cin >> cost;         
                      Books_list[i].setCost(cost);


                    
                        cout <<"\nYour edited Name has been sucessfully saved in our database" << endl;
                       printbyid(id);
                       
                  }
                  }

                  if(!check){
                    cout << "Patron with the Id " <<id <<" not found" << endl;
                    cout << "Returning to the main menu" << endl << endl;
                  }



}
//////////////////////////////////////////////////////////



 void books::printallbook(){  // function to print all book details to the user

   string tempstatus ; 

cout <<"Total Patron Number: " << Books_list.size() << endl; 
    cout << "Book Title      \t    Book Id \t     Author Name    \t    ISBN number \t Cost \t Book Status " << endl;
    cout <<"----------------------------------------------------------------------------------------------------------"<< endl;
  for (int i=0; i < Book_count; i++){
  
        if ( Books_list[i].getBookStatus()==0) tempstatus = "In";
        if ( Books_list[i].getBookStatus()==1) tempstatus = "Out";
        if ( Books_list[i].getBookStatus()==2) tempstatus = "Repair";
        if ( Books_list[i].getBookStatus()==3) tempstatus = "Lost";
        
    
    cout <<left <<setw(25) << Books_list[i].getTitle() << setw(15) << Books_list[i].getLibId() << setw(25) << Books_list[i].getAuthor() << setw(15) << Books_list[i].getISBN()  << setw(12) << Books_list[i].getCost() << setw(10) << tempstatus << endl;
  }

      }

////////////////////////////////////////////////////////////

      void books::searchBook(){ //function to search a book details using book id
          int id; 
          bool check =false ;
          string tempstatus ; 
          cout <<"Please enter Book Id: " ; 
              cin  >> id ;

 cout << "Book Title      \t    Book Id \t     Author Name    \t    ISBN number \t Cost \t Book Status " << endl;
    cout <<"----------------------------------------------------------------------------------------------------------"<< endl;

              for (int i = 0 ; i < Book_count ; i ++){
                  if(Books_list[i].getLibId()==id){
                    check = true ;
                     if ( Books_list[i].getBookStatus()==0) tempstatus = "In";
        if ( Books_list[i].getBookStatus()==1) tempstatus = "Out";
        if ( Books_list[i].getBookStatus()==2) tempstatus = "Repair";
        if ( Books_list[i].getBookStatus()==3) tempstatus = "Lost";
        
    
    cout <<left <<setw(25) << Books_list[i].getTitle() << setw(15) << Books_list[i].getLibId() << setw(25) << Books_list[i].getAuthor() << setw(15) << Books_list[i].getISBN()  << setw(12) << Books_list[i].getCost() << setw(10) << tempstatus << endl;
                  }
         }
         if(!check){
            cout << "Book with the Id " <<id <<" not found" << endl;
                    cout << "Returning to the main menu" << endl << endl;
                  }
      
      }


      //////////////////////////////////////////////////
      void books::deleteBook(){ // function to delete a book 

         int id; 
          bool check =false ;
          cout <<"Please enter Book Id: " ; 
              cin  >> id ;

              for (int i = 0 ; i < Book_count ; i ++){
                  if(Books_list[i].getLibId()==id){
                    check = true ;
                     cout << "The following record has been deleted from  our database " << endl;
                    printbyid(id);
                        Books_list.erase(Books_list.begin()+i);
                        Book_count -- ;
                        
                       }
              }
        if(!check){
            cout << "Book with the Id " <<id <<" not found" << endl;
                    cout << "Returning to the main menu" << endl << endl;
                  }

      }

      //////////////////////////////////////////
      void books::printbyid(int id){   // function to print a book details using the book id
        //int id; 
          bool check =false ;
          string tempstatus; 
          //cout <<"Please enter Book Id: " << endl; 
             // cin  >> id ;

              cout << "Book Title      \t    Book Id \t     Author Name    \t    ISBN number \t Cost \t Book Status " << endl;
    cout <<"----------------------------------------------------------------------------------------------------------"<< endl;


              for (int i = 0 ; i < Book_count ; i ++){
                  if(Books_list[i].getLibId()==id){
                     check = true ;
                     if ( Books_list[i].getBookStatus()==0) tempstatus = "In";
        if ( Books_list[i].getBookStatus()==1) tempstatus = "Out";
        if ( Books_list[i].getBookStatus()==2) tempstatus = "Repair";
        if ( Books_list[i].getBookStatus()==3) tempstatus = "Lost";
        
    
    cout <<left <<setw(25) << Books_list[i].getTitle() << setw(15) << Books_list[i].getLibId() << setw(25) << Books_list[i].getAuthor() << setw(15) << Books_list[i].getISBN()  << setw(12) << Books_list[i].getCost() << setw(10) << tempstatus << endl;
                  }
         }
         if(!check){
            cout << "Book with the Id " <<id <<" not found" << endl;
                    cout << "Returning to the main menu" << endl << endl;
                   
                  }
                
      
      }

      ///////////////////////////////////////////////////////////////

      void books::printbyname(){ // function to print a book details using the book name
       
        string name;  
          bool check =false ;
          string tempstatus;

          cout <<"Please enter Book Title: " ; 
             cin.ignore();
             getline(cin,name);

              cout << "Book Title      \t    Book Id \t     Author Name    \t    ISBN number \t Cost \t Book Status " << endl;
    cout <<"----------------------------------------------------------------------------------------------------------"<< endl;


              for (int i = 0 ; i < Book_count ; i ++){
                  if(Books_list[i].getTitle()==name){
                     check = true ;
                     if ( Books_list[i].getBookStatus()==0) tempstatus = "In";
        if ( Books_list[i].getBookStatus()==1) tempstatus = "Out";
        if ( Books_list[i].getBookStatus()==2) tempstatus = "Repair";
        if ( Books_list[i].getBookStatus()==3) tempstatus = "Lost";
        
    
    cout <<left <<setw(25) << Books_list[i].getTitle() << setw(15) << Books_list[i].getLibId() << setw(25) << Books_list[i].getAuthor() << setw(15) << Books_list[i].getISBN()  << setw(12) << Books_list[i].getCost() << setw(10) << tempstatus << endl;
                  }
        
         }
         if(!check){
            cout << "Book with the title " <<name <<" not found" << endl;
                    cout << "Returning to the main menu" << endl << endl;
                  }
      
      }
    
      //////////////////////////////////////////////////////////////
      void books::printbyISBN(){ // function to print a book details using the ISBN Number
       
        string isbn;  
          bool check =false ;
          cout <<"Please enter Book ISBN : " ; 

          cin  >> isbn ;
              string tempstatus ;

           cout << "Book Title      \t    Book Id \t     Author Name    \t    ISBN number \t Cost \t Book Status " << endl;
    cout <<"----------------------------------------------------------------------------------------------------------"<< endl;

        
              

              for (int i = 0 ; i < Book_count ; i ++){
                  if(Books_list[i].getISBN()==isbn){
                     check = true ;
                     if ( Books_list[i].getBookStatus()==0) tempstatus = "In";
        if ( Books_list[i].getBookStatus()==1) tempstatus = "Out";
        if ( Books_list[i].getBookStatus()==2) tempstatus = "Repair";
        if ( Books_list[i].getBookStatus()==3) tempstatus = "Lost";
        
    
    cout <<left <<setw(25) << Books_list[i].getTitle() << setw(15) << Books_list[i].getLibId() << setw(25) << Books_list[i].getAuthor() << setw(15) << Books_list[i].getISBN()  << setw(12) << Books_list[i].getCost() << setw(10) << tempstatus << endl;
                  }
         }
         if(!check){
            cout << "Book with the ISBN: " << isbn <<" not found" << endl;
                    cout << "Returning to the main menu" << endl << endl;
                  }
      
      }
    
      //////////////////////////////////////////////////////////////
      void books::printbyauthor(){
         string author;  
          bool check =false ;
          string tempstatus;
          cout <<"Please enter Book's author name: " ; 
             cin.ignore();
             getline (cin,author);

              cout << "Book Title      \t    Book Id \t     Author Name    \t    ISBN number \t Cost \t Book Status " << endl;
    cout <<"----------------------------------------------------------------------------------------------------------"<< endl;


              for (int i = 0 ; i < Book_count ; i ++){
                  if(Books_list[i].getAuthor()==author){
                     check = true ;
                     if ( Books_list[i].getBookStatus()==0) tempstatus = "In";
        if ( Books_list[i].getBookStatus()==1) tempstatus = "Out";
        if ( Books_list[i].getBookStatus()==2) tempstatus = "Repair";
        if ( Books_list[i].getBookStatus()==3) tempstatus = "Lost";
        
    
    cout <<left <<setw(25) << Books_list[i].getTitle() << setw(15) << Books_list[i].getLibId() << setw(25) << Books_list[i].getAuthor() << setw(15) << Books_list[i].getISBN()  << setw(12) << Books_list[i].getCost() << setw(10) << tempstatus << endl;
                  }
         }
         if(!check){
            cout << "Book with the author: " << author <<" not found" << endl;
                    cout << "Returning to the main menu" << endl << endl;
                  }
      }
      //////////////////////////////////////////////////////////////
void books::bookstatuschange(int id , Bookstatus status ){

  for (int i = 0 ; i < Book_count ; i ++){
                  if(Books_list[i].getLibId()==id){
                    Books_list[i].setBookStatus(status);
}
  }
}


      //////////////////////////////////////////////////////////
     

bool books::checkBook(int id){  //function to checkif a book is listed in the library or not 
  
              for (int i = 0 ; i < Book_count ; i ++){
                  if(Books_list[i].getLibId()==id){
                     return  true ;
                }

              }
return false;
}


/////////////////////////////////////////////////////////////////////

bool books::bookin(int id){  // function to check whether a book is in the library or not in the current time

   for (int i = 0 ; i < Book_count ; i ++){
                  if(Books_list[i].getLibId()==id){
                     if(Books_list[i].getBookStatus() != In){
                     return  true ;
                     }
                }

              }
return false;

}


///////////////////////////////////////////////////////////////
float books::getcostofbook(int id){ //function that returns the cost of a book 
    for (int i = 0 ; i < Book_count ; i ++){
                  if(Books_list[i].getLibId()==id){
                    return Books_list[i].getCost();
                  }
    }
    return -1;

}



/////////////////////////////////////////////////////////////////////

void books::loadBooks(){  // function that stores the book details from  a file to the Books_list vector

  ifstream fin;
  string author;
  string title;
  string isbn;
  int id;
  float cost;
  Bookstatus status;
  int stat;
 
  
  fin.open("Books.dat");

  fin >> Book_count;
  fin.ignore();
  
  string line ;

while (getline(fin, line)){
  //cout << line << endl;
  istringstream cut(line);
  getline(cut ,author , ',' );
  getline(cut ,title , ',' );
  cut >>   isbn >> id >> cost  >> stat ;
  
  if (stat ==0) status = In;
  if (stat ==1) status = Out;
  if (stat ==2) status = Repair;
  if (stat ==3) status = Lost;

   book temp(author, title, isbn, id, cost , status);
   Books_list.push_back(temp);
}

  fin.close();
  

}

////////////////////////////////////////////////////////////////////
void books::storeBooks(){  // function that stores the Books_list to a file when called

  ofstream fout;

  fout.open( "Books.dat");

Book_count = Books_list.size();

  fout << Book_count << endl;

  for (int i=0; i < Book_count; i++)
  {
    
   fout << Books_list[i].getAuthor() <<","  << Books_list[i].getTitle() <<"," << Books_list[i].getISBN() <<" " << Books_list[i].getLibId()  <<" "<< Books_list[i].getCost()  <<" " <<Books_list[i].getBookStatus() << endl;
  }

  fout.close();
}


////////////////////////////////////////////////////////
books::books(){
  Book_count =0;
}
//////////////////////////////////////////////////


books::~books(){
  Books_list.clear() ;
}