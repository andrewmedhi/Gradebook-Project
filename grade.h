#include <string>
#include <vector>
#include "person.h"
#include "deliverable.h"

class Grade{
private:
    std::string StudentName;
    Person* Student;
    int Points_Potential;
    int Points_Earned;
    std::string Student_Class;
    float Current_Grade; //current grade
    std::vector<std::vector<Deliverable>> Assignment_List;
public:
    Grade(std::string student_name, std::string student_class);
    std::string getName();
    std::string getClass();
    float getGrade();
    int getAss(char type, std::string assName);
    void addAss(Deliverable assignment);










};


