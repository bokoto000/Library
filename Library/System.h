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
	std::string usersPath;
	bool isLoaded;
public:
	System();
	bool readFile();
	void start();
	bool open(std::string); /*opens the data file*/
	bool close();/* closes the data file*/
	bool save();/*saves the data file*/
	void addBook(Book book);
	bool saveAs(std::string);/* saves the data in a different file than the currently loaded*/
	bool logout(); /* logout by setting the user pointer to null*/
	bool login(std::string, std::string); 
	bool requireAdmin(); /* checks if an admin is logged*/
	bool requireUser(); /* checks if an user is logged*/
	void addUser(std::string, std::string, bool);
	void userRemove(std::string);
	void bookFind(std::string option, std::string optionString);
	void bookAll();
	void bookSort(std::string,std::string);
	void bookInfo(int);
};

#endif