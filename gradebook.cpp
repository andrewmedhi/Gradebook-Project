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
        std::cout << "Would you like to import a file for gradebook? (Y or N) :";
        std::cin >> answer;

        // Uppercase the string
        for(char & i : answer){
            i = toupper(i);
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

    // File creation
    if (importFile) { // LOAD DATA FROM FILE
        //DEBUG
        //Person* currentStudent;
        //DEBUG
        // Ask for file name
        std::string fileName;
        std::cout << "Enter file: ";
        std::cin >> fileName;

        std::fstream file(fileName);
        std::string line;
        std::string currentstudent;
        // Ensure a valid file name
        while (not (file.is_open())){
            std::cout << "Could not open file. Please try again. "<< std::endl;
            std::cout << "Enter file: ";
            std::cin >> fileName;
            file.open(fileName);

        }

        this->fileName = fileName;

        // Hide the stream buffer to prevent the console getting flooded

        std::streambuf* hide_buffer = std::cout.rdbuf();
        std::cout.rdbuf(nullptr);


        while(getline(file, line)){

            if(line[0] == '$'){
                line = line.substr(1);
                this->push_student(line);

            } else if(line[0] == '?'){
                line = line.substr(1);
                this->students.at(students.size()-1).push_grade(line);

            } else {

                std::vector<std::string> tempInfo;

                std::string tempStr;
                std::stringstream ss(line);

                while (std::getline(ss, tempStr, ',')) {
                    tempInfo.push_back(tempStr);
                }

                this->students.at(students.size()-1).getClassList()->at(students.at(students.size()-1).getClassList()->size()-1).push_deliverable(tempInfo.at(0), tempInfo.at(3), std::stoi(tempInfo.at(2)), std::stoi(tempInfo.at(1)));

            }


        }

        // Re enable the stream so the program actually prints things
        std::cout.rdbuf(hide_buffer);


        /*
        * The output of the file
        * $Andrew Medeiros
        * ?CSC212
        * Lab 4,15,20,L
        * Assignment 2,30,50,A
        * $Bill Mates
        * ?CSC 212
        * Lab 3,12,20,L
        */
        file.close();
    }
    else {
        //you can change this later ---v

        std::cout << "Input file name: ";
        std::cin >> this->fileName;

        std::fstream createfile(this->fileName);
        /*
        * The output of the file
        * $Andrew Medeiros
        * ?CSC212
        * Lab 4,15,20,L
        * Assignment 2,30,50,A
        * $Bill Mates
        * ?CSC 212
        * Lab 3,12,20,L
        */
        createfile.close();
    }
}

// push student adds a new person to the list of students
void Gradebook::push_student(std::string studentName) {

    bool studentFound = false;

    for(auto & student : students){
        if(student.getName() == studentName){
            studentFound = true;
            break;
        }
    }
    if(!studentFound){
        students.push_back(*new Person(studentName));
        std::cout << studentName << " added to gradebook" << std::endl;
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

    if(studentFound == false){
        std::cout << "Student does not exist" << std::endl;
    }
}

// overwrites the existing save file with the new information
void Gradebook::saveFile() {

    std::cout << "Saving File." << std::endl;

    std::fstream file(this->fileName, std::ios::out);

    for(int i = 0; i < this->getStudentSize(); i++){
        Person student = this->getStudentList()->at(i);

        file << "$" << student.getName() << std::endl;

        for(auto grade : *student.getClassList()){

            double totalGradePoints = 0;
            double earnedGradePoints = 0;
            for(auto deliList : *grade.getDeliverableList()) {
                for (auto tempDev: deliList) {
                    totalGradePoints += tempDev.getPointsTotal();
                    earnedGradePoints += tempDev.getPointsEarned();
                }
            }

            file << "?" << grade.getClassName() << std::endl;
            for(auto deliList : *grade.getDeliverableList()){
                double totalPoints = 0;
                double earnedPoints = 0;

                for(auto tempDev : deliList){
                    totalPoints += tempDev.getPointsTotal();
                    earnedPoints += tempDev.getPointsEarned();
                }

                for(auto tempDev : deliList){
                    file << tempDev.getName() << "," << tempDev.getPointsEarned() << "," << tempDev.getPointsTotal() << "," << tempDev.getType() << std::endl;
                }

            }
        }
    }

    std::cout << "File Saved!" << std::endl;


}

// reads from the save file, reloading the current gradebook to the new config file
void Gradebook::readFile() {

}

// GETTERS & SETTERS


std::vector<Person>* Gradebook::getStudentList() {
    return &this->students;
}

int Gradebook::getStudentSize() {
    return this->students.size();
}
