#include <string>

class Student {

  public:
    Student();
    Student(int i, std::string n, std::string l, std::string m, double g, int a);
    ~Student();

    int id;
    std::string name;
    std::string level; //aka Freshman, Sophomore, etc..
    std::string major;
    double gpa;
    int advisorID;
};
