#include "VectorBooks.h"
VectorBooks::VectorBooks() {
	
}
void VectorBooks::booksAll() const{
	for (size_t i = 0; i < library.getSize(); i++) {
		library[i].printInfo();
	}
}
void VectorBooks::booksInfo() const{
	long int _uniqueNumber = 0;
	std::cout << "Enter unique number: ";
	std::cin >> _uniqueNumber;
	bool isFound=false;
	for (size_t i = 0; i < library.getSize(); i++) {
		if (_uniqueNumber == library[i].getUniqueNumber()) {
			std::cout << library[i] << std::endl;
			isFound = true;
			break;
		}
	}
	if (!isFound) {
		std::cout << "Invalid unique number" << std::endl;
	}
}
void VectorBooks::booksFind() {
	String option;
	std::cout << "Enter option title/author/key word: ";
	std::cin >> option;
	option.validateIntervals();
	String explanation;
	std::cout << "Enter your explanation: ";
	std::cin >> explanation;
	explanation.validateIntervals();
	bool isFound=false;
	if (option == "title") {
		for (size_t i = 0; i < library.getSize(); i++) {
			if (explanation == library[i].getTitle()) {
				isFound = true;
				std::cout << library[i] << std::endl;
			}
		}
	}
	if (option == "author") {
		for (size_t i = 0; i < library.getSize(); i++) {
			if (explanation == library[i].getAuthorName()) {
				isFound = true;
				std::cout << library[i] << std::endl;
			}
		}
	}
	if (option == "tag") {
		for (size_t i = 0; i < library.getSize(); i++) {
			if (explanation == library[i].getKeyWords()) {
				isFound = true;
				std::cout << library[i] << std::endl;
			}
		}
	}
	if (!isFound) {
		std::cout << "Not found" << std::endl;
	}
}
void VectorBooks::booksSort() {
	String option;
	std::cout << "Enter option title/author/year/rating: ";
	std::cin >> option;
	option.validateIntervals();
	String ascOrDesc;
	std::cout << "Select order asc/desc: ";
	std::cin >> ascOrDesc;
	ascOrDesc.validateIntervals();
	if (option == "title" && ascOrDesc == "asc") {
		for (size_t i = 0; i < library.getSize(); i++) {
			for (size_t j = i + 1; j < library.getSize(); j++)
				if (library[i].getTitle() > library[j].getTitle()) {
					library.swap(library[i], library[j]);
				}
		}
	}
	if (option == "author" && ascOrDesc == "asc") {
		for (size_t i = 0; i < library.getSize(); i++) {
			for (size_t j = i + 1; j < library.getSize(); j++)
				if (library[i].getAuthorName() > library[j].getAuthorName()) {
					library.swap(library[i], library[j]);
				}
		}
	}
	if (option == "year" && ascOrDesc == "asc") {
		for (size_t i = 0; i < library.getSize(); i++) {
			for(size_t j=i+1;j< library.getSize(); j++)
				if (library[i].getYearOfPublishing() > library[j].getYearOfPublishing()) {
					library.swap(library[i], library[j]);
			}
		}
	}
	if (option == "rating" && ascOrDesc == "asc") {
		for (size_t i = 0; i < library.getSize(); i++) {
			for (size_t j = i + 1; j < library.getSize(); j++)
				if (library[i].getRating() > library[j].getRating()) {
					library.swap(library[i], library[j]);
				}
		}
	}
	if (option == "title" && ascOrDesc == "desc") {
		for (size_t i = 0; i < library.getSize(); i++) {
			for (size_t j = i + 1; j < library.getSize(); j++)
				if (library[i].getTitle() < library[j].getTitle()) {
					library.swap(library[i], library[j]);
				}
		}
	}
	if (option == "author" && ascOrDesc == "desc") {
		for (size_t i = 0; i < library.getSize(); i++) {
			for (size_t j = i + 1; j < library.getSize(); j++)
				if (library[i].getAuthorName() < library[j].getAuthorName()) {
					library.swap(library[i], library[j]);
				}
		}
	}
	if (option == "year" && ascOrDesc == "desc") {
		for (size_t i = 0; i < library.getSize(); i++) {
			for (size_t j = i + 1; j < library.getSize(); j++)
				if (library[i].getYearOfPublishing() < library[j].getYearOfPublishing()) {
					library.swap(library[i], library[j]);
				}
		}
	}
	if (option == "rating" && ascOrDesc == "desc") {
		for (size_t i = 0; i < library.getSize(); i++) {
			for (size_t j = i + 1; j < library.getSize(); j++)
				if (library[i].getRating() < library[j].getRating()) {
					library.swap(library[i], library[j]);
				}
		}
	}
	booksAll();
}
void VectorBooks::booksAdd() {
	Book newBook;
	std::cout << "Enter data for the new book: " << std::endl;
	std::cin >> newBook;
	for (size_t i = 0; i < library.getSize(); i++) {
		if (newBook.getUniqueNumber() == library[i].getUniqueNumber()) {
			std::cout << "This book already exists in the library!";
			return;
		}
	}
	library.pushBack(newBook);
}
void VectorBooks::booksRemove() {
	String _title;
	std::cout << "Enter title: ";
	std::cin >> _title;
	bool isFound = false;
	for (size_t i = 0; i < library.getSize(); i++) {
		if (library[i].getTitle() == _title) {
			isFound = true;
			library.eraseElement(i);
		}
	}
	if (!isFound) {
		std::cout << "Not found" << std::endl;
	}
}
void VectorBooks::saveBooks(std::ostream& out) {
	size_t size = library.getSize();
	out << '[';
	for (size_t i = 0; i < size; i++) {
		out << library[i];
		if (i < size - 1) {
			out << ',';
		}
	}
	out << ']';
}
void VectorBooks::loadBooks(std::istream& in) {
	char c;
	Book book;
	Vector<Book> resultLib;
	in >> c;

	while (c != ']' && in.peek() != ']') {
		in >> book; 
		resultLib.pushBack(book);
		in >> c; 
	}
	library = resultLib;
}
size_t VectorBooks::getSize() const {
	return library.getSize();
}
Book& VectorBooks::operator[](size_t index) {
	if (index >= 0 && index < library.getSize()) {
		return library[index];
	}
	throw std::out_of_range("Out of range\n");
}