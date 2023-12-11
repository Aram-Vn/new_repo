#include "5__Product_impl.hpp"
#include "6__DiscountedProduct_impl.hpp"
#include "7__Cart_impl.hpp"
#include "8__Customer_impl.hpp"

int main(){

	Product p("TEST", 159.28);	
	/* p.display(); */
	/* std::cout << p.calculate_discount() << std::endl; */

	/* std::cout << "\n*******\n" << std::endl; */

	DiscountedProduct d("TEST2", 1234, 10);
	/* d.display(); */
	/* std::cout << d.calculate_discount() << std::endl; */

	/* std::cout << "\n*******\n" << std::endl; */
	Cart c;

	/* Cart c = {&p, &d}; */

	/* c.addProduct(&p); */

	/* std::cout << "PRISE "  <<c.calculateTotal() << std::endl; */
	
	/* std::cout << "\n*******\n" << std::endl; */
	/* c.display(); */

	Customer AA("AAA", c);
	
	AA.add_to_Cart(&p);
	AA.add_to_Cart(&d);
	
	AA.view_Cart();

}
