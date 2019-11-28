#include "Student.h"
#include <cstddef>
#include <iostream>

using namespace std;

Student::Student() {
  id = 0;
  name = "";
  level = ""; //aka Freshman, Sophomore, etc..
  major = "";
  gpa = 0;
  advisorID = 0;
}

Student::Student(int i, string n, string l, string m, double g, int a) {
  id = i;
  name = n;
  level = l; //aka Freshman, Sophomore, etc..
  major = m;
  gpa = g;
  advisorID = a;
}

Student::~Student() {

}
