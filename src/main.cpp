/*
    Playground project for C++
*/
#include "stdafx.h"
#include "Library/Bookshelf.hpp"
#include "Library/Book/Book.hpp"
#include "Persons/Author.hpp"
#include "Persons/Librarian.hpp"

class ProblematicClass
{
public:
    std::vector<int> numbers;
};

void addOutOfScopeBooks(Bookshelf& bookshelf)
{
    Book eragon("Eragon");
    Book eldest("Eldest");

    bookshelf.addBook(eragon);
    bookshelf.addBook(eldest);
}

class Parent
{
public:
    Parent(std::string name)
        : _name(name)
    {
        std::cout << "Parent Name is " << _name << std::endl;
    };
    virtual void logSomething() = 0;

protected:
    std::string _name;
};

class ChildA : public Parent
{
public:
    ChildA(std::string name)
        : Parent(name)
    {
        std::cout << "ChildA Name is " << name << std::endl;
    };
    void logSomething()
    {
        std::cout << "I am ChildA and my name is " << _name << std::endl;
    };
};

class ChildB : public Parent
{
public:
    ChildB(std::string name)
        : Parent(name)
    {
        std::cout << "ChildB Name is " << name << std::endl;
    };
    void logSomething()
    {
        std::cout << "I am ChildB and my name is " << _name << std::endl;
    };
};

template <class T>
void napisCosi(T param1)
{
    std::cout << "param1 is " << param1 << std::endl;
}

template <>
void napisCosi(Parent* param1)
{
    std::cout << "Specialized template" << std::endl;
    param1->logSomething();
}

struct MyProblematicStruct
{
    char marauderArray[5]{0, 0, 0, 0, 0};
    //const int alwaysZeroValue = 0;
    //short vek = 0;
    int vekkkk = 0;
};

void performThreadOperation(MyProblematicStruct& myStruct)
{
    std::cout << myStruct.vekkkk << std::endl;
}

int main(int argc, char** argv)
{
    short flags = 0;
    flags |= 0b00000010;
    flags = flags | 0b01000000;

    MyProblematicStruct mystruct1;
    std::thread t1(performThreadOperation, std::ref(mystruct1));
    t1.join();

    /*char macka[5] = {'m', 'a', 'c', 'k', 'a'};
    char tempVar = 'a';
    int i = 0;
    while(tempVar != '\0')
    {
        tempVar = macka[i];
        std::cout << tempVar << std::endl;
        i++;
    }
    char* pointerToMacka = (char*)macka[5];
    std::cout << (const char*)*macka << std::endl;
*/

    std::vector<ProblematicClass> classes;

    ProblematicClass class1;
    class1.numbers.push_back(10);
    classes.push_back(class1);
    ProblematicClass* class1Ptr = (ProblematicClass*)&classes[0];
    std::vector<int>* class1NumberPtr = (std::vector<int>*)&classes[0].numbers;
    std::cout << "Size of class1 is " << sizeof(class1) << " and " << sizeof(class1.numbers) << std::endl;

    ProblematicClass class2;
    class2.numbers.push_back(10);
    class2.numbers.push_back(10);
    class2.numbers.push_back(10);
    class2.numbers.push_back(10);
    classes.push_back(class2);
    class1Ptr = (ProblematicClass*)&classes[0];
    class1NumberPtr = (std::vector<int>*)&classes[0].numbers;
    ProblematicClass* class2Ptr = (ProblematicClass*)&classes[1];
    std::vector<int>* class2NumberPtr = (std::vector<int>*)&classes[1].numbers;
    std::cout << "Size of class2 is " << sizeof(class2) << " and " << sizeof(class2.numbers) << std::endl;

    ProblematicClass class3;
    for(int i = 0; i < 100; i++)
    {
        class3.numbers.push_back(i);
    }
    classes.push_back(class3);
    class1Ptr = (ProblematicClass*)&classes[0];
    class1NumberPtr = (std::vector<int>*)&classes[0].numbers;
    class2Ptr = (ProblematicClass*)&classes[1];
    class2NumberPtr = (std::vector<int>*)&classes[1].numbers;
    ProblematicClass* class3Ptr = (ProblematicClass*)&classes[2];
    std::vector<int>* class3NumberPtr = (std::vector<int>*)&classes[2].numbers;
    std::cout << "Size of class3 is " << sizeof(class3) << " and " << sizeof(class3.numbers) << std::endl;

    MyProblematicStruct myStruct;
    //myStruct.alwaysZeroValue = 4;
    //myStruct.marauderArray[5] = 5;
    //std::cout << "My always zero value is " << myStruct.alwaysZeroValue << std::endl;
    std::cout << sizeof(myStruct) << std::endl;

    Bookshelf bookshelf;

    Book whiteFang("White Fang");
    Book lotr("Lord of the Rings");

    bookshelf.addBook(whiteFang);
    bookshelf.addBook(lotr);

    addOutOfScopeBooks(bookshelf);

    bookshelf.listAllBooks();

    char* memLeak = (char*)calloc(1, 100);
    strcpy(memLeak, "I am your intended memory leak");

    Author Robert("Robert Merle", 42);
    std::cout << "Hello " << Robert.getName() << std::endl;
    Librarian Ivan("Ivan the Nasty", 69);
    std::cout << "Hello " << Ivan.getName() << std::endl;

    std::cout << "-------------------" << std::endl;
    ChildA childA("Ferko");
    ChildB childB("Jozko");

    napisCosi(5);
    napisCosi(5.5f);
    napisCosi(true);
    napisCosi('a');
    napisCosi("Test string");
    napisCosi(&static_cast<Parent&>(childA));
    napisCosi(&dynamic_cast<Parent&>(childB));

    return 0;
}
