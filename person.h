#include <string>
#include <iostream>

class Person{
private:
    std::string name;

public:
    // Constructors
    Person();
    Person(std::string name);

    // Get name
    std::string getName();
};