#ifndef __USER_H
#define __USER_H

#include<string>

class User
{
private:
	std::string username;
	std::string password;
	bool isAdmin;
public:
	User();
	User(std::string,std::string, bool);
};

#endif
