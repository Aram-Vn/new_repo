#include <iostream>
#include "Str_impl.hpp"


int main(){

 Str s("aa  aaa a");
 /* s.print(); */

 Str s1("qwerertyutqwertqwertwertertyer we rty");
 /* s1.print(); */

 /* Str f1 = s; */
 // f1.print();   // Segmentation fault (core dumped)  

 /* Str f2 = s1; */
 //f2.print();  // Segmentation fault (core dumped) 

 
 /* std::cout << "\n*******" << std::endl; */

 Str a;

 a = s1 + s;	
 a.print();  // works!!!!!
 
 /* std::cout << "\n*******" << std::endl; */
 
 /* Str a1; */

 /* a1 = s + s1; */	
 //a1.print(); // Segmentation fault (core dumped) 
 

}
