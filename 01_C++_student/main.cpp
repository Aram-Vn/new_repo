#include <iostream>
#include "student_imp.hpp"

	student::student(std::string new_name, int new_age): 
		m_name{new_name}, m_age{new_age}
	{}

	student::student(){
		std::string m_name = "0";
		int m_age = 0;
	}

	student::~student(){
		std::cout << "DESTRUCTED" << std::endl;
	}

	int student::get_age(){
		return m_age;
	}	

	std::string student::get_name(){
		return m_name;
	}		

	void student::set_age(int new_age){
		m_age = new_age;
	}

	void student::set_name(std::string new_name){
		m_name = new_name;
	}

	
int main(){
	student student1("Aram", 22);

} 
