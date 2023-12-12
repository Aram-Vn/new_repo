#include <iostream>
#include "2__Circle.h"

Circle::Circle(int new_radius) :
	m_radius(new_radius)
{}

Circle::Circle() {
	m_radius = 0;
}

void Circle::drawing_the_shape() const {
	std::cout << "Circle" << std::endl;
}


