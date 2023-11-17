#ifndef STUDENT_IMP_HPP 
#define STUDENT_IMP_HPP
#include <iostream>

class student
{
	std::string m_name;
	int m_age;
	
public:
	student();
	student(std::string, int);
	~student();

	int get_age();
	std::string get_name();

	void set_age(int);
	void set_name(std::string);	
};
	

#endif
