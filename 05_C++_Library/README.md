# Library Management system
******************************************************
## Book Management

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

**********************************************

## Reader Management

- **Data Members:**
  - `int readerID`
  - `std::string name`
  - `std::vector<int> issuedBooks`

- **Member Functions:**
  - `int getId() const;`
  - `std::string getName() const;`
  - `std::vector<int> getIssuedBooks() const;`
  - `void returnBook(int id);`
***************************************

#Library Management

- **Data Members:**
  - `std::vector<Book> books`
  - `std::vector<Reader> readers`

- **Member Functions:**
  - `void addReader(const Reader& reader);`
  - `void addBook(const Book& book);`
  - `void issueBook(int book_id, int reader_id);`
  - `void returnBook(int book_id, int reader_id);`
  - `Book getBook(int index) const;`
  - `Reader getReader(int index) const;`
