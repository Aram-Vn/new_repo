#include <iostream>
#include <vector>
#include "3__Library.h"

void Library::add_reader(const std::string& new_name, const int book_ind)
{
	std::cout << new_name << "\nreader added" << std::endl;
	m_readers.emplace_back(new_name, book_ind );
}

void Library::add_book(const std::string& title, const std::string& author)
{
	std::cout << title << "\nbook added" << std::endl;
	m_books.emplace_back(title, author);
}

void Library::issue_book(int book_id, int reader_id)
{
	int book_index = -1;
	int reader_index = -1 ;
	
		if(book_id <= 0 && reader_id <= 0){
			std::cout << "in (issue_book)(6__Library.cpp)" << std::endl;
			std::cout << "book_id and reader_id must be >= 0" << std::endl;
			return;
		}

	bool flag = false;

		for(int i = 0; i < m_books.size(); ++i){
			if(m_books[i].get_id() == book_id){
				flag = true;
				book_index = i;
				break;
			}
		}

		if(!flag){
			std::cout << "in(issue_book)(6__Library.cpp)" << std::endl;
			std::cout << "there is no such book_id" << std::endl;
			return;
		} else if(!m_books[book_index].is_available()){
			std::cout << "in(issue_book)(6__Library.cpp)" << std::endl;
			std::cout << "sorry that book is not available" << std::endl;	
			return;
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
			std::cout << "in(issue_book)(6__Library.cpp)" << std::endl;
			std::cout << "there is no such reader_id" << std::endl;
			return;
		}

	std::cout << "reader: " <<  m_readers[reader_index].get_name() << std::endl;
	std::cout << "issued book: " <<  m_books[book_index].get_title() << std::endl;		
	std::cout << "issued book author: " << m_books[book_index].get_author() << std::endl;

	m_books[book_index].set_availibility(false);
	m_readers[reader_index].addBook(book_id);	
}

void Library::return_book(int book_id, int reader_id)
{
		if(book_id <= 0 && reader_id <= 0){
			std::cout << "in (issue_book)(6__Library.cpp)" << std::endl;
			std::cout << "book_id and reader_id must be >= 0" << std::endl;
			return;
		}

	int book_index = -1;
	int reader_index = -1 ;
	bool flag = false;

		for(int i = 0; i < m_books.size(); ++i){
			if(m_books[i].get_id() == book_id){
				flag = true;
				book_index = i;
				break;
			}
		}

		if(!flag){
			std::cout << "in(return_book)(6__Library.cpp)" << std::endl;
			std::cout << "there is no such book_id" << std::endl;
			return;
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
			std::cout << "in(return_book)(6__Library.cpp)" << std::endl;
			std::cout << "there is no such reader_id" << std::endl;
			return;
		}


	std::cout << "reader: " <<  m_readers[reader_index].get_name() << std::endl;
	std::cout << "returned book: " <<  m_books[book_index].get_title() << std::endl;		
	std::cout << "returned book author: " << m_books[book_index].get_author() << std::endl;

	m_books[book_index].set_availibility(true);
	m_readers[reader_index].returnBook(m_books[book_index].get_id());	 
}

/* Book get_book(int index) const */
/* { */

/* } */
