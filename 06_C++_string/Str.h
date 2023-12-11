#ifndef STR_H
#define STR_H

enum {STACK_SIZE = 16};

class Str 
{ 
public:
	Str();
	~Str();
	Str(const char* new_str);

	Str(const Str& other);	
	Str(Str&& other) noexcept;

	Str& operator=(const Str& other);
	Str& operator=(Str&& other) noexcept;

	Str& operator+=(const Str& other);
	Str& operator+=(const char* new_str);

	Str operator+(const Str& other);
	Str operator+(const char* new_str);
	friend Str operator+(const char* new_str, const Str& str);  

	char& operator[](int ind);
	char operator[](int ind) const;

	int size() const;
	const char* c_str() const;

public:
	void print();

private:
	bool m_Is_on_stack;

    struct dyn_str 
    { 
        int m_size; 
		char* m_ptr;
    };

    union { //std::variant 
        char on_stack[16]; 
        dyn_str str; 
    } string; 
};

Str operator+(const char* new_str, const Str& str);
std::ostream& operator<<(std::ostream&, const Str&);
td::istream& operator>>(std::istream& is, Str& str);

#endif // Str.h
