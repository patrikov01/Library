#include "VectorUser.h"
VectorUsers::VectorUsers() {
	String _username = "admin";
	String _password = "i<3c++";
	User defaultUser(_username, _password, 1);
	users.pushBack(defaultUser);
	isLoggedUser = false;
	indexOfCurrentUser = -1;
}
void VectorUsers::login() {
	String _username;
	String _password;
	std::cout << "Enter username: ";
	std::cin >> _username;
	std::cout << "Enter password: ";
	std::cin >> _password;
	size_t tries = 0;
	for (size_t i = 0; i < users.getSize(); i++) {
		if (users[i].getUsername() == _username && users[i].getPassword() == _password) {
			std::cout << "Welcome, " << _username << std::endl;
			isLoggedUser = true;
			indexOfCurrentUser = i;
			if (tries > 0) {
				std::cout << "You are already logged in" << std::endl;
			}
			return;
		}
	}
	std::cout << "Try again" << std::endl;
	tries++;
	login();
}
void VectorUsers::logout() {
	    isLoggedUser = false;
		indexOfCurrentUser = -1;
		std::cout << "User logged out" << std::endl;
}

void VectorUsers::usersAdd() {
	String _username;
	std::cout << "Enter username: ";
	std::cin >> _username;
	String _password;
	std::cout << "Enter password: ";
	std::cin >> _password;
	for (size_t i = 0; i < users.getSize(); i++) {
		if (_username == users[i].getUsername()) {
			std::cout << "This username is already taken" << std::endl;
			return;
		}
	}
	User newUser;
	newUser.setUsername(_username);
	newUser.setPassword(_password);
	users.pushBack(newUser);

	std::ofstream out;
	out.open("User.txt", std::ofstream::out | std::ofstream::trunc);
	saveUsers(out);
	out.close();
}
void VectorUsers::usersRemove() {
	String _username;
	std::cout << "Enter username: ";
	std::cin >> _username;
	for (size_t i = 0; i < users.getSize(); i++) {
		if (users[i].getUsername() == _username) {
			users.eraseElement(i);
		}
	}
	std::ofstream out;
	out.open("User.txt", std::ofstream::out | std::ofstream::trunc);
	saveUsers(out);
	out.close();
}
bool VectorUsers::getIsLoggedUser() const{
	return isLoggedUser;
}
void VectorUsers::setIsLoggedUser(bool _isLoggedUser) {
	isLoggedUser = _isLoggedUser;
}
size_t VectorUsers::getIndexOfCurrentUser() const{
	return indexOfCurrentUser;
}
void VectorUsers::setIndexOfCurrentUser(size_t _indexOfCurrentUser) {
	indexOfCurrentUser = _indexOfCurrentUser;
}
bool VectorUsers::isCurrentUserAdmin() const {
	return users[indexOfCurrentUser].getIsAdmin();
}
void VectorUsers::saveUsers(std::ostream& out) {
	size_t size = users.getSize();
	out << '[';
	for (size_t i = 0; i < size; i++) {
		out << users[i];
		out << '\n';
		if (i < size - 1) {
			out << ',';
		}
	}
	out << ']';
}
void VectorUsers::loadUsers(std::istream& in) {
	char c;
	User user;
	Vector<User> resultUs;
	in >> c;

	while (c != ']' && in.peek() != ']') {
		in >> user;
		resultUs.pushBack(user);
		in >> c;
	}
	users = resultUs;
}
size_t VectorUsers::getSize() const {
	return users.getSize();
}
User& VectorUsers::operator[](size_t index) {
	if (index >= 0 && index < users.getSize()) {
		return users[index];
	}
	throw std::out_of_range("Out of range\n");
}