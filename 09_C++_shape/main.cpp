#include <iostream>
#include "2__Circle.h"
#include "3__Rectangle.h"
#include "4__Triangle.h"

int main(){
    Circle c(5);
    c.displayInfo();
    std::cout << "*************" << std::endl;

    Rectangle r(7, 8);
    r.displayInfo();
    std::cout << "*************" << std::endl;

    Triangle t(7, 10, 5);
    t.displayInfo();
    std::cout << "*************" << std::endl;

    Triangle f(0, 1, 0);
    f.displayInfo();
}
