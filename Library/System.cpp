#include "System.h"

System::System()
{
	users.add("admin", "i<3c++", true);
	usersPath = "defaultUsers.txt";
}


bool System::readFile()
{
	std::ifstream database,usersDb;
	database.open(this->filePath);
	usersDb.open(this->usersPath);
	std::string line,desc,tagsStr;
	std::vector<std::string> args,tags;
	if (database.is_open())
	{
		for (int i = 0; std::getline(database, line); i++)
		{
			args = helper::splitString(line);
			if (std::getline(database, desc)) {

			}
			else {
				std::cout << "Problem reading file" << std::endl;
				database.close();
				return false;
			}
			if (std::getline(database, tagsStr)) {
				tags = helper::splitString(tagsStr);
			}
			else {
				std::cout << "Problem reading file" << std::endl;
				database.close();
				return false;
			}
			try {
				Book newEntry(args.at(0), args.at(1), args.at(2), args.at(3), std::stoi(args.at(4)), tags, std::stof(args.at(5)));
				books.add(newEntry);
			}
			catch (...) {

				std::cout << "Problem reading file" << std::endl;
				database.close();
				return false;
			}
		}
		database.close();
		std::cout << "Successfully opened file" << std::endl;
	}
	else {
		std::cout << "Problem opening file" << std::endl;
	}
	if (usersDb.is_open())
	{
		for (int i = 0; std::getline(usersDb, line); i++)
		{
			args = helper::splitString(line);
			try {
				users.add(args.at(0), args.at(1), std::stoi(args.at(2)));
			}
			catch (...) {
				std::cout << "Problem reading file" << std::endl;
				usersDb.close();
				return false;
			}
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
	std::ofstream database,usersDatabase;
	database.open(filePath, std::ios::out);
	usersDatabase.open(usersPath, std::ios::out);
	if (database.is_open())
	{
		books.save(database);
		users.save(usersDatabase);
		std::cout << "Successfully saved" << std::endl;
		database.close();
	}
	else {
		std::cout << "Error opening file" << std::endl;
	}
	return false;
}

void System::addBook(Book book) {
	if (!requireAdmin())return; 
	books.add(book);
}


bool System::requireUser()
{
	if (loggedUser != NULL) return true;
	std::cout << "You do not have permission. Please log in!" << std::endl;
	return false;
}

void System::addUser(std::string un, std::string pass, bool isAdmin)
{
	users.add(un, pass, isAdmin);
}

void System::userRemove(std::string username)
{
	if (users.remove(username))std::cout << "User deleted successfully" << std::endl;
	else std::cout << "User not found" << std::endl;
}

void System::bookFind(std::string option, std::string optionString)
{
	books.find(option, optionString);
}

void System::bookAll()
{
	books.all();
}

void System::bookSort(std::string opt, std::string asc)
{
	books.sort(opt, asc);
}

void System::bookInfo(int id)
{
	books.info(id);
}


bool System::logout()
{
	loggedUser = NULL;
	return true;
}

bool System::login(std::string user, std::string pass)
{
	loggedUser = users.logIn(user, pass);
	if (loggedUser!=NULL) {
		std::cout << "Successfull login" << std::endl;
		return true;
	}
	std::cout << "Login failed" << std::endl;
	return false;
}

bool System::requireAdmin()
{
	if (!requireUser()) return false;
	if (requireUser()&&loggedUser->isUserAdmin() == true) return true;
	std::cout << "You do not have permission. Please log in!" << std::endl;
	return false;
}