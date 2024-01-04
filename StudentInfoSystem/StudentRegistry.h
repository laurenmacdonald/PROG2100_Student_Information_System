//
// Created by laure on 2023-11-12.
//

#ifndef PROG2100_FINALPROJECT_LAURENMACDONALD_STUDENTREGISTRY_H
#define PROG2100_FINALPROJECT_LAURENMACDONALD_STUDENTREGISTRY_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Student.h"
#include "ValidateInput.h"

using namespace std;

// Creating a struct to store student info - used to add new students and update student information
struct studentInfo{
    string fName, lName;
    int studentNum{}, midterm1{}, midterm2{}, final{};
} ;
class StudentRegistry {
private:
    // Vector to hold all the students
    std::vector<Student> studentList;
    // Grade weights to be used to calculate letter grade
    int midterm1Weight, midterm2Weight, finalWeight;


public:

    // Insert student information
    static studentInfo insertStudentInfo(int choice);

    // Add a student to the student registry
    bool addStudent(const studentInfo& newStudent);

    // Update student information
    void updateStudent(int studentNum, const studentInfo& updateStudent);

    // Remove a student from the student registry
    void removeStudent(int studentNum);

    // Print all student info
    void printAllStudents() const;

    // Print all student info in alphabetical order
    void printSortedStudents();

    // Print specific student info
    void printStudentInfo(int studentNum) const;

    // Delete all students from the registry
    void deleteAllStudents();

    // Change the grading scheme
    void changeGradingScheme();

    // Calculate the final letter grade
    void calculateLetterGrades();

    // Getters and setters for grade weights
    int getMidterm1Weight() const;

    void setMidterm1Weight(int weight);

    int getMidterm2Weight() const;

    void setMidterm2Weight(int weight);

    int getFinalWeight() const;

    void setFinalWeight(int weight);




};



#endif //PROG2100_FINALPROJECT_LAURENMACDONALD_STUDENTREGISTRY_H
