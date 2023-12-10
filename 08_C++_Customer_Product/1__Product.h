#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>

class Product
{
public:
    Product();
    Product(std::string new_name, double new_price);
    virtual ~Product();

public:
    virtual void display();
    virtual double calculate_discount(double discount);

private:
    std::string m_name;
    double m_price;
};

#endif //1__Product.h

