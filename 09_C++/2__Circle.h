#ifndef CIRCLE_H
#define CIRCLE_H

#include "1__Shape.h"

class Circle : public Shape
{
public:
	~Circle() = default;
	Circle();
	Circle(int new_radius);
public:
	virtual void drawing_the_shape() const override;
	virtual double calculat_area() override;
	virtual void displayInfo() override;	
private:
	int m_radius;
};

#endif //CIRCLE_H
