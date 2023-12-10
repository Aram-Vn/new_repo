#include "2__DiscountedProduct.h"

DiscountedProduct::DiscountedProduct(std::string new_name, double new_price, double new_discount_precentage) :
	Product(new_name, new_price), 
	m_discount_precentage(new_discount_precentage)
{}

DiscountedProduct::~DiscountedProduct()
{
	m_discount_precentage = 0.0;
}

void DiscountedProduct::display() const 
{
	std::cout<< "Discounted Product name: " << m_name << std::endl;
	std::cout << "Discounted Product old  price: " << m_price << std::endl;
	std::cout << "discoun precentage is: " << m_discount_precentage << " %" << std::endl;
	std::cout << "Discounted Product new price: " << calculate_discount() << std::endl;
		
}

double DiscountedProduct::calculate_discount() const
{
	return m_price - ( m_price * (m_discount_precentage / 100.0));
}
