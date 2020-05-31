#ifndef __SYSTEM_H
#define __SYSTEM_H

#include "User.h"
#include "Book.h"
#include "Users.h"
#include "Books.h"
#include "Helper.h"
#include<vector>
#include<string>
#include<fstream>
#include<iostream>
#include <iterator>

class System
{
private:
	Books books;
	User* loggedUser;
	Users users;
	std::string filePath;
	bool isLoaded;
public:
	System();
	bool readFile();
	void start();
	bool open(std::string);
	bool close();
	bool save();
	void addBook(Book book);
	bool saveAs();
	bool logout();
	bool login();

};

#endif