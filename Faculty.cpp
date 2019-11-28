#include "Faculty.h"
#include <cstddef>
#include <iostream>

using namespace std;

Faculty::Faculty() {
  id = 0;
  name = "";
  level = "";
  department = "";
}

Faculty::Faculty(int i, string n, string l, string d){
  id = i;
  name = n;
  level = l; //aka Lecturer, Assistant Prof, etc..
  department = d;
}

Faculty::~Faculty() {

}
