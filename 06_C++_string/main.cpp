#include <iostream>
#include "Str_impl.hpp"


int main(){

 Str s("aaaa  aaa a");
 s.print();

 Str s1("aaa ggg qwertyu qwerty uqwer tyuwer we rty");
// s1.print();

 Str s2("b b vvvvvvvvv");

 s += s1;
// s.print();

 const char* str = "AAAAAA 1";
 
 Str s4(s1.c_str());
 s4.print();

 s2 += str;
 s2.print();


}
