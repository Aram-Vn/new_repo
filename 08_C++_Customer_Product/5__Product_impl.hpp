#include "1__Product.h"

Product::Product() :
	m_name{""},
	m_price{0.0}
{}

Product::Product(std::string new_name, double new_price) :
	m_name(new_name),
	m_price(new_price)
{}	

Product::~Product()
{
	m_name = "\0";	
	m_price = 0.0;
}

void Product::display()
{
	std::cout<< "Product name: " << m_name << std::endl;
	std::cout << "Product price: " << m_price << std::endl;
}

double Product::calculate_discount(double discount)
{
	return	m_price - (m_price * discount) / 100;	
}
