#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include  "1__book.h"
#include  "2__reader.h"
#include  "3__Library.h"


class Library
{
public:
	/* void addReader(const Reader& reader); */
	/* void addBook(const Book& book); */

	void add_reader(const std::string& new_name, const int book_ind);
	void add_book(const std::string& title, const std::string& author);

	void issue_book(int book_id, int reader_id);
	void return_book(int book_id, int reader_id);

	//geters
	Book get_book(int index) const;
	Reader get_reader(int index) const;

private:
	std::vector<Book> m_books;
	std::vector<Reader> m_readers;
};

#endif
