#include <iostream>
#include "2__Circle.h"


constexpr double PI = 3.14159265358979323846;

Circle::Circle(int new_radius) :
	m_radius(new_radius)
{}

Circle::Circle() {
	m_radius = 0;
}

void Circle::drawing_the_shape() const {
	std::cout << "Circle" << std::endl;
}

double Circle::calculat_area() {
	return PI * m_radius * m_radius;
}

void Circle::displayInfo() {
	std::cout << "its a: "; 
	drawing_the_shape();
	std::cout << std::endl;

	std::cout << "area is: ";
	calculat_area(); 
	std::cout << std::endl;
}
