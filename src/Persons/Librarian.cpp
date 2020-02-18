#include "Librarian.hpp"

Librarian::Librarian(std::string name, int age) : AbstractPerson(name, age)
{
    std::cout << "Creating LIBRARIAN with name " << name << " and old of " << age << " years" << std::endl;
}

std::string Librarian::getName()
{
    return _name;
}

int Librarian::getAge()
{
    return _age;
}