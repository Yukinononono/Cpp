#include <iostream>
#include <string>

using namespace std;

class Cat {
    private:
        string name;
        string color;
        string favorite_toy;

    public:
        void print_cat() {
            cout << "Name: " << name << "\n";
            cout << "Color: " << color << "\n";
            cout << "Favorite Toy: " << favorite_toy << "\n";
        }

    Cat() {
        name = "Unknown";
        color = "Unknown";
        favorite_toy = "Unknown";
    }

    Cat(string n) {
        name = n;
        color = "Unknown";
        favorite_toy = "Unknown";
    }

    Cat(string n, string c, string ft) {
        name = n;
        color = c;
        favorite_toy = ft;
    }
};

int main() {
    Cat cat1;
    cout << "Cat 1..." << "\n";
    cat1.print_cat();
    cout << endl;

    Cat cat2("Spot");
    cout << "Cat 2..." << "\n";
    cat2.print_cat();
    cout << endl;

    Cat cat3("Tim", "Gray", "Cat Scratcher");
    cout << "Cat 3..." << "\n";
    cat3.print_cat();
    cout << endl;

    return 0;
}