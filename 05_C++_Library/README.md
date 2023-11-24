# Library Management System

This is a simple Library Management System implemented in C++ with three main classes: `Book`, `Reader`, and `Library`. This system allows you to manage books and readers, issue and return books, and retrieve information about books and readers.

## Book Management

### Class `Book`

- **Data Members:**
  - `int bookID`
  - `std::string title`
  - `std::string author`
  - `bool status` (available or issued)

- **Member Functions:**
  - `int getId() const;`
  - `std::string getAuthor() const;`
  - `std::string getTitle() const;`
  - `bool getAvailability() const;`
  - `void setAvailability(bool available);`

## Reader Management

### Class `Reader`

- **Data Members:**
  - `int readerID`
  - `std::string name`
  - `std::vector<int> issuedBooks`

- **Member Functions:**
  - `int getId() const;`
  - `std::string getName() const;`
  - `std::vector<int> getIssuedBooks() const;`
  - `void returnBook(in

