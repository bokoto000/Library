#include "Book.h"

Book::Book()
{
}

Book::Book(std::string _author, std::string _title, std::string _genre, std::string _description, int _yearOfPublishing, std::vector<std::string> _keyWords,
	double _rating, int _id)
{
	author = _author;
	title = _title;
	genre = _genre;
	description = _description;
	yearOfPublishing = _yearOfPublishing;
	keyWords = _keyWords;
	rating = _rating;
	id = _id;
}
