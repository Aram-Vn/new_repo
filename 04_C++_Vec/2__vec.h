#ifndef VEC_HPP
#define VEC_HPP
 
#include <iostream>

class Vec
{
public:
	Vec();
	~Vec();
	Vec(int new_size, int val = int{});
	Vec(const Vec& other);
	Vec(Vec&& other) noexcept;
	
	int& operator[](int ind) const;

public:
	int get_size() const;
	int get_cap() const;
	
	void realloc();
	void push_back(const int& num);
	void pop_back();
	void insert(int index, int num);
	void erese(int index);
private:
	int m_size;
	int m_cap;
	int* m_ptr;
};

	std::ostream& operator<<(std::ostream&, const Vec&);

#endif // 1__vec.hpp
