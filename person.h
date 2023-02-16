#include <string>
#include <iostream>

class Person{
private:
    std::string name;

public:
    // Constructors
    Person(std::string name);

    // Get name
    std::string getName();
};