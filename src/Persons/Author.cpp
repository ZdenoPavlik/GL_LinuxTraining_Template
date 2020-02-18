#include "Author.hpp"

Author::Author(std::string name, int age) : AbstractPerson(name, age)
{
    std::cout << "Creating AUTHOR with name " << name << " and old of " << age << " years" << std::endl;
}

std::string Author::getName()
{
    return _name;
}

int Author::getAge()
{
    return _age;
}