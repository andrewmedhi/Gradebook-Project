#include <string>
#include <vector>
#include "deliverable.h"

class Grade{
private:
    std::string className;
    std::vector<std::vector<Deliverable>> deliverableList;

public:

    Grade(std::string className); // constructor

    void push_deliverable(std::string name, std::string type, int pt, int pe);
    void pop_deliverable(std::string name, std::string type);
    void pop_category(std::string type);

    // getters & setters
    std::string getClassName();
    std::vector<Deliverable> getDeliverablesType(std::string type);
    std::vector<std::vector<Deliverable>>* getDeliverableList();











};


