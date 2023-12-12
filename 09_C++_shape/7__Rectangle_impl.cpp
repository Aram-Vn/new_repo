#include "3__Rectangle.h"
#include <iostream>

Rectangle::Rectangle() :
    m_length(0),
    m_width(0)
{}

Rectangle::Rectangle(int new_length, int new_width) :
    m_length{new_length},
    m_width{new_width}
{}

void Rectangle::drawing_the_shape() const {
    std::cout << "Rectangle" << std::endl;
}

double Rectangle::calculat_area() {
    return m_length * m_width;
}

void Rectangle::displayInfo() {
    std::cout << "its a: "; 
	drawing_the_shape();
	std::cout << std::endl;

	std::cout << "area is: " << calculat_area() << std::endl;
}
