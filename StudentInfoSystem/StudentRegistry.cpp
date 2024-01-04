//
// Created by laure on 2023-11-12.
//
/*
 * Used throughout this file are iterators to interact with the vector studentList.
 * Iterator is any object that points to an element in a range such as a vector and has the ability to iterate through
 * elements in that range using a set of operators.
 *
 * You will see this used in methods which iterate through the vector, such as removeStudent().
 * In the removeStudent function, the remove_if function uses iterators to point to the beginning and end of the vector
 * list of students. An iterator is also used to point to the student object that is removed to see if it was successfully
 * deleted from the vector of students.
 */
#include "StudentRegistry.h"
#include "ValidateInput.h"


// Insert student information, returns a studentInfo struct to hold student info
// Takes a const int to differentiate between adding a new student and updating a previous student (updating does not
// require input of a student number as this will remain the same).
studentInfo StudentRegistry::insertStudentInfo(int choice) {
    studentInfo newStudent;
    int studentNum = 0, midterm1 = 0, midterm2 = 0, final = 0;

    // Prompt and take user data, store in the newStudent struct
    cout << "INPUT STUDENT INFORMATION:" << endl
         << "-----------------------------------------" << endl
         << "Enter first name:";
    cin >> newStudent.fName;
    cout << "Enter last name:";
    cin >> newStudent.lName;
    if (choice == 1) {
        cout << "Enter student number:";
        newStudent.studentNum = validateInt(studentNum, 100000, 999999);
        cout << "Enter grade information (put 0 if no grades yet):" << endl;
        cout << "Enter midterm 1 grade:";
        // Use the validateInt method with 0 and 100 as range of grades
        newStudent.midterm1 = validateInt(midterm1, 0, 100);
        cout << "Enter midterm 2 grade:";
        newStudent.midterm2 = validateInt(midterm2, 0, 100);
        cout << "Enter final grade:";
        newStudent.final = validateInt(final, 0, 100);
    } else if (choice == 2) {
        cout << "Enter grade information (put 0 if no grades yet):" << endl;
        cout << "Enter midterm 1 grade:";
        // Use the validateInt method with 0 and 100 as range of grades
        newStudent.midterm1 = validateInt(midterm1, 0, 100);
        cout << "Enter midterm 2 grade:";
        newStudent.midterm2 = validateInt(midterm2, 0, 100);
        cout << "Enter final grade:";
        newStudent.final = validateInt(final, 0, 100);
    }
    return newStudent;
}
// Add a student to the student registry using vector push_back function
// Takes the studentInfo struct newStudent
bool StudentRegistry::addStudent(const studentInfo &newStudent) {
    // Create new student object
    Student student;
    int studentNumberAttempt = newStudent.studentNum;
    bool flag;

    auto it = std::find_if(studentList.begin(), studentList.end(),
                           [studentNumberAttempt](const Student &student) {
        return student.getStudentNum() == studentNumberAttempt;
    });
    // if the iterator is not equal to end(), student exists
    if (it != studentList.end()) {
        // Display error message as student number already in registry
        cout << "Student number #" << it->getStudentNum() << " already exists." << endl;
        flag = false;
    } else {
        // Set the attributes using the newStudent struct variables
        student.setFName(newStudent.fName);
        student.setLName(newStudent.lName);
        student.setStudentNum(newStudent.studentNum);
        student.setMidterm1Grade(newStudent.midterm1);
        student.setMidterm2Grade(newStudent.midterm2);
        student.setFinalGrade(newStudent.final);
        // Add the student to the end of the vector
        studentList.push_back(student);
        // Success message
        cout << "Student #" << student.getStudentNum() << " successfully added to the registry." << endl;
        flag = true;
    }
    return flag;
}

// Update student information, takes student number to search and struct to populate info
void StudentRegistry::updateStudent(int studentNum, const studentInfo &updateStudent) {
    // Check to see if vector is empty, display error if it is.
    if (studentList.empty()) {
        cout << "Error. There are no students in the registry." << endl;
    } else {
        // Uses iterator and find_if algorithm to find the student number associated with a student object in the vector. Using a lambda
        // function to return boolean (student number does or does not exist in list).
        auto it = std::find_if(studentList.begin(), studentList.end(), [studentNum](const Student &student) {
            return student.getStudentNum() == studentNum;
        });

        // if the iterator is not equal to end(), student exists
        if (it != studentList.end()) {
            // Update the student information with the data from the struct
            it->setFName(updateStudent.fName);
            it->setLName(updateStudent.lName);
            // Does not include student number to update as this will always stay the same.
            it->setMidterm1Grade(updateStudent.midterm1);
            it->setMidterm2Grade(updateStudent.midterm2);
            it->setFinalGrade(updateStudent.final);
            // print the student info of the student object pointed to by the iterator
            cout << "Student number #" << it->getStudentNum() << " information updated." << endl;
        } else {
            // If student does not exist, print error message.
            cout << "Student number does not exist in registry." << endl;
        }
    }
}

// Remove a student from the student registry using vector erase function
void StudentRegistry::removeStudent(int studentNum) {
// Using remove_if from the algorithm header file within the erase function, will remove the element that meets the criteria below:
// Start at beginning of studentList, go to the end of studentList, with a lambda function to compare student number
// to search with the student object. Lambda function returns boolean.
    if (studentList.empty()) {
        cout << "Error. There are no students in the registry." << endl;
    } else {
        auto listSize = studentList.size();     // get the size of the list before deletion for error handling.
        studentList.erase(
                std::remove_if(studentList.begin(), studentList.end(), [studentNum](const Student &student) {
                    return student.getStudentNum() == studentNum;
                }), studentList.end());
        // End() refers to the 'past-the-end element' that would theoretically follow the last element in the vector
        // If the list is the same size, nothing was deleted.
        if (studentList.size() == listSize) {
            cout << "Error. Student number does not match numbers in records or record not found." << endl;
        } else {
            cout << "Student number " << studentNum << " deleted." << endl;
        }
    }
}

