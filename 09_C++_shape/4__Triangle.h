#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "1__Shape.h"

class Triangle : public Shape
{
public:
    Triangle();
    Triangle(int side_1, int side_2, int side_3);
    ~Triangle() = default;

public:
    virtual void drawing_the_shape() const override;
	virtual double calculat_area() override;
	virtual void displayInfo() override;

private:
    bool is_triangle(int side1,int side2,int side3);

private:
    int m_side_1;
    int m_side_2;
    int m_side_3;
};

#endif //TRIANGLE_H