#include <iostream>
#include "gradebook.h"

int main() {
    Gradebook gradebook;

    // User Input
    std::string input = "0";
    while(input != "-1"){
        std::cout << "--- GRADEBOOK ---" << std::endl;
        std::cout << "1 - View Data" << std::endl;
        std::cout << "2 - Edit Data" << std::endl;
        std::cout << "-1 - Quit" << std::endl;


        std::cout << "Option: ";
        std::cin >> input;

        if(input == "1"){ // VIEW DATA
            std::string viewInput = "0";
            while(viewInput != "-1"){
                // View Menu
                std::cout << "--- VIEW DATA ---" << std::endl;
                std::cout << "1 - View Entire Gradebook" << std::endl;
                std::cout << "2 - View Specific Person" << std::endl;
                std::cout << "-1 - Back" << std::endl;

                // User Input
                std::cout << "Option: ";
                std::cin >> viewInput;

                if(viewInput == "1"){ // VIEW ENTIRE GRADEBOOK TODO: PRINT ENTIRE GRADEBOOK

                } else if (viewInput == "2"){ // VIEW SPECIFIC PERSON
                    std::string specificInput = "0";
                    if(gradebook.getStudentList().empty()){
                        std::cout << "No students are in the gradebook, add new students to view them" << std::endl;
                    } else {
                        // Student Menu
                        std::string studentViewInput = "0";

                        while(studentViewInput != "-1") {
                            std::cout << "--- VIEW STUDENT ---" << std::endl;
                            for (int i = 0; i < gradebook.getStudentSize(); i++) {
                                std::cout << i << " - " << gradebook.getStudentList().at(i).getName() << std::endl;
                            }

                            std::cout << "Option: ";
                            std::cin >> studentViewInput;

                            if(std::stoi(studentViewInput) > gradebook.getStudentSize()){
                                std::cout << "Please input a valid option." << std::endl;
                            } else { // TODO: PRINT STUDENT GRADES

                            }

                        }

                    }

                }


            }

        } else if (input == "2"){ // EDIT DATA
            std::string editInput = "0";
            while(editInput != "-1"){
                // Menu
                std::cout << "--- EDIT DATA ---" << std::endl;
                std::cout << "1 - Add Student to Gradebook" << std::endl;
                std::cout << "2 - Remove Student from Gradebook" << std::endl;
                std::cout << "3 - Add Student to Class" << std::endl;
                std::cout << "4 - Remove Student from Class" << std::endl;
                std::cout << "5 - Add New Deliverable" << std::endl;
                std::cout << "6 - Remove a Deliverable" << std::endl;

                // User Input
                std::cout << "Option: ";
                std::cin >> editInput;

                // TODO: IF STATEMENTS
                if (editInput == "1"){

                }
            }

        }  else {
            std::cout << "Please input a valid option." << std::endl;
        }

    }

    std::cout << "Goodbye." << std::endl;
}
 