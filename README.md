# Student Information System

> **Completed for PROG2100 Final Project**
>
> Lauren MacDonald, December 2023
>
>**Languages/Concepts**: C++.

## Background:
### PROG2100 Final Project Instructions:
A console program that stores information about students in a class and enables users to manipulate the data regarding each student.

### Assignment Requirements:
1. Student class has the following attributes:
   - last name, first name, student number, grades for midterm 1, 2 and final.
2. Print list of all students in the class.
3. Print list of all students in alphabetical order by last name (if same last name, order by first name).
4. Add another student
5. Calculate the letter grade based on the following rule for average:
   - A: higher than 90%
   - B: between 80%-90%
   - C: between 70%-80%
   - D: between 60%-70%
   - F: below 60%
6. Print data of a specific student.
7. Remove a student from the list.
8. Delete all student data.
9. Update the weight of the grades.

### Output Example:
The following is an example provided from the assignment outline for what the input prompts should look like.

![](/README-Images/OutputExample.png)

## Program Execution:

### Overview
Classes for students and student registry are used, and header files for other functionality such as start (running the 
program), display main menu, take student information, input validation are implemented. 

Student registry class has a vector to hold the list of students and functionality to work with the student info.

Student info header file has a struct for student information to be used in adding a new student or updating student info.

All functionality for student-related create, read, update, delete (CRUD) activities occur within the student registry
class. 

The entry point to the program is main.cpp, where the start function is called.

### Running Program Screenshots
#### Program start

![](/README-Images/start_h_1.png)

Program starts with prompt to input student data into the student registry. 

#### Print student data (original and sorted), adding a new student

![](/README-Images/print_data_input_data.png)

#### Letter grade, update data, delete data

![](/README-Images/lettergrade_update_view_delete_change.png)

#### Error examples

![](/README-Images/error_examples.png)
