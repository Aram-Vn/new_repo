#include "3__Cart.h"

/* Cart::Cart() {} */

/* Cart::~Cart() {} */

Cart::Cart(std::initializer_list<Product*> init_list) 
 /* : m_products(init_list) {} */
{
	for (const auto& elem : init_list) {
		m_products.push_back(elem);
    }
}

void Cart::addProduct(Product* product)
{
	m_products.push_back(product);
}

void Cart::display() const
{
    std::cout << "Cart Contents:" << std::endl;
    for (const auto& product : m_products) {
        product->display();
        std::cout << "-----------------------" << std::endl;
    }
}

double Cart::calculateTotal() const
{
	double total = 0.0;

    for (const auto& product : m_products) {
        total += product->calculate_discount();
    }

    return total;
}

