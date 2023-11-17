#include <iostream>
#include "1__Vec.cpp"

int main(){
 Vec v;

	for(int i = 0; i <= 10; ++i){
		v.push_back(i);
	}
 
 std::cout << v ;
 
 Vec v2(v);
 
 v2[2] = 5; 
 
 std::cout << v2[2] << std::endl;

 std::cout << v2 ;

 Vec v3(5);
	
 std::cout << v3;

 Vec v4(5, 8);
	
 std::cout << v4;

}
