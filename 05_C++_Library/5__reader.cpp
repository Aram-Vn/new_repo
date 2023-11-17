#include <iostream>
#include <vector> 

#include "2__reader.h"


Reader::Reader(std::string name, int book_ind) : 
	m_id{++id},
	m_name{name}
{
	m_issued_books.push_back(book_ind);
}

const int Reader::get_id() const
{
	return m_id;
}

std::string Reader::get_name() const
{
	return m_name;
}

std::vector<int> Reader::get_issued_Books() const
{
	return m_issued_books;
}




