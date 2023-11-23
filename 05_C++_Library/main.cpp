#include <iostream>
#include "4__book.cpp"
#include "5__reader.cpp"
#include "6__Library.cpp"

int main(){

 Library lib;

 Book book1("c++", "s");
 Book book2("java", "f");
 Book book3("c#" , "n");

 Reader jo("jon", 0);

 lib.issue_book(8, 0);
}

