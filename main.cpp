#include <iostream>
#include <sstream>
#include <iomanip>
#include "gradebook.h"

// MAIN MENU

void viewAllGrades(Gradebook *gradebook){

    std::cout << "--- GRADEBOOK CONTENTS ---" << std::endl;
    for(int i = 0; i < gradebook->getStudentSize(); i++){
        Person student = gradebook->getStudentList()->at(i);

        std::cout << student.getName() << std::endl;

        for(auto grade : *student.getClassList()){

            double totalGradePoints = 0;
            double earnedGradePoints = 0;
            for(const auto& deliList : *grade.getDeliverableList()) {
                for (auto tempDev: deliList) {
                    totalGradePoints += tempDev.getPointsTotal();
                    earnedGradePoints += tempDev.getPointsEarned();
                }
            }

            std::cout << std::fixed << std::setprecision(2) << "\t" << grade.getClassName() << " --- " << earnedGradePoints/totalGradePoints*100 << "%" <<std::endl;
            for(auto deliList : *grade.getDeliverableList()){
                std::cout << std::endl;
                double totalPoints = 0;
                double earnedPoints = 0;

                for(auto tempDev : deliList){
                    totalPoints += tempDev.getPointsTotal();
                    earnedPoints += tempDev.getPointsEarned();
                }

                std::cout << std::fixed << std::setprecision(2) << "\t\t" << deliList.at(0).getType() << " --- " << earnedPoints/totalPoints*100 << "%" << std::endl;

                for(auto tempDev : deliList){
                    std::cout << std::fixed << std::setprecision(2) << "\t\t" << tempDev.getName() << " " << tempDev.getPointsEarned() << "/" << tempDev.getPointsTotal() << " - " << (double(tempDev.getPointsEarned())/double(tempDev.getPointsTotal()))*100 << "%" << std::endl;
                }

            }
        }
    }

    std::cout << std::endl;
    std::string useless;
    std::cout << "Input anything to exit" << std::endl;
    std::cin >> useless;



}

void viewIndividual(Gradebook *gradebook){

    std::cout << "--- CHOSE STUDENT ---" << std::endl;
    for(int i = 0; i < gradebook->getStudentSize(); i++){
        std::cout << i << " - " << gradebook->getStudentList()->at(i).getName() << std::endl;
    }

    std::cout << "Option (-1 to cancel): ";
    std::string input;
    std::cin >> input;

    int option = std::stoi(input);


    if(option == -1){
        std::cout << "Process aborted." << std::endl;
    } else if (option >= 0 && option < gradebook->getStudentSize()){

        std::cout << "--- INDIVIDUAL CONTENTS ---" << std::endl;

        Person student = gradebook->getStudentList()->at(option);

        std::cout << student.getName() << std::endl;

        for(auto grade : *student.getClassList()){

            double totalGradePoints = 0;
            double earnedGradePoints = 0;
            for(auto deliList : *grade.getDeliverableList()) {
                for (auto tempDev: deliList) {
                    totalGradePoints += tempDev.getPointsTotal();
                    earnedGradePoints += tempDev.getPointsEarned();
                }
            }

            std::cout << std::fixed << std::setprecision(2) << "\t" << grade.getClassName() << " --- " << earnedGradePoints/totalGradePoints*100 << "%" <<std::endl;
            for(auto deliList : *grade.getDeliverableList()){
                std::cout << std::endl;
                double totalPoints = 0;
                double earnedPoints = 0;

                for(auto tempDev : deliList){
                    totalPoints += tempDev.getPointsTotal();
                    earnedPoints += tempDev.getPointsEarned();
                }

                std::cout << std::fixed << std::setprecision(2) << "\t\t" << deliList.at(0).getType() << " --- " << earnedPoints/totalPoints*100 << "%" << std::endl;

                for(auto tempDev : deliList){
                    std::cout << std::fixed << std::setprecision(2) << "\t\t" << tempDev.getName() << " " << tempDev.getPointsEarned() << "/" << tempDev.getPointsTotal() << " - " << (double(tempDev.getPointsEarned())/double(tempDev.getPointsTotal()))*100 << "%" << std::endl;
                }

            }
        }

        std::cout << std::endl;
        std::string useless;
        std::cout << "Input anything to exit" << std::endl;
        std::cin >> useless;


    } else {
        std::cout << "Please chose valid input" << std::endl;
    }

}

