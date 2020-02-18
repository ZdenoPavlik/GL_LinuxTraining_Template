#include "stdafx.h"
#pragma once

class AbstractPerson
{
public:
    AbstractPerson(std::string &name, int age) : _name(name), _age(age)
    {
    }

    virtual ~AbstractPerson(){};

    virtual std::string getName() = 0;
    virtual int getAge() = 0;

protected:
    std::string _name;
    int _age = -1;
};