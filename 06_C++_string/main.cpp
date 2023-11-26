#include <iostream>
#include "Str_impl.hpp"


int main(){

 Str s("aaaa  aaa a");
 s.print();

 Str s1("aaa ggg qwertyu qwerty uqwer tyuwer we rty");
 s1.print();

 Str s2("bbb  bbb b ");

 s += s1;
 s.print();

 std::cout << s.size() << std::endl;
}
