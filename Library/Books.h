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
	void info(int isbn_value); /* Finds a book by id and prints info about it*/
	void find(std::string, std::string); /*Finds book by title/tag/author */
	std::vector<Book> findByTitle(std::string);
	std::vector<Book> findByAuthor(std::string);
	std::vector<Book> findByTag(std::string);
	bool sort(std::string, std::string); /*sort function*/
	void save(std::ofstream&); /*saves data to file*/
	void read(std::ifstream&); /*loads data from file*/
	void clear();/*clears the vector*/
	static bool compareTitleAsc(const Book &, const  Book &); /*comparator for sort function*/
	static bool compareTitleDesc(const Book& a, const  Book& b); /*comparator for sort function*/
	static bool compareAuthorDesc(const Book& a, const  Book& b); /*comparator for sort function*/
	static bool compareAuthorAsc(const Book& a, const  Book& b); /*comparator for sort function*/
	static bool compareYearDesc(const Book& a, const  Book& b); /*comparator for sort function*/
	static bool compareYearAsc(const Book& a, const Book& b); /*comparator for sort function*/
	static bool compareRatingAsc(const Book& a, const Book& b); /*comparator for sort function*/
	static bool compareRatingDesc(const Book& a, const Book& b); /*comparator for sort function*/
	bool add(Book book);
	bool remove(int id);
};

#endif