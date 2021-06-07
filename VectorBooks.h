#pragma once
#include "Book.h"
#include "myVector.h"
class VectorBooks{
private:
	Vector<Book> library;
public:
	VectorBooks();

	void booksAll() const;
	void booksInfo() const;
	void booksFind();
	void booksSort();
	void booksAdd();
	void booksRemove();

	void saveBooks(std::ostream& out);
	void loadBooks(std::istream& in);

	size_t getSize() const;
	Book& operator[](size_t index);
};