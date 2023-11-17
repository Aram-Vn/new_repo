#include <iostream>
#include "2__vec.h"

Vec::Vec() :
	m_ptr {nullptr},
	m_size {0},
	m_cap  {0}
{}

Vec::~Vec(){
	delete[] m_ptr;
	m_size = 0;
	m_cap = 0;
}

Vec::Vec(int new_size, int val) : 
	m_size{new_size},
	m_cap{2 * m_size},
	m_ptr{new int[m_cap]}	
{
	
	for(int i = 0; i < m_size; ++i){
		m_ptr[i] = val;
	}
}


Vec::Vec(const Vec& other) :
	m_size{other.m_size},
	m_cap{other.m_cap},
	m_ptr{new int[m_cap]}	
{

	for(int i = 0; i < m_size; ++i){
		this->m_ptr[i] = other.m_ptr[i];
	}
}

Vec::Vec(Vec&& other) noexcept :       
		m_size{other.m_size},
		m_cap{other.m_cap}, 
		m_ptr{other.m_ptr} 
{
	other.m_size = 0;
	other.m_cap = 0;
	other.m_ptr = nullptr;
}

std::ostream& operator<<(std::ostream& os, const Vec& obj){

	for(int i = 0; i < obj.get_size(); ++i){
		os << obj[i] << " ";
	}
	std::cout << std::endl;

	return os;	
}

int& Vec::operator[](int ind) const{
	if(m_ptr == nullptr){
		std::cout << "NULLPTR" << std::endl;
		exit(0);
	}

	if(ind >= 0 && ind < m_size){
		return *(m_ptr + ind);
	} else {
		std::cout << "ind must be >=0 && < size" << std::endl;
		exit(0);
	}
}

void Vec::realloc(){
	m_cap = (m_cap) ? 2 * m_cap : 1;
	
	int* tmp_ptr = new int[m_cap];

	for(int i = 0; i < m_size; ++i){
		tmp_ptr[i] = m_ptr[i];
	}
	
	delete[] m_ptr;
	m_ptr = tmp_ptr;
}

void Vec::push_back(const int& num){
	
	if(m_size < m_cap){
		m_ptr[m_size++] = num;
		return;
	}

	realloc();	
}

void Vec::pop_back(){
	if(m_size != 0 && m_ptr != nullptr){
		--m_size;
	}
}

int Vec::get_size() const{
	return m_size;
}

int Vec::get_cap() const{
	return m_cap;

}

void Vec::insert(int index, int num){
	if(m_ptr != nullptr && index >= 0 && index < m_size){

		for(int i = m_size - 1; i <  index + 1; ++i){
			m_ptr[i + 1] = m_ptr[i];
		}

		m_ptr[index] = num;
	}
}

void Vec::erese(int index){
	if(m_ptr != nullptr && m_size > 0 && index >= 0 && index < m_size){
		for(int i = index; i < m_size; ++i){
			m_ptr[i] = m_ptr[i + 1];
		} 

		--m_size;
	}
}

