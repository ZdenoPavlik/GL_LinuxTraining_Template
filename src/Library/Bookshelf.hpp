#pragma once
#include "stdafx.h"

#include "Book/Book.hpp"
#include "Book/Book.hpp"

class Bookshelf
{
public:
    void addBook(Book book);
    void listAllBooks();

private:
    std::list<Book> _books;
};