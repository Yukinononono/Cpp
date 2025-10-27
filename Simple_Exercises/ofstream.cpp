#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream outFile;

    outFile.open("file.txt"); //if you want to append rather than overwrite you'd use: "outFile.open("file.txt", ofstream::app);"
    
    if (outFile.fail()) {
        cout << "Error opening file." << endl;
        return 1; //signal to terminal that there was an issue.
    }

    outFile << "content" << endl;

    double x = 4.5;
    int y = 10;
    string z = "abc";

    outFile << x << endl;
    outFile << y << endl;
    outFile << z << endl;

    outFile.close(); //good practice

    return 0;
}