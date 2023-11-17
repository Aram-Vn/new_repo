#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>

class Library
{
public:
	void add_reader(const Reader& reader);
	void add_book(const Book& book);
	void issue_book(int book_id, int reader_id);
	void return_book(int book_id, int reader_id);

	//geters
	Book get_book(int index) const;
	Reader get_reader(int index) const;

private:
	std::vector<Book> m_books;
	std::vector<Reader> m_readers;
}

#endif
