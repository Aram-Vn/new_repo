#include "1__Product.h"

Product::Product() :
	m_name{""},
	m_price{0.0}
{}

Product::Product(std::string new_name, double new_price) :
	m_name(new_name),
	m_price(new_price)
{}	

void Product::display()
{
	std::cout<< "Product name: " << m_nume << std::endl;
	std::cout << "Product price: " << m_price << std::endl;
}
