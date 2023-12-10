#include "2__DiscountedProduct.h"

DiscountedProduct::DiscountedProduct(std::string new_name, double new_price, double discount) :
	Product(new_name, new_price), 
	m_discount_precentage(m_price - (m_price * discount) / 100)
	
{}

DiscountedProduct::~DiscountedProduct()
{
	m_discount_precentage = 0.0;
}

void DiscountedProduct::display() 
{
	std::cout<< "Discounted Product name: " << m_name << std::endl;
	 std::cout << "Discounted Product price: " << m_price << std::endl;
	std::cout << "Discounted Product prise is: " << m_discount_precentage << std::endl;
}

double DiscountedProduct::calculate_discount(double discount)
{
	return m_discount_precentage;
}
