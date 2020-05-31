#ifndef __USERS_H
#define __USERS_H

#include "User.h"
#include<vector>

class Users
{
private:
	std::vector<User> usersVector;
	int size;
public:
	bool add(std::string, std::string, bool);
	User* logIn(std::string, std::string);
	bool remove(std::string);
	int getSize();
};

#endif
