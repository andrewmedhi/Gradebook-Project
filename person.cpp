#include "person.h"

Person::Person(std::string name){
    this->name = name;
}

std::string Person::getName(){
    return this->name;
}
