#include "System.h"

System::System()
{
	users.add("admin", "i<3c++", true);
}


bool System::readFile()
{
	std::ifstream database;
	database.open(this->filePath);
	std::string line;
	if (database.is_open())
	{
		for (int i = 0; std::getline(database, line);i++)
		{
			helper::splitString(line);
		}
		database.close();
		std::cout << "Successfully opened file" << std::endl;
	}
	else {
		std::cout << "Problem opening file" << std::endl;
	}
	return false;
}

void System::start()
{
	readFile();
}

bool System::open(std::string _filePath)
{
	filePath = _filePath;
	isLoaded = true;
	std::ifstream database;
	database.open(this->filePath);
	std::string line;
	if (database.is_open())
	{
		for (int i = 0; std::getline(database, line); i++)
		{
			helper::splitString(line);
		}
		database.close();
		std::cout << "Successfully opened file" << std::endl;
		return true;
	}
	else {
		database.open(this->filePath, std::fstream::out);
		std::cout << "Created new file!" << std::endl;
	}
	return false;
	return false;
}

bool System::close()
{
	books.clear();
	isLoaded = false;
	filePath = "";
	std::cout << "Successfully closed " << filePath << std::endl;
	return false;
}

bool System::save()
{
	std::ofstream database;
	database.open(filePath,std::ios::out);
	if (database.is_open())
	{
		books.save(database);
		database.close();
	}
	else {
		std::cout << "Error opening file" << std::endl;
	}
	return false;
}

void System::addBook(Book book) {
	if(loggedUser!=NULL&&loggedUser->isUserAdmin()==true)
	books.add(book);
}