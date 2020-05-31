#include "Books.h"
#include <iterator>

void Books::all()
{
	for (int i = 0; i < books.size(); i++) {
		std::cout << books[i].getTitle() << " " << books[i].getAuthor() << " " << books[i].getGenre() << " " << books[i].getId() << std::endl;
	}
}

void Books::info(int isbn_value)
{
	for (int i = 0; i < books.size(); i++) {
		if (books[i].getId() == isbn_value) {
			books[i].info();
			return;
		}
	}
}

void Books::find(std::string option, std::string optionString)
{
	std::vector<Book> results;
	if (option == "title") {
		results= findByTitle(optionString);
	}
	if (option == "author") {
		results = findByAuthor(optionString);
	}
	if (option == "tag")
	{
		results =  findByTag(optionString);
	}
	std::cout << "Books found:" << std::endl;
	for (int i = 0; i < results.size(); i++) {
		results[i].info();
	}

	return ;
}

std::vector<Book> Books::findByTitle(std::string title)
{
	std::vector<Book> results;
	for (int i = 0; i < books.size(); i++) {
		if (books[i].getTitle() == title)
			results.push_back(books[i]);
	}
	return results;
}



std::vector<Book> Books::findByAuthor(std::string title)
{
	std::vector<Book> results;
	for (int i = 0; i < books.size(); i++) {
		if (books[i].getAuthor() == title)
			results.push_back(books[i]);
	}
	return results;
}



std::vector<Book> Books::findByTag(std::string title)
{
	std::vector<Book> results;
	for (int i = 0; i < books.size(); i++) {
		if (books[i].getTitle() == title)
			results.push_back(books[i]);
	}
	return results;
}



bool Books::compareTitleAsc(const Book& a, const  Book& b)
{
	return a.getTitle() > b.getTitle();
}

bool Books::compareTitleDesc(const Book& a, const  Book& b)
{
	return a.getTitle() < b.getTitle();
}
bool Books::compareAuthorDesc(const Book& a, const  Book& b)
{
	return a.getAuthor() < b.getAuthor();
}
bool Books::compareAuthorAsc(const Book& a, const  Book& b)
{
	return a.getAuthor() < b.getAuthor();
}
bool Books::compareYearDesc(const Book& a, const Book& b)
{
	return a.getYearOfPublishing() < b.getYearOfPublishing();
}
bool Books::compareYearAsc(const Book& a, const Book& b)
{
	return a.getYearOfPublishing() > b.getYearOfPublishing();
}

bool Books::compareRatingAsc(const Book& a, const Book& b)
{
	return a.getRating() > b.getRating();
}

bool Books::compareRatingDesc(const Book& a, const Book& b)
{
	return a.getRating() < b.getRating();
}

bool Books::add(Book book)
{
	for (int i = 0; i < books.size(); i++) {
		if (books[i].getTitle() == book.getTitle()) {
			if (books[i].getAuthor() == book.getAuthor()) {
				return false;
			}
		}
	}
	books.push_back(book);
	std::cout << "Book added" << std::endl;
	return true;
}

bool Books::sort(std::string option, std::string asc)
{
	if (option == "title" && asc == "asc") {
		std::sort(books.begin(), books.end(), compareTitleAsc);
		return true;
	}
	if (option == "title" && asc == "desc") {
		std::sort(books.begin(), books.end(), compareTitleDesc);
		return true;
	}
	if (option == "author" && asc == "asc") {
		std::sort(books.begin(), books.end(), compareAuthorAsc);
		return true;
	}
	if (option == "author" && asc == "desc") {
		std::sort(books.begin(), books.end(), compareAuthorDesc);
		return true;
	}
	if (option == "year" && asc == "asc") {
		std::sort(books.begin(), books.end(), compareYearAsc);
		return true;
	}
	if (option == "year" && asc == "desc") {
		std::sort(books.begin(), books.end(), compareYearAsc);
		return true;
	}
	if (option == "rating" && asc == "asc") {
		std::sort(books.begin(), books.end(), compareRatingAsc);
		return true;
	}
	if (option == "rating" && asc == "desc") {
		std::sort(books.begin(), books.end(), compareRatingDesc);
		return true;
	}
	return false;
}

void Books::save(std::ofstream& database)
{
	for (int i = 0; i < books.size(); i++) {
		database<< books[i].getAuthor() << " " << books[i].getTitle() << " " << books[i].getGenre() <<
			" " << books[i].getYearOfPublishing() << " " << books[i].getRating() << std::endl <<
			books[i].getDescription() << std::endl;
		std::vector<std::string> tags= books[i].getTags();
		for (int i = 0; i < tags.size(); i++) {
			database<< tags[i]<< " ";
		}
		database << std::endl;

	}
}

void Books::read(std::ifstream& database)
{
	std::string line;

	while (std::getline(database, line))
	{

	}
}

void Books::clear()
{
	books.clear();
}

bool Books::remove(int id)
{
	for (int i = 0; i < books.size(); i++) {
		if (books[i].getId() == id) {
			std::cout << "Are you sure you want to delete this book" << std::endl;
			books[i].info();
			std::cout << "Y/N" << std::endl;
			std::string res;
			std::cin >> res;
			if (res.size() > 0 && res[0] == 'Y') {
				books.erase(books.begin() + i);
				std::cout << "Book removed" << std::endl;
			}
			else {
				std::cout << "Book not removed" << std::endl;
			}
		}
	}
	return false;
}
