//
// Created by laure on 2023-11-11.
//

#ifndef PROG2100_FINALPROJECT_LAURENMACDONALD_STUDENT_H
#define PROG2100_FINALPROJECT_LAURENMACDONALD_STUDENT_H

#include <string>

using namespace std;

class Student {
private:
    // Attributes for a student.
    string fName{}, lName{};
    int studentNum{};
    int midterm1Grade{}, midterm2Grade{}, finalGrade{}, averageGrade{};
    char letterGrade{};

public:

    // Getters and setters
    const string &getFName() const;

    void setFName(const string &firstName);

    const string &getLName() const;

    void setLName(const string &lastName);

    int getStudentNum() const;

    void setStudentNum(int number);


    void setMidterm1Grade(const int &grade);

    void setMidterm2Grade(const int &grade);


    void setFinalGrade(const int &grade);

    int getAverageGrade() const;

    void setAverageGrade(int midterm1Weight, int midterm2Weight, int finalWeight);

    char getLetterGrade() const;

    void setLetterGrade(int avGrade);

    // Other functions
    string appendStudentInfo() const;

};


#endif //PROG2100_FINALPROJECT_LAURENMACDONALD_STUDENT_H
