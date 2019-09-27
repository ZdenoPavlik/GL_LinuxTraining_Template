#pragma once
#include "stdafx.h"

class Book
{
public:
    Book(string bookName);
    Book(const Book &oldObject); //Copy constructor
    Book(Book &&oldObject);      //Move constructor
    std::string getBookName() const;

private:
    std::string _bookName;
};