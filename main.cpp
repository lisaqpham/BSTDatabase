#include "Student.h"
#include "Faculty.h"
#include "BST.h"
#include <cstddef>
#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char ** argv) {
  int choice;
  bool continue = true;
  ifstream sfile("studentTable");
  ifstream ffile("facultyTable");



  cout << "CHAPMAN DATABASE" << endl;
  if (sfile) {
    cout << "Run reading method"<< endl;
  } else {
    BST<int> masterStudent = new BST<int>();
  }
  if (ffile) {
    cout << "Run reading method"<< endl;
  } else {
    BST<int> masterFaculty = new BST<int>();
  }

  while(continue) {
    cout << "MENU" << endl;
    cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
    cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
    cout << "3. Find and display student information given the students id" << endl;
    cout << "4. Find and display faculty information given the faculty id" << endl;
    cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl;
    cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
    cout << "7. Add a new student" << endl;
    cout << "8. Delete a student given the id" << endl;
    cout << "9. Add a new faculty member" << endl;
    cout << "10. Delete a faculty member given the id" << endl;
    cout << "11. Change a student’s advisor given the student id and the new faculty id" << endl;
    cout << "12. Remove an advisee from a faculty member given the ids" << endl;
    cout << "13. Rollback" << endl;
    cout << "14. Exit" << endl;

    cin >> choice;
    if (choice == 1) {
      printStudents(masterStudent);
    } else if (choice == 2) {
      printFaculty(masterFaculty);
    } else if (choice == 3) {
      
    } else if (choice == 4) {

    } else if (choice == 5) {

    } else if (choice == 6) {

    } else if (choice == 7) {

    } else if (choice == 8) {

    } else if (choice == 9) {

    } else if (choice == 10) {

    } else if (choice == 11) {

    } else if (choice == 12) {

    } else if (choice == 13) {

    } else if (choice == 14) {

    } else {
      cout << "Invalid Choice. Please try again." << endl;
    }
  }

  return 0;
}
