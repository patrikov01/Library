#pragma once
#include "myVector.h"
#include "myString.h"
#include "Book.h"
#include "User.h"
#include "VectorBooks.h"
#include "VectorUser.h"
class Library {
private:
	VectorBooks library;
	VectorUsers users;

	char bookFile[256];
	bool isOpenedFile;
public:
	Library();

	void open();
	void close();
	void save();
	void saveAs();
	void help() const;
	void exit();

	void start();
};