void viewMenu(Gradebook *gradebook){

    std::cout << std::endl;
    std::string option;

    while(option != "-1"){
        std::cout << std::endl;
        std::cout << "--- VIEW MENU ---" << std::endl;
        std::cout << "1 - All Grades" << std::endl;
        std::cout << "2 - Individual Student Grade" << std::endl;

        std::cout << "Option (-1 to quit): ";
        std::cin >> option;

        if(option == "1"){
            std::cout << std::endl;
            viewAllGrades(gradebook);

        } else if (option == "2"){
            std::cout << std::endl;
            viewIndividual(gradebook);

        } else {
            std::cout << std::endl;
            std::cout << "Please input a valid option" << std::endl;
            std::cout << std::endl;
        }
    }

}

void addStudent(Gradebook *gradebook) {

    std::string name;
    std::cout << "Input student name (First Last): ";
    std::cout.flush();
    std::cin.ignore();
    std::getline(std::cin, name);
    gradebook->push_student(name);

}

void removeStudent(Gradebook *gradebook) {
    std::cout << "--- REMOVE STUDENT ---" << std::endl;
    for(int i = 0; i < gradebook->getStudentSize(); i++){
        std::cout << i << " - " << gradebook->getStudentList()->at(i).getName() << std::endl;
    }

    std::cout << "Option (-1 to cancel): ";
    std::string input;
    std::cin >> input;

    int option = std::stoi(input);


    if(option == -1){
        std::cout << "Process aborted." << std::endl;
    } else if (option >= 0 && option < gradebook->getStudentSize()){
        std::string studentName = gradebook->getStudentList()->at(option).getName();
        gradebook->pop_student(studentName);
        std::cout << studentName << " removed from gradebook" << std::endl;
    } else {
        std::cout << "Please chose valid input" << std::endl;
    }

}

void addClass(Gradebook *gradebook){
    std::cout << "--- CHOOSE STUDENT ---" << std::endl;
    for(int i = 0; i < gradebook->getStudentSize(); i++){
        std::cout << i << " - " << gradebook->getStudentList()->at(i).getName() << std::endl;
    }

    std::cout << "Option (-1 to cancel): ";
    std::string input;
    std::cin >> input;

    int option = std::stoi(input);


    if(option == -1){
        std::cout << "Process aborted." << std::endl;
    } else if (option >= 0 && option < gradebook->getStudentSize()){
        Person student = gradebook->getStudentList()->at(option);

        std::string className;

        std::cout << "Input class name (Ex. CSC212): ";
        std::cin >> className;

        gradebook->getStudentList()->at(option).push_grade(className);

        std::cout << student.getName() << " added to " << className << std::endl;
    } else {
        std::cout << "Please chose valid input" << std::endl;
    }

}

void removeClass(Gradebook *gradebook){
    std::cout << "--- CHOOSE STUDENT ---" << std::endl;
    for(int i = 0; i < gradebook->getStudentSize(); i++){
        std::cout << i << " - " << gradebook->getStudentList()->at(i).getName() << std::endl;
    }

    std::cout << "Option (-1 to cancel): ";
    std::string input;
    std::cin >> input;

    int option = std::stoi(input);


    if(option == -1){
        std::cout << "Process aborted." << std::endl;
    } else if (option >= 0 && option < gradebook->getStudentSize()){

        Person *tempStudent = &gradebook->getStudentList()->at(option);
        std::vector<Grade> *tempClass = tempStudent->getClassList();

        if(tempClass->empty()){
            std::cout << tempStudent->getName() << " is not in any classes" << std::endl;
        } else {

            std::cout << std::endl;
            std::cout << "--- CHOOSE CLASS ---" << std::endl;

            for (int i = 0; i < tempClass->size(); i++) {
                std::cout << i << " - " << tempClass->at(i).getClassName() << std::endl;
            }

            std::cout << "Option (-1 to cancel): ";
            std::cin >> input;
            option = std::stoi(input);

            if(option == -1){
                std::cout << "Process aborted." << std::endl;
            } else if (option >= 0 && option < tempClass->size()){
                std::string className = tempStudent->getClassList()->at(option).getClassName();

                tempStudent->pop_grade(className);

                std::cout << tempStudent->getName() << " removed from " << className << std::endl;
            } else {
                std::cout << "Please chose valid input" << std::endl;
            }

        }

    } else {
        std::cout << "Please chose valid input" << std::endl;
    }

}

