#include "Book.h"
#include <iostream>

Book::Book()
{
}

Book::Book(std::string _author, std::string _title, std::string _genre, std::string _description, int _yearOfPublishing, std::vector<std::string> _tags,
	double _rating, int _id)
{
	author = _author;
	title = _title;
	genre = _genre;
	description = _description;
	yearOfPublishing = _yearOfPublishing;
	tags = _tags;
	rating = _rating;
	id = _id;
}

void Book::info()
{
	std::cout << "title: " << title << std::endl;
	std::cout << "author: " << author << std::endl;
	std::cout << "genre: " << genre << std::endl;
	std::cout << "description: " << description << std::endl;
	std::cout << "year of publishing: " << yearOfPublishing << std::endl;
	std::cout << "key words: ";
	for (int i = 0; i < tags.size(); i++) {
		std::cout << tags[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "rating: " << rating << std::endl;
	std::cout << "id: " << id << std::endl;
}

std::string Book::getTitle() const
{
	return title;
}

std::string Book::getAuthor() const
{
	return author;
}

std::string Book::getDescription() const
{
	return description;
}

std::vector<std::string> Book::getTags() const
{
	return tags;
}

int Book::getYearOfPublishing() const
{
	return yearOfPublishing;
}

double Book::getRating() const
{
	return rating;
}

std::string Book::getGenre() const
{
	return genre;
}

int Book::getId() const
{
	return id;
}

bool Book::hasTag(std::string tag) const
{
	for (int i = 0; i < tags.size(); i++) {
		if (tags[i] == tag)return true;
	}
	return false;
}


