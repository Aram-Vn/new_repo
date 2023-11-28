#include <iostream>
#include "s_ln_list.h"

int main(){
    Slist my_list;

    my_list.push_back(1);
    my_list.push_back(2);
    my_list.push_back(3);

    std::cout << "Original list: ";
    my_list.print_list();

    my_list.push_front(0);
    std::cout << "After push_front(0): ";
    my_list.print_list();

	my_list.push_back(0);
    std::cout << "After push_back(0): ";
    my_list.print_list();

    my_list.pop_front();
    std::cout << "After pop_front(): ";
    my_list.print_list();

    my_list.pop_back();
    std::cout << "After pop_back(): ";
    my_list.print_list();

    return 0;

}
