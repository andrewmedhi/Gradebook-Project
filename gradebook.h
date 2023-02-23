#include "person.h"

class Gradebook{
private:
    std::vector<Person> students;

public:
    Gradebook(); // constructor

    void push_student(std::string studentName);
    void pop_student(std::string studentName);

    void saveFile();
    void readFile();

    Person getStudent(std::string Name);
    std::vector<Person> getStudentList();






};

