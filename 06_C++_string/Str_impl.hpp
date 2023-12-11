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

	if(len < STACK_SIZE){
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
		this->m_Is_on_stack = true;
	} else {

		this->string.str.m_size = other.string.str.m_size;
		this->string.str.m_ptr = new char[other.string.str.m_size];		
		strcpy(this->string.str.m_ptr, other.string.str.m_ptr);

		this->m_Is_on_stack = false; 
	}
}

Str::Str(Str&& other) noexcept 
{
	if(other.m_Is_on_stack){
		strcpy(this->string.on_stack, other.string.on_stack);
		this->m_Is_on_stack = true;
	} else {
		this->string.str.m_ptr = other.string.str.m_ptr;
		this->string.str.m_size = other.string.str.m_size;
		this->m_Is_on_stack = false;
		
		other.string.str.m_ptr = nullptr;
		other.string.str.m_size = 0;
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

		if(!this->m_Is_on_stack){
			delete[] this->string.str.m_ptr;
		}

		if(other.m_Is_on_stack){
			strcpy(this->string.on_stack, other.string.on_stack);
			this->m_Is_on_stack = other.m_Is_on_stack;
		} else {

			this->string.str.m_size = other.string.str.m_size;
 			this->string.str.m_ptr = new char[ this->string.str.m_size];
	
			strcpy(this->string.str.m_ptr, other.string.str.m_ptr);	
	
			this->m_Is_on_stack = other.m_Is_on_stack;
		}	
	} 

	return *this;
}

