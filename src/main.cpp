/*
    Playground project for C++
*/
#include "stdafx.h"
#include "Library/Bookshelf.hpp"
#include "Library/Book/Book.hpp"

void addOutOfScopeBooks(Bookshelf &bookshelf)
{
    Book eragon("Eragon");
    Book eldest("Eldest");

    bookshelf.addBook(eragon);
    bookshelf.addBook(eldest);
}

int main(int argc, char **argv)
{
    Bookshelf bookshelf;

    Book whiteFang("White Fang");
    Book lotr("Lord of the Rings");

    bookshelf.addBook(whiteFang);
    bookshelf.addBook(lotr);

    addOutOfScopeBooks(bookshelf);

    bookshelf.listAllBooks();

    char *memLeak = (char *)calloc(1, 100);
    strcpy(memLeak, "I am your intended memory leak");

    return 0;
}
