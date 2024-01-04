//
// Created by laure on 2023-11-13.
//

#ifndef PROG2100_FINALPROJECT_LAURENMACDONALD_START_H
#define PROG2100_FINALPROJECT_LAURENMACDONALD_START_H

#include <iostream>
#include "ValidateInput.h"
#include "StudentRegistry.h"
#include "Menu.h"

using namespace std;

// Declaring variables to be used throughout
int studentNum;
int userInput = 0;
bool menuFlag;
// New instance of studentRegistry class
StudentRegistry studentRegistry;
// New studentInfo struct to store student data to be populated in student object throughout program
studentInfo newStudentInfo;

void creation(){
    // Setting default grade weights
    studentRegistry.setMidterm1Weight(25);
    studentRegistry.setMidterm2Weight(25);
    studentRegistry.setFinalWeight(50);

    cout << "********* STUDENT INFORMATION SYSTEM *********" << endl
         << "Student registry is empty. How many students would you like to add to the registry?" << endl;
    userInput = validateInt(userInput, 1, 10);
    for(int i=0; i < userInput; i++){
        newStudentInfo = StudentRegistry::insertStudentInfo(1);
        studentRegistry.addStudent(newStudentInfo);
    }
    cout << "Students successfully added." << endl;
}


void start() {
    creation();
    // Do while loop to keep menu on screen unless user quits the program
    do {
        printMainMenu();
        // Take user input for menu/switch statement and validate it
        userInput = validateInt(userInput, 1, 10);
        switch(userInput){
            case 1:
                // Print all student data.
                studentRegistry.printAllStudents();
                menuFlag = true;
                break;
            case 2:
                // Print all student data, sorted alphabetically
                studentRegistry.printSortedStudents();
                menuFlag = true;
                break;
            case 3:
                // Add a new student
                bool validStudent;
                do{
                    newStudentInfo = StudentRegistry::insertStudentInfo(1);
                    validStudent = studentRegistry.addStudent(newStudentInfo);
                }while(!validStudent);
                menuFlag = true;
                break;
            case 4:
                // Calculate the letter grade of all students
                studentRegistry.calculateLetterGrades();
                menuFlag = true;
                break;
            case 5:
                // Update student information
                cout << "Input student number to update:" << endl;
                studentNum = validateInt(userInput, 100000, 999999);
                newStudentInfo = StudentRegistry::insertStudentInfo(2);
                studentRegistry.updateStudent(studentNum, newStudentInfo);
                menuFlag = true;
                break;
            case 6:
                // View one student information
                cout << "Input student number to view:" << endl;
                studentNum = validateInt(userInput, 100000, 999999);
                studentRegistry.printStudentInfo(studentNum);
                menuFlag = true;
                break;
            case 7:
                // Delete student
                cout << "Input student number to delete:" << endl;
                studentNum = validateInt(userInput, 100000, 999999);
                studentRegistry.removeStudent(studentNum);
                menuFlag = true;
                break;
            case 8:
                // Delete all students
                studentRegistry.deleteAllStudents();
                menuFlag = true;
                break;
            case 9:
                // Change grading scheme
                studentRegistry.changeGradingScheme();
                menuFlag = true;
                break;
            case 10:
                // Quit - display thank you message and end program
                cout << "Thank you for using the student information system." << endl;
                exit(0);
            default:
                cout << "Unexpected error.";
                break;
        }
    } while (menuFlag);
}


#endif //PROG2100_FINALPROJECT_LAURENMACDONALD_START_H
