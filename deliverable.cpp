#include "deliverable.h"
#include <iostream>

deliverable::deliverable(std::string name, int points_Worth, int points_Earned, char AssType){
    this->name = name;
    this->points_Worth = points_Worth;
    this->points_Earned = points_Earned;
    this->AssType = AssType;


}

std::string deliverable::GetName(){
    return this.name;
}
int deliverable::GetPW(){
    return this.points_Worth;
}
int deliverable::GetPE(){
    return this.points_Earned;
}
char deliverable::GetAss(){
    return this.assType;
}