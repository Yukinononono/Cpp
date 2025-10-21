#include <iostream>
using namespace std;

bool iseven(int getnumber){
    return getnumber % 2 == 0;
}

int main() {
    int getnumber;

    cout << "Enter a number to check: ";
    cin >> getnumber;

    if (iseven(getnumber)){
        cout << getnumber << " is even.";
    }   else {
        cout << getnumber << " is odd.";
    }   


    return 0;
}