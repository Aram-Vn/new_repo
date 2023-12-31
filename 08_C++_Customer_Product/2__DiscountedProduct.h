#ifndef DISCOUNTEDPRODUCT_H
#define DISCOUNTEDPRODUCT_H

#include "1__Product.h"
#include <iostream>

class DiscountedProduct : public Product
{
public:
	DiscountedProduct(std::string new_name, double new_price, double discount);
	~DiscountedProduct();	

public:
	virtual void display() const override;
	virtual double calculate_discount() const override;

private:
	double m_discount_precentage;
};

#endif // 2__DiscountedProduct.h
