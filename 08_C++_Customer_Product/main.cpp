#include "5__Product_impl.hpp"
#include "6__DiscountedProduct_impl.hpp"
#include "7__Cart_impl.hpp"
#include "8__Customer_impl.hpp"

int main(){

	Product p("TEST", 159.28);	
	p.display();
	std::cout << p.calculate_discount(15) << std::endl;

	DiscountedProduct d("TEST2", 1234, 10);
	d.display();
	std::cout << d.calculate_discount(15) << std::endl;
}
