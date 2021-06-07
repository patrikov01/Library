#pragma once
#include <iostream>
#include "myString.h"
class Book {
private:
	String author;
	String title;
	String genre;
	String description;
	int yearOfPublishing;
	String keyWords;
	double rating;
	long int uniqueNumber;

public:
	Book();

    String getAuthorName() const;
	String getTitle() const;
	String getGenre() const;
	String getDescription() const;
	int getYearOfPublishing() const;
	String getKeyWords() const;
	double getRating() const;
	long int getUniqueNumber() const;

	void setAuthorName(const String& _authorName);
	void setTitle(const String& _title);
	void setGenre(const String& _genre);
	void setDescription(const String& _description);
	void setYearOfPublishing(int _yearOfPublishing);
	void setKeyWords(const String& _keyWords);
	void setRating(double _rating);
	void setUniqueNumber(long int _uniqueNumber);

	friend std::istream& operator>>(std::istream& in, Book& book);
	friend std::ostream& operator<<(std::ostream& out, const Book& book);
	void printInfo() const;
};