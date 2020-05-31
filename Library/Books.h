#ifndef __BOOKS_H
#define __BOOKS_H
#include <vector>
#include <iostream>
#include <algorithm>
#include "Book.h"
#include <fstream>
#include <sstream>
class Books
{
private:
	std::vector<Book> books;
public:
	void all();
	void info(int isbn_value);
	void find(std::string, std::string);
	std::vector<Book> findByTitle(std::string);
	std::vector<Book> findByAuthor(std::string);
	std::vector<Book> findByTag(std::string);
	bool sort(std::string, std::string);
	void save(std::ofstream&);
	void read(std::ifstream&);
	void clear();
	static bool compareTitleAsc(const Book &, const  Book &);
	static bool compareTitleDesc(const Book& a, const  Book& b);
	static bool compareAuthorDesc(const Book& a, const  Book& b);
	static bool compareAuthorAsc(const Book& a, const  Book& b);
	static bool compareYearDesc(const Book& a, const  Book& b);
	static bool compareYearAsc(const Book& a, const Book& b);
	static bool compareRatingAsc(const Book& a, const Book& b);
	static bool compareRatingDesc(const Book& a, const Book& b);
	bool add(Book book);
	bool remove(int id);
};

#endif