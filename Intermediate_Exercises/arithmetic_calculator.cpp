//The goal is to make a simple arithmetic calculator, 2+2, 5-4, 5/5, and so on.
#include <iostream>
#include <string>
#include <limits>

int main() {
    std::string equationDirty;
    std::string equationClean;
    char o;
    int indexLocation = -1;
    
    std::cout << "-------- Calc is short for calculator chat --------" << "\n\n";
    std::cout << "Insert your equationClean below (only one operation please):" << "\n";
    std::getline(std::cin, equationDirty);


    for (int s = 0; s < equationDirty.length(); s++) {
        if (equationDirty[s] != ' ') {
            equationClean.append(1, equationDirty[s]);
        }
    }

    for (int i = 0; i < equationClean.length(); i++) {//So basically we set i to index 0 of the string, then while i < the length of equationClean, we output the character.
        if (equationClean[i] == '+') {
            o = '+';
            indexLocation = i;
        }
        else if (equationClean[i] == '-') {
            o = '-';
            indexLocation = i;
        }
        else if (equationClean[i] == '*') {
            o = '*';
            indexLocation = i;
        }
        else if (equationClean[i] == '/') {
            o = '/';
            indexLocation = i;
        }
        else if (equationClean[i] == '^') {
            o = '^';
           indexLocation = i;
        }
    }
    
    if (indexLocation == -1) {
        std::cout << "No valid operator found." << "\n";
        return 1;
    }


    std::string leftString = equationClean.substr(0, indexLocation);
    std::string rightString = equationClean.substr(indexLocation + 1);

    double leftNum = std::stod(leftString);
    double rightNum = std::stod(rightString);

    if (o == '+') {
        std::cout << "Result: " << leftNum + rightNum << "\n";
    }
    else if (o == '-') {
        std::cout << "Result: " << leftNum - rightNum << "\n";
    }
    else if (o == '*') {
        std::cout << "Result: " << leftNum * rightNum << "\n";
    }
    else if (o == '/') {
        std::cout << "Result: " << leftNum / rightNum << "\n";
    }
    else {
        std::cout << "There was an issue calculating. Sorry.";
        return 1;
    }

    return 0;
}