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
			bool compare = usersVector[i].comparePasswords(password);
			if (compare)return &usersVector[i];
		}
	}
	return NULL;
}

int Users::getSize()
{
	return this->size;
}

void Users::save(std::ofstream& database)
{
	for (int i = 0; i < this->usersVector.size(); i++) {
		database << usersVector[i].getUsername() << " " << usersVector[i].getPassword() << " " << usersVector[i].getIsAdmin();
		database << std::endl;
	}
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
