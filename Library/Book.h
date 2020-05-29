#ifndef __BOOK_H
#define __BOOK_H

#include<string>
#include <vector>
class Book
{
public:
	std::string author;
	std::string title;
	std::string genre;
	std::string description;
	int yearOfPublishing;
	std::vector<std::string> keyWords;
	double rating;
	std::string id;
public:
	Book();
	Book(std::string, std::string, std::string,std::string, int, std::vector<std::string> ,
		double, int id);


};

#endif