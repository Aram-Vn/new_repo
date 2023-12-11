#include "4__Customer.h"

Customer::Customer(const char* new_name, Cart new_cart) :
	m_name(new_name),
	m_cart(new_cart)
{}

void Customer::add_to_Cart(Product* product)
{
	 m_cart.addProduct(product);
}

void Customer::view_Cart()
{
	std::cout << "+++++++++++++++++++++++++" << std::endl;
	std::cout << "Customer name : " << m_name << std::endl;
	std::cout << "+++++++++++++++++++++++++" << std::endl;
	m_cart.display();
}

