#include "User.h"

User::User() {
	username = "";
	password = "";
	isAdmin = 0;
}

User::User(std::string _username, std::string _password, bool _isAdmin)
{
	username = _username;
	password = _password;
	isAdmin = _isAdmin;
}

std::string User::getUsername()
{
	return username;
}

bool User::comparePasswords(std::string salt)
{
	if (password == salt)return true;
	return false;
}

bool User::isUserAdmin() {
	return isAdmin;
}