void addDeliverable(Gradebook *gradebook){

    std::cout << "--- CHOOSE STUDENT ---" << std::endl;
    for(int i = 0; i < gradebook->getStudentSize(); i++){
        std::cout << i << " - " << gradebook->getStudentList()->at(i).getName() << std::endl;
    }

    std::cout << "Option (-1 to cancel): ";
    std::string input;
    std::cin >> input;

    int option = std::stoi(input);


    if(option == -1){
        std::cout << "Process aborted." << std::endl;
    } else if (option >= 0 && option < gradebook->getStudentSize()){

        Person *tempStudent = &gradebook->getStudentList()->at(option);
        std::vector<Grade> *tempClass = tempStudent->getClassList();

        if(tempClass->empty()){
            std::cout << tempStudent->getName() << " is not in any classes" << std::endl;
        } else {

            std::cout << std::endl;
            std::cout << "--- CHOOSE CLASS ---" << std::endl;

            for (int i = 0; i < tempClass->size(); i++) {
                std::cout << i << " - " << tempClass->at(i).getClassName() << std::endl;
            }

            std::cout << "Option (-1 to cancel): ";
            std::cin >> input;
            option = std::stoi(input);

            if(option == -1){
                std::cout << "Process aborted." << std::endl;
            } else if (option >= 0 && option < tempClass->size()){

                std::cout << "Input Deliverable (Name, Points Earned (-1 for blank), Total Points, Type) :";
                std::cout.flush();
                std::cin.ignore();
                std::getline(std::cin, input);

                std::vector<std::string> inputs;

                std::string tempStr;
                std::stringstream ss(input);

                while (std::getline(ss, tempStr, ',')) {
                    inputs.push_back(tempStr);
                }

                if(inputs.size() != 4){
                    std::cout << "Please chose valid input" << std::endl;
                } else {
                    tempClass->at(option).push_deliverable(inputs.at(0), inputs.at(3), std::stoi(inputs.at(2)), std::stoi(inputs.at(1)));

                }

            } else {
                std::cout << "Please chose valid input" << std::endl;
            }

        }

    } else {
        std::cout << "Please chose valid input" << std::endl;
    }

}

void removeDeliverable(Gradebook* gradebook){
    std::cout << "--- CHOOSE STUDENT ---" << std::endl;
    for(int i = 0; i < gradebook->getStudentSize(); i++){
        std::cout << i << " - " << gradebook->getStudentList()->at(i).getName() << std::endl;
    }

    std::cout << "Option (-1 to cancel): ";
    std::string input;
    std::cin >> input;

    int option = std::stoi(input);


    if(option == -1){
        std::cout << "Process aborted." << std::endl;
    } else if (option >= 0 && option < gradebook->getStudentSize()){

        Person *tempStudent = &gradebook->getStudentList()->at(option);
        std::vector<Grade> *tempClass = tempStudent->getClassList();

        if(tempClass->empty()){
            std::cout << tempStudent->getName() << " is not in any classes" << std::endl;
        } else {

            std::cout << std::endl;
            std::cout << "--- CHOOSE CLASS ---" << std::endl;

            for (int i = 0; i < tempClass->size(); i++) {
                std::cout << i << " - " << tempClass->at(i).getClassName() << std::endl;
            }

            std::cout << "Option (-1 to cancel): ";
            std::cin >> input;
            option = std::stoi(input);

            if(option == -1){
                std::cout << "Process aborted." << std::endl;
            } else if (option >= 0 && option < tempClass->size()){

                Grade *tempGrade = &tempClass->at(option);
                std::vector<std::vector<Deliverable>> *tempDeliverables = tempClass->at(option).getDeliverableList();
                if(!tempDeliverables->empty()) {
                    std::cout << std::endl;
                    std::cout << "--- CHOOSE DELIVERABLE ---" << std::endl;

                    int amountOfDeliverables = 0;

                    for (auto &tempDeliverable: *tempDeliverables) {
                        for (auto &j: tempDeliverable) {
                            std::cout << amountOfDeliverables << " - " << j.getName() << std::endl;
                            amountOfDeliverables++;
                        }
                    }

                    std::cout << "Option (-1 to cancel): ";
                    std::cin >> input;
                    option = std::stoi(input);

                    if (option == -1) {
                        std::cout << "Process aborted." << std::endl;
                    } else if (option >= 0 && option < amountOfDeliverables) {

                        int temp = 0;
                        while (option >= tempDeliverables->at(temp).size()) {
                            option -= tempDeliverables->at(temp).size();
                            temp += 1;
                        }

                        if (tempDeliverables->at(temp).size() - 1 == 0) {
                            std::cout << tempDeliverables->at(temp).at(option).getName() << " removed from " << tempDeliverables->at(temp).at(option).getType() << std::endl;
                            tempGrade->pop_category(tempDeliverables->at(temp).at(option).getType());
                        } else {
                            tempGrade->pop_deliverable(tempDeliverables->at(temp).at(option).getName(),tempDeliverables->at(temp).at(option).getType());
                        }

                    } else {
                        std::cout << "Please chose valid input" << std::endl;
                    }
                } else {
                    std::cout << tempStudent->getName() << " doesn't have any deliverables" << std::endl;
                }

            } else {
                std::cout << "Please chose valid input" << std::endl;
            }

        }

    } else {
        std::cout << "Please chose valid input" << std::endl;
    }




}


