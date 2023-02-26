#include "person.h"

class Gradebook{
private:
    std::vector<Person> students;
    std::string fileName;

public:
    Gradebook(); // constructor

    void push_student(std::string studentName);
    void pop_student(std::string studentName);

    void saveFile();
    void readFile();

    int getStudentSize();
    std::vector<Person>* getStudentList();






};

