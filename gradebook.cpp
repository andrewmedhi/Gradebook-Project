#include "gradebook.h"


// will ask the user whether they want to load an existing Gradebook or generate a new one
//      reading will search for a file of the same name and will organize the data into the proper objects
//      generating a new one will create an empty "Gradebook.txt"

Gradebook::Gradebook() {

}

// push student adds a new person to the list of students
void Gradebook::push_student(std::string studentName) {

}

// pop student will search for an existing student and remove them
void Gradebook::pop_student(std::string studentName) {

}

// overwrites the existing save file with the new information
void Gradebook::saveFile() {

}

// reads from the save file, reloading the current gradebook to the new config file
void Gradebook::readFile() {

}

// GETTERS & SETTERS

Person Gradebook::getStudent(std::string Name) {



}

std::vector<Person> Gradebook::getStudentList() {
    return this->students;
}
