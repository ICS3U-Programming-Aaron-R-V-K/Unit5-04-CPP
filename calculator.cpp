// Copyright (2025) Aaron Rivelino All rights reserved.
// Date: May 13, 2025
// Calculator that accepts the operation as well
// Uses a function and returns the result of the operation
// It asks for three parameters in main

#include <iomanip>
#include <iostream>
#include <string>

// Defines the calculation function, with three parameters
float calculate(std::string operation,
    float firstNumber, float secondNumber, int module1, int module2) {
    // calculations for each operation
    if (operation == "+")
        return firstNumber + secondNumber;
    else if (operation == "-")
        return firstNumber - secondNumber;
    else if (operation == "*")
        return firstNumber * secondNumber;
    else if (operation == "/")
        return firstNumber / secondNumber;
    else if (operation == "%")
        return module1 % module2;
    else
        return 0;
}

// Define main
int main() {
    // Get user input as strings
    std::string operation, firstNumberStr, secondNumberStr;
    // Declare this variables a s floats to type cast the string to a float
    float firstNumber, secondNumber;
    int module1 = 0, module2 = 0;

    // Get operation input from the user
    std::cout << "Enter the operator (+, -, *, /, %): ";
    std::cin >> operation;

    // If the operators are not any of the needed it will be an Invalid operator
    if (operation != "+" && operation != "-" &&
        operation != "*" && operation != "/" && operation != "%") {
        std::cout << "Invalid operator" << std::endl;
        return 0;
    }

    // Get user first number as string
    std::cout << "Enter the first number: ";
    std::cin >> firstNumberStr;

    // Get user second number as str
    std::cout << "Enter the second number: ";
    std::cin >> secondNumberStr;

    // If statement to type cast module from a float to an integer an be able to
    // Use %
    if (operation == "%") {
        try {
            module1 = std::stoi(firstNumberStr);
            module2 = std::stoi(secondNumberStr);
        } catch (...) {
            std::cout << "Invalid integer input for modulo operation"
            << std::endl;
            return 0;
        }
    // Else it will do the normal type cast for the user input
    } else {
        try {
            firstNumber = std::stof(firstNumberStr);
        } catch (...) {
            std::cout << "Invalid first number" << std::endl;
            return 0;
        }


        // Type cast the user number to a float
        try {
            secondNumber = std::stof(secondNumberStr);
        } catch (...) {
            std::cout << "Invalid second number" << std::endl;
            return 0;
        }
    }
    // create a variable to call the function
    float result = calculate(operation, firstNumber, secondNumber,
         module1, module2);

    // Set 2 sig digs, and display the answer
    std::cout << std::fixed << std::setprecision(2);
    // If the operation has module, it will print a different line
    if (operation == "%") {
        std::cout << module1 << " " << operation
                  << " " << module2 << " = " << result << std::endl;
    // else it will print the normal line
    } else {
        std::cout << firstNumber << " " << operation
                  << " " << secondNumber << " = " << result << std::endl;
    }

    return 0;
    }
