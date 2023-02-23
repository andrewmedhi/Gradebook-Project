#include "grade.h"
#include <iostream>
#include <utility>

// constructor, className is only needed, everything else will be filled at runtime
Grade::Grade(std::string className) {
    this->className = std::move(className);

}

//push deliverable into the assignment list
void Grade::push_deliverable(std::string name, std::string type, int pt, int pe) {

    Deliverable tempDeliverable(std::move(name), type, pt, pe);

    bool successfulPlacement = false;

    for(auto & i : deliverableList){ // i is sub list inside of deliverableList
        if(i.at(0).getType() == type){ // if first position in list matches the list, add it
            i.push_back(tempDeliverable);
            std::cout << name << " added to " << type << std::endl;
            successfulPlacement = true; // successful placement, don't create new category
        }
    }

    if(!successfulPlacement){ // create new category
        this->deliverableList.push_back(*new std::vector<Deliverable>); // add new category to bottom
        this->deliverableList.at(deliverableList.size()-1).push_back(tempDeliverable); // bottom category has to be new one, push deliverable to it
        std::cout << "created category " << type << " and added " << name << "to it" << std::endl;
    }

}


void Grade::pop_deliverable(std::string name, std::string type) {

    bool successfulRemoval = false;

    for(auto & i : deliverableList){ // i is sub list inside of deliverableList
        if(i.at(0).getType() == type){ // search for the category
            for(int x = 0; x < i.size(); x++){
                if(i.at(x).getName() == name){
                    i.erase(i.begin() + x);
                    successfulRemoval = true;
                }
            }
        }
    }

    if(!successfulRemoval){
        std::cout << "deliverable does not exist" << std::endl;
    } else {
        std::cout << name << " removed from " << type << std::endl;
    }

}

void Grade::pop_category(std::string type) {

    bool successfulRemoval = false;

    for(int i = 0; i < deliverableList.size(); i++){ // i is sub list inside of deliverableList
        if(deliverableList.at(i).at(0).getType() == type){ // search for the category
            deliverableList.erase(deliverableList.begin() + i);
            successfulRemoval = true;
        }
    }

    if(!successfulRemoval){
        std::cout << "category does not exist" << std::endl;
    } else {
        std::cout << type << " category removed" << std::endl;
    }

}

// GETTERS & SETTERS

std::string Grade::getClassName() {
    return this->className;
}

// get a list of all the assignments under a certain type
// returns an empty list if not found
std::vector<Deliverable> Grade::getDeliverablesType(std::string type) {

    for(auto & i : deliverableList){
        if(i.at(0).getName() == type){
            return i;
        }
    }

    std::vector<Deliverable> empty;

    return empty;

}