// Print the entire list of students' info
void StudentRegistry::printAllStudents() const {
    // Iterate through the list of students and print their info via the appendStudentInfo() function.
    if (studentList.empty()) {
        cout << "Error. There are no students in the registry." << endl;
    } else {
        cout << "PRINTING ALL STUDENT INFO:" << endl;
        for (const Student &student: studentList) {
            cout << "-----------------------------------------" << endl;
            cout << student.appendStudentInfo() << endl;
        }
    }
}

// Print the entire list of students' info, in alphabetical order
void StudentRegistry::printSortedStudents() {
    if (studentList.empty()) {
        cout << "Error. There are no students in the registry." << endl;
    } else {
        cout << "SORTING STUDENT INFO IN ALPHABETICAL ORDER:" << endl
             << "-----------------------------------------" << endl;
        // Using the sort function with a lambda function of boolean return type to compare two student objects.
        sort(studentList.begin(), studentList.end(), [](const Student &student1, const Student &student2) {
            // Compare last names, if they are equal...
            if (student1.getLName() == student2.getLName()) {
                // Then sort by first name, the first name with lesser value returned first
                return student1.getFName() < student2.getFName();
                // If last names don't match
            } else {
                // Sort by last name, last name with lesser value returned first
                return student1.getLName() < student2.getLName();
            }
        });
        // Print the list of students after the list is alphabetized.
        printAllStudents();
    }
}

// Print the student info of one specified student
void StudentRegistry::printStudentInfo(int studentNum) const {
    if (studentList.empty()) {
        cout << "Error. There are no students in the registry." << endl;
    } else {
        // Setting up an iterator, using find_if function with a lambda function that take's input student number to compare
        // against student object. Returns boolean.
        auto it = std::find_if(studentList.begin(), studentList.end(), [studentNum](const Student &student) {
            return student.getStudentNum() == studentNum;
        });

        // if the iterator is not equal to end(), student exists
        if (it != studentList.end()) {
            // print the student info of the student object pointed to by the iterator
            cout << "STUDENT INFO:" << endl
                 << "-----------------------------------------" << endl;
            cout << it->appendStudentInfo() << endl;
        } else {
            // If student does not exist, print error message.
            cout << "Student number does not exist in registry." << endl;
        }
    }
}

// Delete all students from the registry
void StudentRegistry::deleteAllStudents() {
    // If the vector of students is empty, display error message.
    if (studentList.empty()) {
        cout << "Error. There are no records in the registry to delete." << endl;
    } else {
        // Use the clear function to delete all student info from the vector of students, display message.
        studentList.clear();
        cout << "All student records deleted." << endl;
    }
}

// Change the grading scheme
void StudentRegistry::changeGradingScheme() {
    bool validFlag;
    int tempMidterm1Weight, tempMidterm2Weight, tempFinalWeight, total;

    cout << "CHANGE GRADING SCHEME:" << endl
         << "-----------------------------------------" << endl;
    do {
        cout << "Enter weight for midterm 1:";
        cin >> tempMidterm1Weight;
        cout << "Enter weight for midterm 2:";
        cin >> tempMidterm2Weight;
        cout << "Enter weight for final exam:";
        cin >> tempFinalWeight;

        total = tempMidterm1Weight + tempMidterm2Weight + tempFinalWeight;

        if (total > 100 || total < 100) {
            cout << "ERROR. The total of the weights must equal 100. Try again." << endl;
        } else {
            validFlag = true;
            this->setMidterm1Weight(tempMidterm1Weight);
            this->setMidterm2Weight(tempMidterm2Weight);
            this->setFinalWeight(tempFinalWeight);
        }
    } while (!validFlag);
    cout << "Midterm 1 weight changed to:" << this->getMidterm1Weight() << endl
         << "Midterm 2 weight changed to:" << this->getMidterm2Weight() << endl
         << "Final exam weight changed to:" << this->getFinalWeight() << endl;
}

void StudentRegistry::calculateLetterGrades() {
    int averageGrade;
    if (studentList.empty()) {
        cout << "Error. There are no students in the registry." << endl;
    } else {
        for (auto &student: studentList) {
            student.setAverageGrade(this->getMidterm1Weight(), this->midterm2Weight, this->finalWeight);
            averageGrade = student.getAverageGrade();
            student.setLetterGrade(averageGrade);

            cout << "Letter grade for student #" << student.getStudentNum() << ": " << student.getLetterGrade() << endl;
        }
    }
}

int StudentRegistry::getMidterm1Weight() const {
    return midterm1Weight;
}

void StudentRegistry::setMidterm1Weight(int weight) {
    StudentRegistry::midterm1Weight = weight;
}

int StudentRegistry::getMidterm2Weight() const {
    return midterm2Weight;
}

void StudentRegistry::setMidterm2Weight(int weight) {
    StudentRegistry::midterm2Weight = weight;
}

int StudentRegistry::getFinalWeight() const {
    return finalWeight;
}

void StudentRegistry::setFinalWeight(int weight) {
    StudentRegistry::finalWeight = weight;
}

