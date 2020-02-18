#include "stdafx.h"
#include "AbstractPerson.hpp"
#pragma once

class Author : protected AbstractPerson
{
public:
    Author(std::string name, int age);
    virtual ~Author(){};
    std::string getName() override;
    int getAge() override;

private:
};