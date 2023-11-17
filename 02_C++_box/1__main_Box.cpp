#include <iostream>
#include "box.hpp"
	
	Box::Box(){
		m_length = 0;
		m_width = 0;
		m_height = 0;
	}

	Box::Box(int new_length, int new_width, int new_heigth){
		m_length = new_length;
		m_width = new_width;
		m_height = new_heigth;
	} 	

	Box::~Box(){}

	int Box::get_length() const{
		return m_length;
	}

	int Box::get_width() const{
		return m_width;
	}

	int Box::get_height() const{
		return m_height;
	}

	Box::Box(const Box& obj) : 
		m_length {obj.m_length},
	 	m_width {obj.m_width}, 
		m_height {obj.m_height}
	{}

int main(){

 Box box1;
 Box newBox(10, 11, 15);

 std::cout << newBox.get_length() << std::endl;
 std::cout << newBox.get_width() << std::endl;
 std::cout << newBox.get_height() << std::endl;

 Box otherBox(newBox);

 std::cout << otherBox.get_length() << std::endl;
 std::cout << otherBox.get_width() << std::endl;
 std::cout << otherBox.get_height() << std::endl;

}
