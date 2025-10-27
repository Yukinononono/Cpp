#include <iostream>
#include <cmath>
#include <string>

class Car {
    public:
        std::string make;
        std::string model;
        std::string trim;
        int plateNum;

        void set_vinNum(std::string vin) {
            vinNum = vin;
            std::cout << "What's your cars VIN number? " << "\n";
            std::cin >> vin;
            
        }

        std::string get_vinNum() {
            return vinNum;
        }

        void print_vinNum() {
            std::cout << "VIN #: " << vinNum << "\n";
        }

    
    private:
        std::string vinNum;
        bool registrationValid;
        bool insuranceValid;

};

int main() {
    Car car1;
    std::string vin;    
    car1.set_vinNum(vin);
    car1.print_vinNum();

    
    
    
    
    
    return 0;
}