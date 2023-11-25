#ifndef STR_H
#define STR_H

class Str 
{ 
public:
	Str();
	Str(const char* new_str);

private:
	bool m_Is_on_stack;

    struct dyn_str 
    { 
        int m_size; 
		char* m_ptr;
    };
 
    union { 
        char on_stack[16]; 
        dyn_str str; 
    } string; 
};


#endif // Str.h
