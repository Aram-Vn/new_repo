#ifndef STR_IMPL_H
#define STR_IMPL_H

#include "Str.h"
#include <cstring>

Str::Str()
{
	m_Is_on_stack = true;
	string.on_stack[0] = '\0';
}	

Str::Str(const char* new_str)
{
	int len = strlen(new_str);

	if(len < 16){
		strcpy(string.on_stack, new_str);
		m_Is_on_stack = true;
	} else {
		string.str.m_ptr = new char[len + 1];
		string.str.m_size = len;
		strcpy(string.str.m_ptr, new_str);
		m_Is_on_stack = false;
	}
}

Str::Str(const Str& other)
{
	if(other.m_Is_on_stack){
		strcpy(this->string.on_stack, other.string.on_stack);
	} else {
		this->string.str.m_ptr = new char[other.string.str.m_size];		
		strcpy(this->string.str.m_ptr, other.string.str.m_ptr);
	}
}

Str::Str(Str&& other) noexcept 
{
	if(other.m_Is_on_stack){
		strcpy(this->string.on_stack, other.string.on_stack);
	} else {
		for(int i = 0; i < other.string.str.m_size; ++i){
			this->string.str.m_ptr[i] = other.string.str.m_ptr[i];
		}
	}
}

Str::~Str()
{
	if(m_Is_on_stack){
		string.on_stack[0] = '\0';
	} else {
		delete[] string.str.m_ptr;
		string.str.m_size = 0;
	}
}

Str& Str::operator=(const Str& other)
{
	if(this != &other){
		if(other.m_Is_on_stack){
			strcpy(this->string.on_stack, other.string.on_stack);
		} else {
			if(other.string.str.m_size > this->string.str.m_size){
				delete[] this->string.str.m_ptr;
				this->string.str.m_ptr = new char[other.string.str.m_size];
			}

			this->string.str.m_size = other.string.str.m_size;

			for(int i = 0; i < other.string.str.m_size; ++i){
				this->string.str.m_ptr[i] = other.string.str.m_ptr[i];
			}
		}	
	} 

	return *this;
}

Str& Str::operator=(Str&& other) noexcept
{
	if(this != &other){
		if(other.m_Is_on_stack){
			strcpy(this->string.on_stack, other.string.on_stack);
			other.string.on_stack[0] = '\0';
		} else {
			this->string.str.m_ptr = other.string.str.m_ptr;
			this->string.str.m_size = other.string.str.m_size;

			other.string.str.m_ptr = nullptr;
			other.string.str.m_size = 0;
		}
	}
	
	return *this;
}

int Str::size() const
{
	if(m_Is_on_stack){
		return strlen(string.on_stack);
	} else {
		return string.str.m_size;
	}
}

Str& Str::operator+=(const Str& other)
{
	if(this->m_Is_on_stack){
		if( (this->size() + other.size()) < 16){
			strcat(this->string.on_stack, other.string.on_stack);			
		} else {
			char arr[16];
			strcpy(arr, this->string.on_stack);

			this->string.str.m_ptr = new char[this->size() + other.size() + 1];

			strcpy(this->string.str.m_ptr, arr);

				if(other.m_Is_on_stack){
					strcat(this->string.str.m_ptr, other.string.on_stack);
				} else {
					strcat(this->string.str.m_ptr, other.string.str.m_ptr);
				}

			this->string.str.m_size = this->size() + other.size() + 1;
			m_Is_on_stack = false;
		}
	} else {
		this->string.str.m_size += other.size();

		char* tmp_ptr = new char[this->string.str.m_size];

		strcpy(tmp_ptr, this->string.str.m_ptr);
			
			if(other.m_Is_on_stack){
				 strcat(tmp_ptr, other.string.on_stack);
			} else {
				strcat(tmp_ptr, other.string.str.m_ptr);
			}

		delete[] this->string.str.m_ptr;
		this->string.str.m_ptr = tmp_ptr;
	}
	
	return *this;
}

Str& Str::operator+=(const char* new_str)
{
	if(m_Is_on_stack){
		if(strlen(string.on_stack) + strlen(new_str) < 16){
			
		}
	}
}

void Str::print()
{
	if(m_Is_on_stack){
		std::cout << string.on_stack << std::endl;
	} else {
		for(int i = 0; i < string.str.m_size; ++i){
			std::cout << string.str.m_ptr[i];
		}
		std::cout << std::endl;
	}
}

#endif // Str_impl.h
