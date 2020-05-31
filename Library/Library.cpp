#include <iostream>
#include "Book.h"
#include "Books.h"
#include "User.h"
#include "Users.h"
#include "System.h"
#include "CommandLine.h"
int main()
{
    Book book("Test", "test", "test", "test", 1999, { "Shit","Lol" }, 9, 1);
    Book book1("Test1", "test1", "test", "test", 1999, { "Shit","Lol" }, 9, 1);
    System system;
    CommandLine cmd(&system);
    Books books;
    books.add(book);
    books.add(book1);
    books.all();
    books.sort("title", "asc");
    books.all();
    books.sort("title", "desc");
    books.all();
    User user("boko", "1234", 1);
    Users users;
    users.add("boko","1234",1);
    system.start();
    cmd.start();

}