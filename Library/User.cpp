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
