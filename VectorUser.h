#pragma once
#include "User.h"
#include "myVector.h"
#include <fstream>
class VectorUsers{
private:
	Vector<User> users;
	size_t indexOfCurrentUser;
	bool isLoggedUser;
public:
	VectorUsers();

	void login();
	void logout();

	void usersAdd();
	void usersRemove();

	bool getIsLoggedUser() const;
	size_t getIndexOfCurrentUser() const;
	bool isCurrentUserAdmin() const;
	void setIsLoggedUser(bool _isLoggedUser);
	void setIndexOfCurrentUser(size_t _indexOfCurrentUser);

	void saveUsers(std::ostream& out);
	void loadUsers(std::istream& in);

	size_t getSize() const;
	User& operator[](size_t index);
};