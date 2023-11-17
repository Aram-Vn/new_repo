#ifndef BOX_HPP
#define BOX_HPP

//#pragma once insted of #ifndef, #define and #endif

class Box{
	int m_length;
	int m_width;
	int m_height;
public:
	int get_length() const;
	int get_width() const;
	int get_height() const;

	Box();
	Box(const Box&);
	Box(int, int, int);

	~Box();
};


#endif //BOX.HPP
