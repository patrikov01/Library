#include "User.h"
User::User() {
	username = "user";
	password = "1234";
	isAdmin = false;
}
User::User(const String& _username,const String& _password, bool _isAdmin) {
	username = _username;
	password = _password;
	isAdmin = _isAdmin;
}

String User::getUsername() const {
	return username;
}
String User::getPassword() const {
	return password;
}
bool User::getIsAdmin() const {
	return isAdmin;
}
void User::setUsername(const String& _username) {
	username = _username;
}
void User::setPassword(const String& _password) {
	password = _password;
}
void User::setIsAdmin(bool _isAdmin) {
	isAdmin = _isAdmin;
}
std::ostream& operator<<(std::ostream& out, const User& user) {
	out << user.username << std::endl;
	out << user.password << std::endl;
	out << user.isAdmin;
	return out;
}
std::istream& operator>>(std::istream& in, User& user) {
	in >> user.username;
	in >> user.password;
	in >> user.isAdmin;
	return in;
}