#include "4__Triangle.h"
#include <iostream>
#include <cmath>

Triangle::Triangle() :
    m_side_1(0),
    m_side_2(0),
    m_side_3(0)
{}

Triangle::Triangle(int side_1, int side_2, int side_3) 
{
    if(is_triangle(side_1, side_2, side_3)){
        m_side_1 = side_1;
        m_side_2 = side_2;
        m_side_3 = side_3;
    } else {
        std::cout << "invalid triangle" << std::endl;
    }

}

void Triangle::drawing_the_shape() const {
    std::cout << "Triangle" << std::endl;
}

double Triangle::calculat_area() {
    if(is_triangle(m_side_1, m_side_2, m_side_3)) {
	    int p = (m_side_1 + m_side_2 + m_side_3) / 2;

        double res = sqrt(p * (p - m_side_1) * (p - m_side_2) + (p - m_side_3));
	    return res;
    } else {
        std::cout << "invalid triangle" << std::endl;
        return -1;
    }
}

bool Triangle::is_triangle(int side1,int side2,int side3) {
    if((side1 <= 0) || (side2 <= 0) || (side3 <= 0)){
		std::cout << " ERROR\nNO side need to be > 0!!!" << std::endl;
		return false;
	}

	if((side1 + side2 > side3 && side2 + side3 > side1 &&  side1 + side3 > side2)){
		return true;
	}

	std::cout << "ERROR\nNO sum of 2 sides need to be < than 3-rd side!!!" << std::endl;
	return false;
}

void Triangle::displayInfo() {
    std::cout << "its a: "; 
	drawing_the_shape();
	std::cout << std::endl;

	std::cout << "area is: " << calculat_area() << std::endl;
}