void editMenu(Gradebook *gradebook){

    std::cout << std::endl;
    std::string option;

    while(option != "-1"){
        std::cout << std::endl;
        std::cout << "--- EDIT MENU ---" << std::endl;
        std::cout << "1 - Add Student" << std::endl;
        std::cout << "2 - Remove Student" << std::endl;
        std::cout << "3 - Add Class" << std::endl;
        std::cout << "4 - Remove Class" << std::endl;
        std::cout << "5 - Add Deliverable" << std::endl;
        std::cout << "6 - Remove Deliverable" << std::endl;

        std::cout << "Option (-1 to quit): ";
        std::cin >> option;

        if(option == "1"){
            std::cout << std::endl;
            addStudent(gradebook);

        } else if (option == "2"){
            std::cout << std::endl;
            if(gradebook->getStudentSize() == 0){
                std::cout << "No students are in the gradebook" << std::endl;
            } else {
                removeStudent(gradebook);
            }

        } else if (option == "3"){
            std::cout << std::endl;
            if(gradebook->getStudentSize() == 0){
                std::cout << "No students are in gradebook" << std::endl;
            } else {
                addClass(gradebook);
            }

        } else if (option == "4"){
            std::cout << std::endl;
            if(gradebook->getStudentSize() == 0){
                std::cout << "No students are in gradebook" << std::endl;
            } else {
                removeClass(gradebook);
            }

        } else if (option == "5"){
            std::cout << std::endl;
            if(gradebook->getStudentSize() == 0){
                std::cout << "No students are in gradebook" << std::endl;
            } else {
                addDeliverable(gradebook);
            }

        } else if (option == "6"){
            std::cout << std::endl;
            if(gradebook->getStudentSize() == 0){
                std::cout << "No students are in gradebook" << std::endl;
            } else {
                removeDeliverable(gradebook);
            }


        } else {
            std::cout << std::endl;
            std::cout << "Please input a valid option" << std::endl;
            std::cout << std::endl;
        }
    }

    gradebook->saveFile();

}


void mainMenu(Gradebook *gradebook){

    std::cout << std::endl;
    std::string option;

    while(option != "-1"){
        std::cout << std::endl;
        std::cout << "--- GRADEBOOK ---" << std::endl;
        std::cout << "1 - View Grades" << std::endl;
        std::cout << "2 - Edit Grades" << std::endl;

        std::cout << "Option (-1 to quit): ";
        std::cin >> option;

        if(option == "1"){
            std::cout << std::endl;
            viewMenu(gradebook);

        } else if (option == "2"){
            std::cout << std::endl;
            editMenu(gradebook);

        } else {
            std::cout << std::endl;
            std::cout << "Please input a valid option" << std::endl;
            std::cout << std::endl;
        }
    }

}

int main() {

    auto *gradebook = new Gradebook;

    mainMenu(gradebook);

    std::cout << "Goodbye" << std::endl;
}
 