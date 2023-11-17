#ifndef BOOK_H
#define BOOK_H

#include <iostream>

class Book
	{
public:
	/* Book(); */
	Book(std::string title, std::string author);
	
public:
	//geters
	const int get_id() const;
	std::string get_author() const;
	std::string get_title() const;
	bool is_available() const;
	
	//seters
	/* void set_title(std::string new_title); */
	/* void set_author(std::string new_author); */
	void set_availibility(bool flag);
	
private:
	static int id;
	const int m_id;
	std::string m_title;
	std::string m_author;
	bool m_availibility;
};

#endif
