#include "test/stdafx_test.h"
#include "src/Library/Bookshelf.hpp"
#include "src/Library/Book/Book.hpp"

TEST(BookshelfTest, simpleTest)
{
    Book book("My manifique book");
    EXPECT_STRNE(book.getBookName().c_str(), "Any book");
}