Str& Str::operator=(Str&& other) noexcept
{
	if(this != &other){
		if(other.m_Is_on_stack){
			strcpy(this->string.on_stack, other.string.on_stack);
			this->m_Is_on_stack = other.m_Is_on_stack;
			other.string.on_stack[0] = '\0';
		} else {
			this->string.str.m_ptr = other.string.str.m_ptr;
			this->string.str.m_size = other.string.str.m_size;
			this->m_Is_on_stack = other.m_Is_on_stack;
			
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
		if( (this->size() + other.size()) < STACK_SIZE){
			strcat(this->string.on_stack, other.string.on_stack);			
		} else {
			char arr[STACK_SIZE];
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
		if(strlen(string.on_stack) + strlen(new_str) < STACK_SIZE){
			strcat(string.on_stack, new_str);			
			string.on_stack[15] = '\0';
		} else {
			char tmp_str[STACK_SIZE];
			strcpy(tmp_str, string.on_stack);
			
			string.str.m_size = strlen(string.on_stack) + strlen(new_str) + 2;

			string.str.m_ptr = new char[string.str.m_size];

			strcpy(string.str.m_ptr, tmp_str);
            strcat(string.str.m_ptr, new_str);
	
			/* string.str.m_ptr[string.str.m_size - 1] = '\0'; */	

			m_Is_on_stack = false;		
		}
	} else {
		string.str.m_size += strlen(new_str) + 2;
	
		char* tmp_ptr = new char[string.str.m_size];

		strcpy(tmp_ptr, string.str.m_ptr);
        strcat(tmp_ptr, new_str);

		delete[] string.str.m_ptr;
		string.str.m_ptr = tmp_ptr;
	}

	return *this;
}

/* Str Str::operator+(const Str& other) */
/* { */
/* 	Str tmp_obj(this->c_str()); */
	
/* 	if(tmp_obj.m_Is_on_stack){ */
/* 		if(tmp_obj.size() + other.size() < STACK_SIZE){ */
/* 			strcat(tmp_obj.string.on_stack, other.string.on_stack); */
/* 		} else { */
/* 			char tmp_str[strlen(tmp_obj.string.on_stack)]; */
/* 			strcpy(tmp_str, tmp_obj.string.on_stack); */
			
/* 			tmp_obj.string.str.m_size = tmp_obj.size() + other.size() + 2; */
/* 			tmp_obj.string.str.m_ptr = new char[tmp_obj.string.str.m_size]; */

/* 			strcpy(tmp_obj.string.str.m_ptr, tmp_str); */
           
/* 				if(other.m_Is_on_stack){ */
/* 					strcat(tmp_obj.string.str.m_ptr, other.string.on_stack); */
/* 				} else { */
/* 					strcat(tmp_obj.string.str.m_ptr, other.string.str.m_ptr); */
/* 				} */		

/* 			m_Is_on_stack = false; */	
/* 		} */
/* 	} else { */

/* 		tmp_obj.string.str.m_size = tmp_obj.size() + other.size() + 1; */
/* 		tmp_obj.string.str.m_ptr = new char[tmp_obj.size()]; */

/* 		strcpy(tmp_obj.string.str.m_ptr, this->string.str.m_ptr); */

/* 				if(other.m_Is_on_stack){ */
/* 					strcat(tmp_obj.string.str.m_ptr, other.string.on_stack); */
/* 				} else { */
/* 					strcat(tmp_obj.string.str.m_ptr, other.string.str.m_ptr); */
/* 				} */		
/* 	} */

/* 	return tmp_obj; */
			
/* } */

const char* Str::c_str() const
{
	if(m_Is_on_stack){
		return string.on_stack;
	} else {
		return string.str.m_ptr;
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

Str Str::operator+(const Str& other) {
    Str tmp_obj(this->c_str());
    if (tmp_obj.m_Is_on_stack) {
        if (tmp_obj.size() + other.size() < STACK_SIZE) {
            strcat(tmp_obj.string.on_stack, other.string.on_stack);
        } else {

            char tmp_str[STACK_SIZE];
            strcpy(tmp_str, tmp_obj.string.on_stack);

            tmp_obj.string.str.m_size = tmp_obj.size() + other.size() + 1;
            tmp_obj.string.str.m_ptr = new char[tmp_obj.string.str.m_size];

            strcpy(tmp_obj.string.str.m_ptr, tmp_str);

           		if (other.m_Is_on_stack) {
            	    strcat(tmp_obj.string.str.m_ptr, other.string.on_stack);
        	    } else {
    	            strcat(tmp_obj.string.str.m_ptr, other.string.str.m_ptr);
	            }

            tmp_obj.m_Is_on_stack = false;
        }
    } else {

        tmp_obj.string.str.m_size = tmp_obj.size() + other.size() + 1;
        tmp_obj.string.str.m_ptr = new char[tmp_obj.size()];

        strcpy(tmp_obj.string.str.m_ptr, this->string.str.m_ptr);

	        if (other.m_Is_on_stack) {
    	        strcat(tmp_obj.string.str.m_ptr, other.string.on_stack);
       		} else {
            	strcat(tmp_obj.string.str.m_ptr, other.string.str.m_ptr);
        	}
    }

    return tmp_obj;
}

Str Str::operator+(const char* new_str)
{
	Str tmp_obj(this->c_str());

	if(tmp_obj.m_Is_on_stack) {
		if (tmp_obj.size() + strlen(new_str) < STACK_SIZE) { 
			strcat(tmp_obj.string.on_stack, new_str);
		} else {
			char tmp_str[STACK_SIZE];
			strcpy(tmp_str, tmp_obj.string.on_stack);

			tmp_obj.string.str.m_size = tmp_obj.size() + strlen(new_str) + 1;
			tmp_obj.string.str.m_ptr = new char[tmp_obj.size()];

			strcpy(tmp_obj.string.str.m_ptr, tmp_str);
			strcat(tmp_obj.string.str.m_ptr, new_str);

			tmp_obj.m_Is_on_stack = false; 
		}
	} else {
		
		tmp_obj.string.str.m_size = tmp_obj.size() + strlen(new_str) + 1;
		tmp_obj.string.str.m_ptr = new char[tmp_obj.size()];
		
		strcpy(tmp_obj.string.str.m_ptr, this->string.str.m_ptr);
		
		strcat(tmp_obj.string.str.m_ptr, new_str);
	}

	return tmp_obj;	
}

Str operator+(const char* new_str, const Str& str)
{
	Str tmp_obj(str.c_str());
	if(tmp_obj.m_Is_on_stack) {
		if(strlen(new_str) + str.size() < STACK_SIZE){
			strcpy(tmp_obj.string.on_stack, new_str);
			strcat(tmp_obj.string.on_stack, str.string.on_stack);
		} else {
			tmp_obj.string.str.m_size = strlen(new_str) + str.size() + 1;
			tmp_obj.string.str.m_ptr = new char[tmp_obj.size()];
			
			strcpy(tmp_obj.string.str.m_ptr, new_str);
			strcat(tmp_obj.string.str.m_ptr, str.string.on_stack);

			tmp_obj.m_Is_on_stack = false;
		}		
	} else {
		tmp_obj.string.str.m_size = tmp_obj.size() + strlen(new_str) + 1;
		tmp_obj.string.str.m_ptr = new char[tmp_obj.size()];	

		strcpy(tmp_obj.string.str.m_ptr, new_str);
		strcat(tmp_obj.string.str.m_ptr, str.string.str.m_ptr);
	}

	return tmp_obj;
}

char& Str::operator[](int ind) 
{
	if(!m_Is_on_stack){
		if(this->string.str.m_ptr == nullptr){
			std::cout << "NULLPTR" << std::endl;
			exit(0);
		}
	
		if(ind >= 0 && ind < this->string.str.m_size){
			return *(this->string.str.m_ptr + ind);
		} else {
			std::cout << "ind must be >=0 && < size" << std::endl;
			exit(0);
		}
	} else {
		if(ind >= 0 && ind < strlen(this->string.on_stack)){
			return string.on_stack[ind];
		} else {
			std::cout << "ind must be >=0 && < size" << std::endl;
			exit(0);
		}
	}
}

char Str::operator[](int ind) const
{
	if(!m_Is_on_stack){
		if(this->string.str.m_ptr == nullptr){
			std::cout << "NULLPTR" << std::endl;
			exit(0);
		}
	
		if(ind >= 0 && ind < this->string.str.m_size){
			return *(this->string.str.m_ptr + ind);
		} else {
			std::cout << "ind must be >=0 && < size" << std::endl;
			exit(0);
		}
	} else {
		if(ind >= 0 && ind < strlen(this->string.on_stack)){
			return string.on_stack[ind];
		} else {
			std::cout << "ind must be >=0 && < size" << std::endl;
			exit(0);
		}
	}
}

std::ostream& operator<<(std::ostream& os, const Str& obj)
{
	for(int i = 0; i < obj.size(); ++i){
		os << obj[i];
	}
	return os;
}

std::istream& operator>>(std::istream& is, Str& str)
{
	for(int i = 0; i < obj.size(); ++i){
		is >> str[i];
	}
	return is;
}

#endif // Str_impl.h
