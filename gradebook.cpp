#include "gradebook.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <utility>

// will ask the user whether they want to load an existing Gradebook or generate a new one
//      reading will search for a file of the same name and will organize the data into the proper objects
//      generating a new one will create an empty "Gradebook.txt"

Gradebook::Gradebook() {
    bool correctAnswer = false;
    bool importFile = false;
    while(!correctAnswer) {
        // Take user input
        std::string answer;
        std::cout << "Would you like to import a file for gradebook? (Y or N) ";
        std::cin >> answer;

        // Uppercase the string
        for(int i = 0; i < answer.length(); i++){
            answer[i] = toupper(answer[i]);
        }

        // Check for valid input
        if (answer == "Y" || answer == "YES") { // YES, will ask the user for a file name, then import the file
            correctAnswer = true;
            importFile = true;
        } else if (answer == "N" || answer == "NO") { // NO, will ask the user for a file name, then create an empty
            correctAnswer = true;
            importFile = false;
        }
    }

    // Ask for file name
    std::string fileName;
    std::cout << "Enter file: ";
    std::cin >> fileName;

    // File creation
    if(importFile) { // LOAD DATA FROM FILE
        std::fstream readfile(fileName);
        std::string line;
        std::string currentstudent;
        while (getline(readfile, line)) {
            std::string s;
            std::istringstream ss(line);
            while (getline(ss, s)) {
                if (s.find('$') != std::string::npos) {
                    s.erase(remove(s.begin(), s.end(), '$'), s.end());
                    currentstudent = s;
                    this->push_student(s);
                }else {
                    //splits string by space, then adds each item in string into list
                    std::vector<std::string> deliver_list;
                    while (getline(ss, s, ' ')) {
                        deliver_list.push_back(s);
                    }
                    std::string delivName = deliver_list[0];
                    std::string delivPE = deliver_list[1];
                    std::string delivPP = deliver_list[2];
                    std::string delivType = deliver_list[3];

                }
            }
        }
        readfile.close();
    }else {

    }
}

// push student adds a new person to the list of students
void Gradebook::push_student(std::string studentName) {

    bool studentFound = false;
    for(int i = 0; i < students.size(); i++){
        if(students.at(i).getName() == studentName){
            studentFound = true;
            break;
        }
    }
    if(studentFound){
        students.push_back(*new Person(std::move(studentName)));
        std::cout << "Created student " << studentName << std::endl;
    } else {
        std::cout << "Student already exists" << std::endl;
    }

}

// pop student will search for an existing student and remove them
void Gradebook::pop_student(std::string studentName) {

    bool studentFound = false;
    for(int i = 0; i < students.size(); i++){
        if(students.at(i).getName() == studentName){
            students.erase(students.begin() + i);
            studentFound = true;
            break;
        }
    }

    if(studentFound){
        std::cout << "Deleted student " << studentName << std::endl;
    } else {
        std::cout << "Student does not exist" << std::endl;
    }
}

// overwrites the existing save file with the new information
void Gradebook::saveFile() {

}

// reads from the save file, reloading the current gradebook to the new config file
void Gradebook::readFile() {

}

// GETTERS & SETTERS

Person Gradebook::getStudent(std::string Name) { // TODO: THIS

}



std::vector<Person> Gradebook::getStudentList() {
    return this->students;
}

int Gradebook::getStudentSize() {
    return this->students.size();
}
