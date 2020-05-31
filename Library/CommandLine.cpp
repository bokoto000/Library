#include "CommandLine.h"





std::string trim(const std::string& str)
{
	size_t first = str.find_first_not_of(' ');
	if (std::string::npos == first)
	{
		return str;
	}
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}

CommandLine::CommandLine(System* _system)
{
	system = _system;
}

void CommandLine::start()
{
	std::string input;
	for (;;) {
		std::getline(std::cin, input);
		std::vector<std::string> splitInput;
		input = trim(input);
		splitInput = helper::splitString(input);
		commandHandler(splitInput);
	}
}


void CommandLine::commandHandler(std::vector<std::string> splitInput) {
	try {
		if (splitInput.at(0) == "open") {
			std::string fileName = splitInput.at(1);
			if (system->open(trim(fileName)))
				isOpened = true;
		}
		if (isOpened == false) {
			std::cout << "Please open file first" << std::endl;
			return;
		}
		if (splitInput.at(0) == "close") {
			system->close();
			isOpened = false;
		}
		if (splitInput.at(0) == "save") {
			system->save();
		}
		else
			if (splitInput.at(0) == "saveas") {
				system->open(trim(splitInput.at(1)));
			}
		if (splitInput.at(0) == "help") {
			help();
		}
		if (splitInput.at(0) == "exit") {
			exit(NULL);
		}
		if (splitInput.at(0) == "login") {
			login();
		}
		if (splitInput.at(0) == "logout") {
			if (!system->requireUser())return;
			system->logout();
		}
		if (splitInput.at(0) == "books") {
			booksCommandHandler(splitInput);

		}
		if (splitInput.at(0) == "users") {
			if(!system->requireAdmin()) return;
			userCommandHandler(splitInput);
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << "Not enough arguments" << std::endl;
	}
}

void CommandLine::help() {
	std::cout << "List of commands" << std::endl;
	std::cout << "help" << std::endl;
	std::cout << "open <filepath>" << std::endl;
	std::cout << "close" << std::endl;
	std::cout << "save" << std::endl;
	std::cout << "login" << std::endl;
	std::cout << "logout" << std::endl;
	std::cout << "exit" << std::endl;
	std::cout << "books all" << std::endl;
	std::cout << "books find" << std::endl;
	std::cout << "books sort" << std::endl;
	std::cout << "books info" << std::endl;
	std::cout << "books add" << std::endl;
	std::cout << "books remove" << std::endl;
	std::cout << "users add" << std::endl;
	std::cout << "users remove" << std::endl;
}

void CommandLine::login() {
	std::string user, pass;
	std::cout << "Username: ";
	std::getline(std::cin, user);
	std::cout << std::endl << "Password: ";
	std::getline(std::cin, pass);
	std::cout << std::endl;
	system->login(user, pass);
}
void CommandLine::usersRemove() {
	std::string user, pass;
	std::cout << "Username: ";
	std::getline(std::cin, user);
	system->userRemove(user);
}

void CommandLine::addUser() {
	std::string user, pass, isAdmin;
	bool isAdminBool=false;
	std::cout << "Username: ";
	std::getline(std::cin, user);
	std::cout << std::endl << "Password: ";
	std::getline(std::cin, pass);
	std::cout << std::endl << "Is admin? (yes/no)";
	std::getline(std::cin, isAdmin);
	if (isAdmin == "yes") isAdminBool = true;
	system->addUser(user, pass,isAdminBool);
}

void CommandLine::userCommandHandler(std::vector < std::string> args) {
	try {
		if (!system->requireAdmin())return;
		if (args.at(1) == "add") {
		}
		if (args.at(1) == "remove") {

		}
	}
	catch (const std::out_of_range& e) {
		std::cout << "Not enough arguments" << std::endl;
	}
}

void CommandLine::booksCommandHandler(std::vector<std::string> args)
{
	try {
		if (!system->requireUser())return;
		if (args.at(1) == "all") {
			system->bookAll();
		}
		if (args.at(1) == "find") {
			system->bookFind(args.at(2),args.at(3));
		}
		if (args.at(1) == "sort") {
			system->bookSort(args.at(2), args.at(3));

		}
		if (args.at(1) == "info") {

			system->bookInfo(std::stoi(args.at(2)));
		}
		if (!system->requireAdmin())return;
		if (args.at(1) == "add") {
			addBook();
		}
		if (args.at(1) == "remove") {

		}
	}
	catch (const std::out_of_range& e) {
		std::cout << "Not enough arguments" << std::endl;
	}

}

void CommandLine::addBook()
{
	if(!system->requireAdmin())return;
	std::cout << "Please enter:" << std::endl;
	std::string title, author,genre,description,tagsString;
	std::vector < std::string> tags;
	int yearOfPublishing,id;
	double rating;
	std::cout << "Title:" << std::endl;
	std::getline(std::cin, title);
	std::cout << "Author:" << std::endl;
	std::getline(std::cin, author);
	std::cout << "Genre:" << std::endl;
	std::getline(std::cin, genre);
	std::cout << "yearOfPublishing:" << std::endl;
	std::cin >> yearOfPublishing;
	std::cout << "rating:" << std::endl;
	rating = helper::inputDouble();
	std::cout << "description:" << std::endl;
	std::getline(std::cin, description);
	std::cout << "Tags:" << std::endl;
	std::getline(std::cin, tagsString);
	tags = helper::splitString(tagsString);
	Book newEntry(author, title, genre, description, yearOfPublishing, tags, rating);
	system->addBook(newEntry);

}
