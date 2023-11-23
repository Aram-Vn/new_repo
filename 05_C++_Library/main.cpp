#include <iostream>
#include "4__book.cpp"
#include "5__reader.cpp"
#include "6__Library.cpp"

int main(){

 Library lib;

 /* Book book1("c++", "s"); */
 /* Book book2("java", "f"); */
 /* Book book3("c#" , "n"); */

 /* Reader jo("jon", 0); */
 
 /* lib.addBook(book1); */
 /* lib.addBook(book2); */
 /* lib.addBook(book3); */
  
 /* lib.addReader(jo); */ 

 /* lib.issue_book(1, 1); */
 /* lib.issue_book(0, 0); */

 lib.add_book("c++", "s");
 lib.add_book("java", "f");
 lib.add_book("c#" , "n");

 lib.add_reader("jon", 0);  

 lib.issue_book(1, 1);
 /* lib.issue_book(0, 0); */
}

