#include <iostream>

int foo(int num);

int main(){

 int num = 0;
 std::cin >> num;
  
 std::cout << foo(num) << std::endl;
}

int foo(int num){
	int res = 1;

	for(int i = 1; i <= num; ++i){
		res *= i;
	}

	return res;
}

