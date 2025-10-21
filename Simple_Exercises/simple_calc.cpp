#include <iostream>
using namespace std;

int mult(int num1, int num2){
    return num1 * num2;
}

int divide(int num1, int num2){
    return num1 / num2;
}

int add(int num1, int num2){
    return num1 + num2;
}

int sub(int num1, int num2){
    return num1 - num2;
}

int main(){
    int num1, num2;
    char operation;

    cout << "What is the first number you'd like in the equation? ";
    cin >> num1;

    cout << "What is the second number you'd like in the equation? ";
    cin >> num2;

    cout << "What is the operation you'd like to perform? (ex: *, /, +, -.) ";
    cin >> operation;

    int result;
    if (operation == '*'){
        result = mult(num1, num2);
        cout << "Result: " << result;
    }
    else if (operation == '/'){
        if (num2 == 0){
            cout << "Cannot divide by zero." << endl;
        } else {
            result = divide(num1, num2);
            cout << "Result: " << result;
        }
    }
    else if (operation == '+'){
        result = mult(num1, num2);
        cout << "Result: " << result;
    }
    else if (operation == '-'){
        result = sub(num1, num2);
        cout << "Result: " << result;
    }
    else {
        cout << "Invalid operation.";
    }

    return 0;
}