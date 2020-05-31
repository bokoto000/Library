#ifndef __USERS_H
#define __USERS_H

#include "User.h"
#include<vector>
#include<fstream>

class Users
{
private:
	std::vector<User> usersVector;
	int size;
public:
	bool add(std::string, std::string, bool)/* adds user  */;
	User* logIn(std::string, std::string) /* returns pointer to existing user */;
	bool remove(std::string);
	int getSize();
	void save(std::ofstream& database) /* saves users to text file */;
};

#endif
