#ifndef __BOOK_H
#define __BOOK_H

#include<string>
#include <vector>
class Book
{
private:
	std::string author;
	std::string title;
	std::string genre;
	std::string description;
	int yearOfPublishing;
	std::vector<std::string> tags;
	double rating;
	int id;
public:
	Book();
	Book(std::string, std::string, std::string,std::string, int, std::vector<std::string>, double);/*constructor for book using the data*/
	void info(); /* Prints title,author,genre, id*/
	//getters and setters
	std::string getTitle() const;
	std::string getAuthor() const;
	std::string getDescription() const;
	std::vector<std::string> getTags() const;
	int getYearOfPublishing() const;
	double getRating() const;
	std::string getGenre() const;
	int getId() const;
	void setId(int);
	bool hasTag(std::string) const;
};

#endif