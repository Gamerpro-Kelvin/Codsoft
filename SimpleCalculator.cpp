#include <iostream>

using namespace std;  // Use the standard namespace

int main() {
    // Declare variables
    double num1, num2, result;
    char operation;

    // Ask the user for input
    cout << "Enter first number: ";
    cin >> num1;  // Read first number
    cout << "Enter second number: ";
    cin >> num2;  // Read second number

    // Ask the user for the operation
    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;  // Read the operation

    // Perform the operation
    switch (operation) {
        case '+':
            result = num1 + num2;
            cout << "Result: " << result << endl;
            break;
        case '-':
            result = num1 - num2;
            cout << "Result: " << result << endl;
            break;
        case '*':
            result = num1 * num2;
            cout << "Result: " << result << endl;
            break;
        case '/':
            if (num2 != 0) {  // Check for division by zero
                result = num1 / num2;
                cout << "Result: " << result << endl;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "Error: Invalid operation." << endl;  // Handle invalid input
    }

    return 0;  // Exit the program
}

