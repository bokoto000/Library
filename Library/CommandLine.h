#ifndef __COMMANDLINE_H
#define __COMMANDLINE_H
#include<string>
#include<iostream>
#include "System.h"
#include "Helper.h"


class CommandLine
{
private:
	System* system;
	bool isOpened = false;
public:
	CommandLine(System* system);
	void start();
	void commandHandler(std::vector<std::string> splitInput);
	void booksCommandHandler(std::vector<std::string> args);
	void addBook();
};

#endif