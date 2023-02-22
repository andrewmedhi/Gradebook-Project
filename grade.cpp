#include "grade.h"
#include <iostream>

Grade::Grade(std::string student_name, std::string student_class){
    this->StudentName=student_name;
    this->Student_Class=student_class;

    this->Student=new Person(this->StudentName);
    this->Current_Grade=100;
    this->Points_Earned=0;
    this->Points_Potential=0;
    //i thought it would be a good idea to set the area size to 4 rows
    //row 1: Labs
    //row 2: Assignments
    //row 3: Projects
    //row 4: Exams

    for(int i=0;i<4;i++){
        this->Assignment_List.push_back({});
    }
}

std::string Grade::getName() {
    return this->StudentName;
}

std::string Grade::getClass(){
    return this->Student_Class;
}

float Grade::getGrade(){
    return this->Current_Grade;
}

int Grade::getAss(char type, std::string assName) {
    int idx1=0;
    //find which row it's in
    switch(type){
        case 'L':
            idx1=0;
            break;
        case 'A':
            idx1=1;
            break;
        case 'P':
            idx1=2;
            break;
        case 'E':
            idx1=3;
            break;
    }
    //find where in the row it is in
    int idx2 = 0;
    while (idx2 < this->Assignment_List[idx1].size()) {
        if (this->Assignment_List[idx1][idx2].GetName()==assName) {
            break;
        }
        idx2 += 1;
    }
    //return the assignment at the row and idx2 name
    return this->Assignment_List[idx1][idx2].GetPE();
}

void Grade::addAss(Deliverable assignment){
    switch(assignment.GetType()){
        case 'L':
            this->Assignment_List[0].push_back(assignment);
            break;
        case 'A':
            this->Assignment_List[1].push_back(assignment);
            break;
        case 'P':
            this->Assignment_List[2].push_back(assignment);
            break;
        case 'E':
            this->Assignment_List[3].push_back(assignment);
            break;
    }

    this->Points_Earned+=assignment.GetPE();
    this->Points_Potential+=assignment.GetPW();
    this->Current_Grade=this->Points_Earned/this->Points_Potential*1.0;
}
