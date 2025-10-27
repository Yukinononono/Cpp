#include <iostream>
#include <string>

using namespace std;

class Employee {
    public: //this allows its member variables to be used outside of the def., in the main function for example.
        string name;

        void set_salary(double potential_salary) { //this is a "setter function" these are common.
            if (potential_salary < 0) salary = 0;
            else salary = potential_salary;
        }

        double get_salary() { //this is a "getter function"
            return salary;
        }

        void print_bonus() {
            cout << name << " bonus: " << calculate_bonus << "\n";
        }

    private: //this does not allow its member variables to be used outside of the def.
        double salary; //basically in main(), we cannot use employee1.salary, and try to make it a value.
        double calculate_bonus() {
            return salary * 0.10;
        }

};

int main() {
    Employee employee1;
    employee1.name = "Kevin";
    cout << employee1.name << "\n";

    employee1.set_salary(50000);
    cout << employee1.get_salary() << "\n";

    employee1.print_bonus();

    return 0;
}