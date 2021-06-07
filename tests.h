#define DOCTEST_CONFIG_IMPLEMENT
#include "Doctests.h"
#include "myString.h"
#include "VectorUser.h"
#include "VectorBooks.h"

TEST_CASE("Book default constructor")
{
	Book b;
	CHECK(b.getAuthorName() == "Empty author name");
	CHECK(b.getTitle() == "Empty title");
	CHECK(b.getGenre() == "Empty genre");
	CHECK(b.getDescription() == "Empty description");
	CHECK(b.getYearOfPublishing() == 0);
	CHECK(b.getKeyWords() == "None");
	CHECK(b.getRating() == 0);
	CHECK(b.getUniqueNumber() == 0);
}
TEST_CASE("User default constructor") {
	User u;
	CHECK(u.getUsername() == "user");
	CHECK(u.getPassword() == "1234");
	CHECK(u.getIsAdmin() == false);
}
TEST_CASE("string intervals") {
	String command = "     help    ";
	command.validateIntervals();
	CHECK(command == "help");
}
TEST_CASE("push back") {
	Vector<Book> lib;
	Book b;
	lib.pushBack(b);
	CHECK(lib.getSize()==1);
}
TEST_CASE("lexicographically") {
	String s1 = "abcde";
	String s2 = "abcd";
	CHECK(s1 > s2);
}
TEST_CASE("setters and getters") {
	Book b;
	User u;
	b.setAuthorName("vazov");
	u.setUsername("cska");
	CHECK(b.getAuthorName() == "vazov");
	CHECK(u.getUsername() == "cska");
	Vector<User> users;
	User u1("abc", "0000", 0);
	User u2("abc", "0000", 0);
	User u3("abc", "0000", 0);
	users.pushBack(u1);
	users.pushBack(u2);
	users.pushBack(u3);
	CHECK(users.getSize() == 3);
}
TEST_CASE("copy") {
	User u;
	User u1(u);
	CHECK(u.getUsername() == u1.getUsername());
	CHECK(u.getPassword() == u1.getPassword());
}
TEST_CASE("swap") {
	Book b;
	Book(b2);
	b.setTitle("abcde");
	b2.setTitle("abcd");
	Vector<Book> books;
	books.pushBack(b);
	books.pushBack(b2);
	bool isSwapped = false;
	if (b.getTitle() > b2.getTitle()) {
		books.swap(b, b2);
		isSwapped = true;
	}
	CHECK(isSwapped);
}
TEST_CASE("string ==") {
	String s = "abc";
	String s2 = "abc";
	CHECK(s == "abc");
	CHECK(s == s2);
}
TEST_CASE("pop back") {
	String s = "abc";
	s.popBack();
	CHECK(s == "ab");
}
TEST_CASE("length") {
	String s = "abcdefg";
	CHECK(s.getSize() == 7);
}
void runTests() {
	doctest::Context().run();
}