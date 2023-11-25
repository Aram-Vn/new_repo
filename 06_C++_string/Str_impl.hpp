#ifndef STR_IMPL_H
#define STR_IMPL_H

#include "Str.h"
#include <cstring>

Str::Str()
{
	string.on_stack[0] = '\0';
}	

Str::Str(const char* new_str)
{
	int len = strlen(new_str);

	if(len < 16){
		strcpy(string.on_stack, new_str);
	} else {
		string.str.m_ptr = new char[len + 1];
		string.str.m_size = len;
		strcpy(string.str.m_ptr, new_str);
	}
}




#endif // Str_impl.h
