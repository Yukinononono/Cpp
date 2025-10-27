#include <iostream>
#include <string>

using namespace std;

class Number {
    private:
        double *number;
    
    public: 
        Number(double num) {
            number = (double *) malloc(sizeof(double));
            *number = num;
            cout << "Constructer executing!" << "\n";
            cout << "Number: " << *number << "\n\n";
        }

        ~Number() {
            cout << "Destructor executing!" << "\n";
            cout << "Number: " << *number << "\n\n";
            free(number);
        }
};

    void test() {
        Number six(6);
    }

int main() {
    test();
    Number seven(7);

    return 0;
}