#include "Student.h"
#include "Faculty.h"
#include "BST.h"
#include <cstddef>
#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char ** argv) {
  ifstream sfile("studentTable");
  ifstream ffile("facultyTable");

  cout << "CHAPMAN DATABASE" << endl;
  if (sfile) {
    cout << "Run reading method"<< endl;
  } else {
    cout << "doesnt exist" << endl;
  }
  if (ffile) {
    cout << "Run reading method"<< endl;
  } else {
    cout << "doesnt exist" << endl;
  }

  return 0;
}
