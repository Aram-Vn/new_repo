#ifndef SHAPE_H
#define SHAPE_H


class Shape
{
public:
	virtual ~Shape();
public:
	virtual void drawing_the_shape() const = 0;
	virtual double calculat_area() = 0;
	virtual void displayInfo() = 0;	
};



#endif //SHAPE_H
