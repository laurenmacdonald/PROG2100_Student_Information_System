//
// Created by laure on 2023-11-20.
//

#ifndef PROG2100_FINALPROJECT_LAURENMACDONALD_MENU_H
#define PROG2100_FINALPROJECT_LAURENMACDONALD_MENU_H

#include <iostream>
using namespace std;

void printMainMenu(){
    cout << "Please choose from the following options:" << endl
         << "---------------------------------------------------------------" << endl
         << "1. Print all Student data" << endl
         << "2. Sort the list of students in alphabetical order by last name" << endl
         << "3. Add a new student" << endl
         << "4. Calculate the letter grade of all students" << endl
         << "5. Change the information of a previous student" << endl
         << "6. Print the data of a specific student" << endl
         << "7. Remove a student from the registry" << endl
         << "8. Delete ALL student data" << endl
         << "9. Change grading scheme" << endl
         << "10. Exit" << endl
         << "---------------------------------------------------------------" << endl;
}
#endif //PROG2100_FINALPROJECT_LAURENMACDONALD_MENU_H
