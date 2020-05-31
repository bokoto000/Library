#ifndef __COMMANDLINE_H
#define __COMMANDLINE_H
#include<string>
#include<iostream>
#include "System.h"
#include "Helper.h"
#include <stdlib.h>

/*The command interface which is used for the system api*/
class CommandLine
{
private:
	System* system; /* pointer to the system*/
	bool isOpened = false;
public:
	CommandLine(System* system);
	void start(); /* starts the engine for detecting commands*/
	void commandHandler(std::vector<std::string> splitInput);/*this all the commands*/
	void userCommandHandler(std::vector<std::string> args);/* handles the commands for user*/
	void booksCommandHandler(std::vector<std::string> args);/* handles the commands for books*/
	//the following functions inputs data and gives it to the system
	void help(); 
	void login();
	void usersRemove();
	void addUser(); 
	void addBook();
};

#endif