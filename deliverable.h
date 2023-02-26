#include <string>
class Deliverable {
private:
    std::string name; // assignment name
    int pointTotal; // total points (ex. the 100 in 85/100)
    int pointEarned; // total points earned (ex. the 85 in 85/100)
    std::string type; // assigment type (ex. lab, homework, etc.)


public:
    Deliverable(std::string name, std::string type, int pw, int pe); // constructor


    // getters & setters
    std::string getName();
    int getPointsTotal();
    int getPointsEarned();
    std::string getType();

};

