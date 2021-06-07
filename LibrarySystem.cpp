#include "LibrarySystem.h"
Library::Library() {
	strcpy_s(bookFile,9, "Book.txt");
	isOpenedFile = false;
}
void Library::open() {
	std::ifstream in;
	std::cout << "File: ";
	std::cin >> bookFile;
	in.open(bookFile, std::ios::in);
	if (!in) {
		std::ofstream outfile(bookFile);
		std::cout << "New empty file was created" << std::endl;
		isOpenedFile = true;
		outfile.close();
	}
	else {
			std::cout << "Successfully opened " << bookFile << std::endl;
			library.loadBooks(in);
			isOpenedFile = true;
	}
	in.close();
	
	in.open("User.txt", std::ios::in);
	if (!in) {
		std::cout << "Error while opening the users file..." << std::endl;
	}
	else {
		users.loadUsers(in);
	}
	in.close();
}
void Library::close() {
	std::cout << "Successfully closed " << bookFile << std::endl;
	isOpenedFile = false;
}
void Library::save() {
	std::ofstream out;
	out.open(bookFile, std::ofstream::out | std::ofstream::trunc);
	library.saveBooks(out);
	std::cout << "Successfully saved " << bookFile << std::endl;
	out.close();
}
void Library::saveAs() {
	std::ofstream out;
	char file[256];
	std::cout << "File: ";
	std::cin >> file;
	out.open(file, std::ofstream::out | std::ofstream::trunc);
	library.saveBooks(out);
	std::cout << "Successfully saved " << file << std::endl;
	out.close();
}
void Library::exit() {
	std::cout << "Exiting the program..." << std::endl;
}
void Library::help() const{
	std::cout << "Help: Available commands are: " << std::endl;
	std::cout << "Open <file> opens <file>" << std::endl;
	std::cout << "Close	closes currently opened file" << std::endl;
	std::cout << "Save	saves the currently open file" << std::endl;
	std::cout << "Save as <file> saves the currently open file in <file>" << std::endl;
	std::cout << "Login enters the user into the library based on username and password" << std::endl;
	std::cout << "Logout exits the user from the library" << std::endl;
	std::cout << "Books all prints info for all the books" << std::endl;
	std::cout << "Books info prints detailed info based on unique number" << std::endl;
	std::cout << "Books find helps you to find a book based on title/author/tags" << std::endl;
	std::cout << "Books sort can sort books asc/desc based on title/year/author/rating" << std::endl;
	std::cout << "Admin: Users add registers new user based on username and password" << std::endl;
	std::cout << "Admin: Users remove deletes user based on username" << std::endl;
	std::cout << "Admin: Books add adds a book into the library" << std::endl;
	std::cout << "Admin: Books remove deletes a book from the library based on a title" << std::endl;
}
void Library::start() {
     String command;
	 std::cout << "Library started...Please enter a valid command: ";
	 do {
		 std::cin >> command;
		 command.validateIntervals();
		 if (command == "" || command==" ") {
			 continue;
		 }
		 else if (command == "login" && isOpenedFile) {
			 users.login();
		 }
		 else if (command == "logout" && users.getIsLoggedUser() && isOpenedFile) {
			 users.logout();
		 }
		 else if (command == "books all" && users.getIsLoggedUser() && isOpenedFile) {
			 library.booksAll();
		 }
		 else if (command == "books info" && users.getIsLoggedUser() && isOpenedFile) {
			 library.booksInfo();
		 }
		 else if (command == "books find" && users.getIsLoggedUser() && isOpenedFile) {
			 library.booksFind();
		 }
		 else if (command == "books sort" && users.getIsLoggedUser() && isOpenedFile) {
			 library.booksSort();
		 }
		 else if (command == "help") {
			 help();
		 }
		 else if (command == "users add" && users.isCurrentUserAdmin() && users.getIsLoggedUser() && isOpenedFile) {
			 users.usersAdd();
		 }
		 else if (command == "users remove" && users.isCurrentUserAdmin() && users.getIsLoggedUser() && isOpenedFile) {
			 users.usersRemove();
		 }
		 else if (command == "books add" && users.isCurrentUserAdmin() && users.getIsLoggedUser() && isOpenedFile) {
			 library.booksAdd();
		 }
		 else if (command == "books remove" && users.isCurrentUserAdmin() && users.getIsLoggedUser() && isOpenedFile) {
			 library.booksRemove();
		 }
		 else if (command == "open") {
			 open();
	     }
		 else if (command == "save" && isOpenedFile) {
			save();
		 }
		 else if (command == "save as" && isOpenedFile) {
			 saveAs();
		 }
		 else if (command == "close" && isOpenedFile) {
			 close();
		 }
		else {
			std::cout << "Invalid command"<<std::endl;
		 }
		 } while (command != "exit");
		 exit();
	}