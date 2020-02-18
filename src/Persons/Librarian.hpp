#include "stdafx.h"
#include "AbstractPerson.hpp"
#pragma once

class Librarian : protected AbstractPerson
{
public:
    Librarian(std::string name, int age);
    virtual ~Librarian(){};
    std::string getName() override;
    int getAge() override;

private:
};