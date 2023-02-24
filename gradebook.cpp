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

    // File creation
    if (importFile) { // LOAD DATA FROM FILE
        //DEBUG
        //Person* currentStudent;
        //DEBUG
        // Ask for file name
        std::string fileName;
        std::cout << "Enter file: ";
        std::cin >> fileName;

        std::fstream readfile(fileName);
        std::string line;
        std::string currentstudent;
        // Ensure a valid file name
        while (not (readfile.is_open())){
            std::cout << "Could not open file. Please try again. "<< std::endl;
            std::cout << "Enter file: ";
            std::cin >> fileName;
        }

        while (getline(readfile, line)) {
            std::string s;
            std::istringstream ss(line);
            while (getline(ss, s)) {
                //this if if we know it's a student
                if (s.find('$') != std::string::npos) {
                    s.erase(remove(s.begin(), s.end(), '$'), s.end());
                    currentstudent = s;
                    this->push_student(s);
                }
                else {
                    //splits string by space, then adds each item in string into list
                    std::vector<std::string> deliver_list;
                    std::istringstream tt(s);
                    std::string t;
                    //i decided it would be better to split the string by commas, since an assignment name could have a space
                    while (getline(tt, t, ',')) {
                        deliver_list.push_back(t);
                    }
                    std::string delivName = deliver_list[0];
                    int delivPE = std::stoi(deliver_list[1]);
                    int delivPP = std::stoi(deliver_list[2]);
                    std::string delivType = deliver_list[3];
                    Deliverable* tempDeliverable = new Deliverable(delivName,delivType,delivPP,delivPE);
                    //whatever code is needed to add this deliverable to last person in student list
                    //students.at(student.size()-1).addDeliverable(tempDeliverable);
                }
            }
        }
        /* Im Assuming the file to look something like this:
        * $Andrew Medeiros
        * Lab 4,15,20,L
        * Assignment 2,30,50,A
        * $Bill Mates
        * Lab 3,12,20,L
        */
        readfile.close();
    }
    else {
        //you can change this later ---v
        std::fstream createfile("output.txt");

        std::string input;

        //will ask user to enter a student's name until they enter %
        std::cout << "Please Enter Student Name (Enter '%' To Quit):\n";
        //std::cin.ignore();
        std::cin >> input;
        while (input != "%") {
            std::string currentstudent = input;
            this->push_student(currentstudent);
            currentstudent.insert(0, 1, '$');

            createfile << currentstudent << std::endl;
            std::string input2;
            std::cout << "Please Enter A Grade In Format:\nName,Points Earned,Points Worth,Type\n(Enter '%' To Quit):\n";
            std::cin >> input2;
            //will ask user to enter a deliverable written in format: Name,Points_earned,Points_worth,Type
            while (input2 != "%") {
                //splits string by space, then adds each item in string into list
                std::vector<std::string> deliver_list;
                std::istringstream ss(input2);
                std::string s;
                while (getline(ss, s, ',')) {
                    deliver_list.push_back(s);
                }
                std::string delivName = deliver_list[0];
                int delivPE = std::stoi(deliver_list[1]);
                int delivPP = std::stoi(deliver_list[2]);
                std::string delivType = deliver_list[3];
                for (int i = 0; i < deliver_list.size() - 1; i++) {
                    createfile << deliver_list[i] << ',';
                }
                createfile << deliver_list[3] << std::endl;
                Deliverable* tempDeliverable = new Deliverable(delivName, delivType, delivPP, delivPE);
                //whatever code is needed to add this deliverable to last person in student list
                //students.at(student.size()-1).addDeliverable(tempDeliverable);
                std::cout << "Please Enter A Grade In Format:\nName,Points Earned,Points Worth,Type\n(Enter '%' To Quit):\n";
                std::cin >> input2;

            }
            std::cout << "Please Enter Student Name (Enter '%' To Quit):\n";
            std::cin >> input;

        }
        createfile.close();
        /*
        * The output of the file will match how I assume an input file to look
        * $Andrew Medeiros
        * Lab 4,15,20,L
        * Assignment 2,30,50,A
        * $Bill Mates
        * Lab 3,12,20,L
        */
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
