#include "deliverable.h"
#include <iostream>

Deliverable::Deliverable(std::string name, int points_Worth, int points_Earned, char AssType){
    this->name = name;
    this->points_Worth = points_Worth;
    this->points_Earned = points_Earned;
    this->AssType = AssType;


}

std::string Deliverable::GetName(){
    return this->name;
}
int Deliverable::GetPW(){
    return this->points_Worth;
}
int Deliverable::GetPE(){
    return this->points_Earned;
}
char Deliverable::GetAss(){
    return this->assType;
}