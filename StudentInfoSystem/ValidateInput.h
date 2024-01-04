//
// Created by laure on 2023-11-15.
//

#ifndef PROG2100_FINALPROJECT_LAURENMACDONALD_VALIDATEINPUT_H
#define PROG2100_FINALPROJECT_LAURENMACDONALD_VALIDATEINPUT_H
#include <iostream>
#include <limits>

using namespace std;
/*
 * PURPOSE:
 *  Take user input, validate the input, and return the value input once validated. Lower and upper limit parameters
 *  are the lowest and highest allowed numbers for this section of input.
 * INPUT: double to validate
 * RETURN: double
 */
static int validateInt(int num, int lowerLimit, int upperLimit){
    cin >> num;
    while(true){
        // If no issues, exit if...else statement and return value
        if(!cin.fail()){
            if (num < lowerLimit || num > upperLimit) {
                // Ensure the value input doesn't cause system error. If it does, clear and try again
                cout << "Please enter a valid number between " << lowerLimit << " and " << upperLimit << "." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> num;
            } else {
                break;
            }
        } else if (num > lowerLimit && num < upperLimit){
            // Ensure the value input doesn't cause system error. If it does, clear and try again
            cout << "Please enter a valid number between " << lowerLimit << " and " << upperLimit << "." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cin >> num;
        }
    }
    return num;
}
#endif //PROG2100_FINALPROJECT_LAURENMACDONALD_VALIDATEINPUT_H
