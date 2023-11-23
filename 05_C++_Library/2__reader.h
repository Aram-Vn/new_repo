#ifndef READER_H
#define READER_H  

#include <iostream>
#include <vector> 

class Reader{
public:
	Reader(std::string name, int book_ind);

public:
	//geters
	const int get_id() const;
	std::string get_name() const;
	std::vector<int> get_issued_Books() const;

	//seters
	/* void set_name(std::string new_name); */

public:
	void returnBook(const int id);

private:
	static int id;
	const int m_id;
	std::string m_name;
	std::vector<int> m_issued_books;
};

#endif //2__reader.h
