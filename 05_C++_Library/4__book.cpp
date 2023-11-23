#include <iostream>
#include "1__book.h"

int Book::id = 0;

Book::Book(std::string title, std::string author) : 
	m_id{++id},
	m_title{title},
	m_author{author},
	m_availibility{true}
{}

const int Book::get_id() const 
{
	return m_id;
}

std::string Book::get_author() const
{
	return m_author;
}

std::string Book::get_title() const
{
	return m_title;
}

bool Book::is_available() const
{
	return m_availibility;
} 

void Book::set_availibility(bool flag)
{
	m_availibility = flag;
}



