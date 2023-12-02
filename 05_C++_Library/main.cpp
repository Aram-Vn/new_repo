#include <iostream>
/* #include "1__book.h" */
/* #include "5__reader." */
#include "3__Library.h"
int main(){

 Library lib;

 lib.add_book("c++", "s");
 lib.add_book("java", "f");
 lib.add_book("c#" , "n");
 lib.add_book("ci#" , "n");
 lib.add_book("ca#" , "n");

 std::cout << "\n********" << std::endl;

 lib.add_reader("jon", 1);  
 lib.add_reader("aaa", 2);  
 lib.add_reader("aa", 3);  
 
// book id, reader id

 std::cout << "\n**********lib.issue_book " << std::endl;
 std::cout << std::endl;
 lib.issue_book(1, 2);


 std::cout << "\n**********lib.issue_book " << std::endl;   
 std::cout << std::endl;
 lib.issue_book(1, 1);


 std::cout << "\n***********lib.return_book" << std::endl;
 std::cout << std::endl;
 lib.return_book(1, 1);
 
 std::cout << "\n**********lib.issue_book " << std::endl;   
 std::cout << std::endl;
 lib.issue_book(1, 1);
 
}
