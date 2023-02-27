#include "person.h"

#include <utility>

Person::Person(std::string name){
    this->name = std::move(name);
}

// search for if the grade className exists
// push grade through if it doesn't, else do nothing
void Person::push_grade(std::string name) {
    bool gradeExists = false;

    for(auto & i : gradeList){
        if(i.getClassName() == name){
            gradeExists = true;
        }
    }

    if(!gradeExists){
        gradeList.push_back(*new Grade(name));
        std::cout << name<< " added to " << this->name << std::endl;
    } else {
        std::cout << "class already exists" << std::endl;
    }
}

// search for grade with same className, remove it if it exists
void Person::pop_grade(std::string name) {

    bool gradeRemoved = false;

    for(int i = 0; i < this->gradeList.size(); i++){
        if(this->gradeList.at(i).getClassName() == name){
            this->gradeList.erase(gradeList.begin() + i);
            gradeRemoved = true;
        }
    }

    if(gradeRemoved){
        std::cout << name << " removed from " << this->name << std::endl;
    } else {
        std::cout << "class does not exist" << std::endl;
    }

}

// GETTERS & SETTERS

std::string Person::getName(){
    return this->name;
}

std::vector<Grade>* Person::getClassList(){
    return &this->gradeList;
}
