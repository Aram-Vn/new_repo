#include <iostream>
#include "Str_impl.hpp"


int main(){

 Str s("aa  aaa a");
 std::cout << s << std::endl; 

 Str s1("qwerertyutqwertqwertwertertyer we rty");
 std::cout << s1 << std::endl; 

 /* Str f1 = s; */
 /* f1.print();   // works!!!!! */  

 /* Str f2 = s1; */
 /* f2.print();  // nothig */ 

 
 /* std::cout << "\n*******" << std::endl; */

 /* Str a; */

 /* a = s1 + s; */	
 /* a.print();  // works!!!!! */
 
 /* std::cout << "\n*******" << std::endl; */
 
 /* Str a1; */

 /* a1 = s + s1; */	
 /* a1.print(); // Segmentation fault (core dumped) */ 
 
 /* Str k; */

 /* k = s + "avvvvvvaaaa"; */

 /* k.print(); */
 
 /* Str k1; */

 /* k1 = s1 + "AAAAAAAAAAAAAAAAAAA"; */

 /* k1.print(); */

 /* Str l1; */
	
 /* l1 = "LLLLLLL" + s; */

 /* l1.print(); */

 /* Str l2; */
	
 /* l2 = "lllllllllllllll" + s1; */
 /* l2.print(); */

}
