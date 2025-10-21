#include <iostream>

using namespace std;

string ifMinor(int age){
    if (age < 18) {
        return "minor";
    } else {
        return "adult";
    }
}

int main(){
    
    string name;
    int age;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your age: ";
    cin >> age;

    cout << "Hello " << name << ", you are a(n) " << ifMinor(age) << "!";


    return 0;
}