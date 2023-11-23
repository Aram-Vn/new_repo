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

void Reader::returnBook(const int id)
{
	if(id < 0){
		std::cout << "in returnBook(Reader)" << std::endl;
		std::cout << "id must be >= 0" << std::endl;
		return;
	}

	bool flag = false;
	int book_index = 0;

		for(int i = 0; i < m_issued_books.size(); ++i){
			if(m_issued_books[i] == id){
				flag = true;
				book_index = i;
				break;
			}
		}

		if(!flag){
			std::cout << "in (returnBook)" << std::endl;
			std::cout << "there is no such book_id" << std::endl;
		}	

		m_issued_books.erase(m_issued_books.begin() + book_index);
}
