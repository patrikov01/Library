#include "Book.h"
Book::Book() {
	author = "Empty author name";
	title = "Empty title";
	genre = "Empty genre";
	description = "Empty description";
	yearOfPublishing = 0;
	keyWords = "None";
	rating = 0;
	uniqueNumber = 0;
}
String Book::getAuthorName() const {
	return author;
}
String Book::getTitle() const {
	return title;
}
String Book::getGenre() const {
	return genre;
}
String Book::getDescription() const {
	return description;
}
int Book::getYearOfPublishing() const {
	return yearOfPublishing;
}
String Book::getKeyWords() const {
	return keyWords;
}
double Book::getRating() const {
	return rating;
}
long int Book::getUniqueNumber() const {
	return uniqueNumber;
}

void Book::setAuthorName(const String& _authorName) {
	author = _authorName;
}
void Book::setTitle(const String& _title) {
	title = _title;
}
void Book::setGenre(const String& _genre) {
	genre = _genre;
}
void Book::setDescription(const String& _description) {
	description = _description;
}
void Book::setYearOfPublishing(int _yearOfPublishing) {
	yearOfPublishing = _yearOfPublishing;
}
void Book::setKeyWords(const String& _keyWords) {
	keyWords = _keyWords;
}
void Book::setRating(double _rating) {
	rating = _rating;
}
void Book::setUniqueNumber(long int _uniqueNumber) {
	uniqueNumber = _uniqueNumber;
}
void Book::printInfo() const {
	std::cout << "Title: " << title << std::endl;
	std::cout << "Author: " << author << std::endl;
	std::cout << "Genre: " << genre << std::endl;
	std::cout << "Unique number: " << uniqueNumber << std::endl;
}

std::istream& operator>>(std::istream& in, Book& book) {
	in >> book.author;
	in >> book.title;
	in >> book.genre;
	in >> book.description;
	in >> book.keyWords;
	in >> book.yearOfPublishing;
	in >> book.rating;
	in >> book.uniqueNumber;
	return in;
}
std::ostream& operator<<(std::ostream& out, const Book& book) {
	out << book.author << std::endl;
	out << book.title << std::endl;
	out << book.genre << std::endl;
	out <<  book.description << std::endl;
	out << book.keyWords << std::endl;
	out << book.yearOfPublishing << std::endl;
	out <<  book.rating << std::endl;
	out <<  book.uniqueNumber << std::endl;
	return out;
}