#ifndef __SYSTEM_H
#define __SYSTEM_H

#include "User.h"
#include "Book.h"
#include<vector>
#include<string>

class System
{
private:
	std::vector<Book> books;
	User user;
	std::string filePath;
public:
	System(std::string);
	void start();
};

#endif