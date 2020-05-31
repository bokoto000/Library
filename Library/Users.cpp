#include "Users.h"

bool Users::add(std::string username, std::string password, bool isAdmin)
{
	for (int i = 0; i < this->size; i++) {
		if (usersVector[i].getUsername() == username) {
			return true;
		}
	}
	usersVector.push_back(User(username, password, isAdmin));
	this->size++;
	return false;
}

User* Users::logIn(std::string username, std::string password)
{
	for (int i = 0; i < this->size; i++) {
		if (usersVector[i].getUsername() == username) {
			if (usersVector[i].comparePasswords(password))return &usersVector[i];
		}
	}
	return NULL;
}

int Users::getSize()
{
	return this->size;
}

bool Users::remove(std::string username)
{
	for (int i = 0; i < this->size; i++) {
		if (usersVector[i].getUsername() == username) {
			usersVector.erase(usersVector.begin() + i);
			return true;
		}
	}
	return false;
}
