#include "Book.hpp"

Book::Book(string bookName) : _bookName{bookName} //Constructor
{
    std::cout << "Created book with name " << _bookName << std::endl;
};

Book::Book(const Book &oldObject) //Copy constructor
{
    this->_bookName = oldObject.getBookName();
    std::cout << "Copying " << oldObject.getBookName() << std::endl;
};

Book::Book(Book &&oldObject) //Move constructor
{
    this->_bookName = oldObject.getBookName();
    std::cout << "Moving " << oldObject.getBookName() << std::endl;
};

std::string Book::getBookName() const
{
    return _bookName;
};