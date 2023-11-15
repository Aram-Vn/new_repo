#include <iostream>

int fibonachi(int num);
int foo(int num);

int main(){

 int num = 0;
 std::cin >> num;
  
 std::cout << foo(num) << std::endl;
 std::cout << fibonachi(num) << std::endl;

}

int foo(int num){
	int res = 1;

	for(int i = 1; i <= num; ++i){
		res *= i;
	}

	return res;
}

int fibonachi(int num){
	int tmp = 0;
	int last = 0;
	int next = 1;


	for(int i = 0; i < num; ++i){
		tmp = next;
		next += last;
		last = tmp;
	}

	return last;
}
