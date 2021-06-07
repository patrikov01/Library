#include "myString.h"
void String::copy(const String& other) {
	capacity = other.capacity;
	size = other.size;
	string = new char[capacity];
	strcpy_s(string, capacity, other.string);
}

void String::erase() {
	delete[] string;
}

void String::resize() {
	capacity *= 2;
	char* newString = new char[capacity];
	for (size_t i = 0; i < size; i++)
	{
		newString[i] = string[i];
	}
	delete[] string;
	string = newString;
}
String::String() {
	capacity = 8;
	size = 0;
	string = new char[capacity];
	string[0] = '\0';
}

String::String(const char* other) {
	capacity = strlen(other) + 1;
	string = new char[capacity];
	strcpy_s(string, capacity, other);
	size = strlen(other);
}

String::~String() {
	erase();
}

String::String(const String& other) {
	copy(other);
}

String& String::operator=(const String& other) {
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
}

String& String::operator=(const char* other) {
	erase();
	capacity = strlen(other) + 1;
	string = new char[capacity];
	size = strlen(other);
	strcpy_s(string, capacity, other);
	return *this;
}

String& String::operator+=(char newChar) {
	if (size+1 >= capacity) {
		resize();
	}
	string[size] = newChar;
	size++;
	string[size] = '\0';
	return *this;
}
bool String::operator>(const String& other) {
	size_t shorterString = 0;
	if (size >= other.getSize()) {
		shorterString = size;
	}
	else {
		shorterString = other.size;
	}
	bool equal = true;
	for (size_t i = 0; i < shorterString; i++) {
		if (string[i] < other.string[i]) {
			return false;
			break;
		}
		if (string[i] != other.string[i]) {
			equal = false;
		}
	}
	if (equal && size > other.size) {
		return true;
	}
	if (equal && size < other.size) {
		return false;
	}
	return true;
}
bool String::operator<(const String& other) {
	size_t shorterString = 0;
	if (size >= other.getSize()) {
		shorterString = size;
	}
	else {
		shorterString = other.size;
	}
	bool equal = true;
	for (size_t i = 0; i < shorterString; i++) {
		if (string[i] > other.string[i]) {
			return false;
			break;
		}
		if (string[i] != other.string[i]) {
			equal = false;
		}
	}
	if (equal && size > other.size) {
		return false;
	}
	if (equal && size < other.size) {
		return true;
	}
	return true;
}
bool String::operator==(const String& other) {
	return !strcmp(string, other.string);
}

bool String::operator!=(const String& other) {
	return strcmp(string, other.string);
}

char& String::operator[](size_t index) {
	if (index >= 0 && index < size - 1) {
		return string[index];
	}
}
size_t String::getSize() const {
	return size;
}
void String::popBack() {
	if (size >= 1) {
		size--;
		string[size] = '\0';
	}
}
void String::print() const {
	std::cout << string << std::endl;
}
void String::remove(size_t index) {
	for (size_t i = index; i < size; i++) {
		string[i] = string[i + 1];
	}
	size--;
	string[size] = '\0';
}
void String::validateIntervals() {
	for (size_t i = 0; i < size; i++) {
		if (string[i] == ' ') {
			size_t j = i + 1;
			while (string[j] == ' ') {
				remove(j);
				j++;
			}
              j = 0;
		}
			if (string[0] == ' ') {
				remove(0);
			}
			if (string[size-1] == ' ') {
				remove(size-1);
			}
	}
}	
std::ostream& operator<<(std::ostream& out, const String& _string) {
	out << _string.string;
	return out;
}
std::istream& operator>>(std::istream& in, String& _string) {
	for (size_t i = _string.size; i > 0; i--) {
		_string.popBack();
	}
	char ch = ' ';
	while (ch != '\n') {
		ch = in.get();
		_string += ch;
	}
	_string.popBack();
	return in;
}