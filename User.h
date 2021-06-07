#pragma once
#include <iostream>
#include "myString.h"
class User {
private:
	String username;
	String password;
	bool isAdmin;

public:
	User();
	User(const String& _username,const String& _password, bool _isAdmin);

	String getUsername() const;
	String getPassword() const;
	bool getIsAdmin() const;

	void setUsername(const String& _username);
	void setPassword(const String& _password);
	void setIsAdmin(bool _isAdmin);

	friend std::ostream& operator<<(std::ostream& out, const User& user);
	friend std::istream& operator>>(std::istream& in, User& user);
};
