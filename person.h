#include <string>
#include <iostream>
#include <vector>

#include "grade.h"

class Person{
private:
    std::string name;
    std::vector<Grade> gradeList;


public:
    // Constructors
    Person(std::string name);

    void push_grade(std::string name);
    void pop_grade(std::string name);


    // getters & setters
    std::string getName();
};