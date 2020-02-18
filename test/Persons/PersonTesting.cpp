#include "test/stdafx_test.h"
#include "MockedPerson.hpp"

//usages
using ::testing::AtLeast;
using ::testing::Return;

TEST(PersonTesting, testingName)
{
    MockedPerson fakePerson("Useless name", -55);
    EXPECT_CALL(fakePerson, getName())
        .Times(AtLeast(1))
        .WillOnce(Return("Fero"))
        .WillOnce(Return("Jozo"))
        .WillRepeatedly(Return("Andrej"));

    EXPECT_CALL(fakePerson, getAge())
        .Times(AtLeast(1))
        .WillRepeatedly(Return(1));

    std::cout << fakePerson.getName() << std::endl;
    std::cout << fakePerson.getName() << std::endl;
    std::cout << fakePerson.getName() << std::endl;
    std::cout << fakePerson.getName() << std::endl;
}