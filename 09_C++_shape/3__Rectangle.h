#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "1__Shape.h"

class Rectangle : public Shape
{
public:
    Rectangle();
    Rectangle(int new_length, int new_width);
    ~Rectangle() = default;

public:
    virtual void drawing_the_shape() const override;
	virtual double calculat_area() override;
	virtual void displayInfo() override;	

private:
    int m_length;
    int m_width;
};
 
#endif // RECTANGLE_H