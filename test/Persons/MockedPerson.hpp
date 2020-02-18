#include "../stdafx_test.h"
#include "../../src/Persons/AbstractPerson.hpp"

class MockedPerson : public AbstractPerson
{
public:
    MockedPerson(std::string uselessName, int uselessAge) : AbstractPerson(uselessName, uselessAge){};
    MOCK_METHOD0(getName, std::string());
    MOCK_METHOD0(getAge, int());
};