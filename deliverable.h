#include <string>
class Deliverable {
private:
    std::string name;
    int points_Worth;
    int points_Earned;
    char assType;


public:
    Deliverable(std::string name, int points_Worth, int points_Earned, char assType);
    std::string GetName();
    int GetPW();
    int GetPE();
    char GetAss();

/*
That looks like a sad face.
|
v

*/

};

