#include <string>
#include <vector>

class Faculty {

  public:
    Faculty();
    Faculty(int i, std::string n, std::string l, std::string d);
    ~Faculty();

    int id;
    std::string name;
    std::string level; //aka Freshman, Sophomore, etc..
    std::string department;
    std::vector<int> advisees;
};
