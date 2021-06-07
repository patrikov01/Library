#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT
#include <fstream>
#include "myString.h"
#include "myVector.h"
#include "Book.h"
#include "User.h"
#include "LibrarySystem.h"
#include "Doctests.h"
#include "tests.h"
int main() {
	Library menu;
	runTests();
	menu.start();
}