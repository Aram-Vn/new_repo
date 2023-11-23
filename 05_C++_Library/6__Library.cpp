#include <iostream>
#include <vector>
#include "3__Library.h"

void Library::addReader(const Reader& reader)
{

	m_readers.push_back(reader);

}

void Library::addBook(const Book& book)
{
	m_books.push_back(book);
}

void Library::issue_book(int book_id, int reader_id)
{

	if(book_id < 0 && reader_id < 0){
		std::cout << "in (issue_book)" << std::endl;
		std::cout << "book_id and reader_id must be >= 0" << std::endl;
		return;
	}

	bool flag = false;
	int book_index = 0;
	int reader_index = 0;

		for(int i = 0; i < m_books.size(); ++i){
			if(m_books[i].get_id() == book_id){
				flag = true;
				book_index = i;
				break;
			}
		}

		if(!flag){
			std::cout << "in (issue_book)" << std::endl;
			std::cout << "there is no such book_id" << std::endl;
		} else if(!m_books[book_index].is_available()){
			std::cout << "in (issue_book)" << std::endl;
			std::cout << "sorry\nthat book is not available" << std::endl;	
		}	

		flag = false;		

		for(int i = 0; i < m_readers.size(); ++i){
			if(m_readers[i].get_id() == reader_id){
				flag = true;
				reader_index = i;
				break;
			}
		}

		if(!flag){
			std::cout << "in (issue_book)" << std::endl;
			std::cout << "there is no such reader_id" << std::endl;
		}
	
		m_books[book_index].set_availibility(false);
		m_readers[reader_index].addBook(book_id);	
}



/* void Library::add_reader(const std::string& new_name, const int book_ind) */
/* { */

/* 	m_readers.emplace_back(new_name, book_ind ); */

/* } */

/* void Library::add_book(const std::string& title, const std::string& author) */
/* { */
/* 	m_books.emplace_back(title, author); */
/* } */
