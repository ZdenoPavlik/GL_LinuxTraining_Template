#include "Bookshelf.hpp"
#

void Bookshelf::addBook(Book book)
{
    std::cout << "Adding book " << book.getBookName() << std::endl;
    _books.push_back(book);
}

void Bookshelf::listAllBooks()
{
    std::cout << "List of books :" << std::endl;
    for (Book book : _books)
    {
        std::cout << " - " << book.getBookName() << std::endl;
    }
}