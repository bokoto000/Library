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
			if (splitInput.at(0) == "save" && splitInput.at(1) == "as") {
				system->open(trim(splitInput.at(2)));
			}
		if (splitInput.at(0) == "help") {

		}
		if (splitInput.at(0) == "exit") {

		}
		if (splitInput.at(0) == "login") {

		}
		if (splitInput.at(0) == "logout") {

		}
		if (splitInput.at(0) == "books") {
			booksCommandHandler(splitInput);

		}
		if (splitInput.at(0) == "users") {

		}
	}
	catch (const std::out_of_range& e) {
		std::cout << "Not enough arguments" << std::endl;
	}
}



void CommandLine::booksCommandHandler(std::vector<std::string> args)
{
	try {
		if (args.at(1) == "all") {

		}
		if (args.at(1) == "find") {

		}
		if (args.at(1) == "sort") {

		}
		if (args.at(1) == "add") {
			std::cout << "Test";
			addBook();
		}
		if (args.at(1) == "remove") {

		}

		if (args.at(1) == "info") {

		}
	}
	catch (const std::out_of_range& e) {
		std::cout << "Not enough arguments" << std::endl;
	}

}

void CommandLine::addBook()
{
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
	std::cout << "id:" << std::endl;
	id = helper::inputInt();
	std::cout << "rating:" << std::endl;
	rating = helper::inputDouble();
	std::cout << "description:" << std::endl;
	std::getline(std::cin, description);
	std::cout << "Tags:" << std::endl;
	std::getline(std::cin, tagsString);
	tags = helper::splitString(tagsString);
	Book newEntry(author, title, genre, description, yearOfPublishing, tags, rating, id);
	system->addBook(newEntry);

}
