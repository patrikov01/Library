#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
class String
{
private:
	char* string;
	size_t size;
	size_t capacity;

	void copy(const String& _string);
	void erase();
	void resize();

public:
	String();
	String(const char* other);
	~String();
	String(const String& other);

	String& operator=(const String& other);
	String& operator=(const char* other);
	bool operator==(const String& other);
	bool operator!=(const String& other);
	bool operator>(const String& other);
	bool operator<(const String& other);

	String& operator+=(char newChar);
	void popBack();
	void remove(size_t index);

	friend std::ostream& operator<<(std::ostream& out, const String& _string);
	friend std::istream& operator>>(std::istream& in, String& _string);

	char& operator[](size_t index);
	size_t getSize() const;
	void print() const;
	void validateIntervals();
};