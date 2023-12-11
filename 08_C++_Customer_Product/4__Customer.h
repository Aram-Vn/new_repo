#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include "3__Cart.h"

class Customer 
{
public:
	Customer(const char* new_name, Cart new_cart);

public:
	void add_to_Cart(Product* product);
	void view_Cart();

private:
	std::string m_name;
	Cart m_cart;
};

#endif //4__Customer.h
