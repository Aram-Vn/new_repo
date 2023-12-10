#ifndef CART_H
#define CART_H

#include <iostream>
#include <vector>
#include "1__Product.h"
#include "2__DiscountedProduct.h"

class Cart 
{
public:
	Cart() = default;
	~Cart() = default;
	Cart(std::initializer_list<Product*> init_list);

public:
	void addProduct(Product* product);
	void display() const;
	double calculateTotal() const;

private:
 	std::vector<Product*> m_products;
};

#endif //CART_H
