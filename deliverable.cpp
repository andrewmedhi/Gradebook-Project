#include "deliverable.h"
#include <iostream>
#include <utility>

Deliverable::Deliverable(std::string name, std::string type, int pw, int pe) {
    this->name = std::move(name);
    this->pointTotal = pw;
    this->pointEarned = pe;
    this->type = std::move(type);


}

// GETTERS & SETTERS

std::string Deliverable::getName(){
    return this->name;
}

int Deliverable::getPointsTotal() {
    return this->pointTotal;
}

int Deliverable::getPointsEarned() {
    return this->pointEarned;
}

std::string Deliverable::getType(){
    return this->type;
}