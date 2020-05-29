#include <iostream>
#include "Book.h"
#include "User.h"
#include "System.h"

int main()
{
    Book book("Test", "test", "test", "test", 1999, {"Shit","Lol"}, 9, 1);
    User user("boko", "1234", 1);
    System system("test");
}