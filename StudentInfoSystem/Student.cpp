//
// Created by laure on 2023-11-11.
//

#include "Student.h"

const string &Student::getFName() const {
    return fName;
}

void Student::setFName(const string &firstName) {
    Student::fName = firstName;
}

const string &Student::getLName() const {
    return lName;
}

void Student::setLName(const string &lastName) {
    Student::lName = lastName;
}

int Student::getStudentNum() const {
    return studentNum;
}

void Student::setStudentNum(int number) {
    Student::studentNum = number;
}


void Student::setMidterm1Grade(const int &grade) {
    Student::midterm1Grade = grade;
}


void Student::setMidterm2Grade(const int &grade) {
    Student::midterm2Grade = grade;
}


void Student::setFinalGrade(const int &grade) {
    Student::finalGrade = grade;
}

int Student::getAverageGrade() const {
    return averageGrade;
}

void Student::setAverageGrade(int midterm1Weight, int midterm2Weight, int finalWeight) {
    Student::averageGrade =
            (midterm1Grade * midterm1Weight + midterm2Grade * midterm2Weight + finalGrade * finalWeight) /
            (midterm1Weight + midterm2Weight + finalWeight);
}


char Student::getLetterGrade() const {
    return letterGrade;
}

void Student::setLetterGrade(int avGrade) {
    if(avGrade > 90){
        letterGrade = 'A';
    } else if (avGrade >= 80){
        letterGrade = 'B';
    } else if (avGrade >= 70){
        letterGrade = 'C';
    } else if (avGrade >= 60 ){
        letterGrade = 'D';
    } else {
        letterGrade = 'F';
    }
}

string Student::appendStudentInfo() const{

    // Create new string variables using the to_string variable to change other data types to string
    string studentNumStr = to_string(this->studentNum);
    string midterm1GradeStr = to_string(this->midterm1Grade);
    string midterm2GradeStr = to_string(this->midterm2Grade);
    string finalGradeStr = to_string(this->finalGrade);
    string studentInfo;

    // Use the append method to append all the converted information into one string
    studentInfo="First Name: " + this->fName +
                      "\nLast Name: " + this->lName +
                      "\nStudent Number: " + studentNumStr +
                      "\nMidterm 1 Grade: " + midterm1GradeStr +
                      "\nMidterm 2 Grade: " + midterm2GradeStr +
                      "\nFinal Grade: " + finalGradeStr;


    // Return the string of all student info for use.
    return studentInfo;
}


