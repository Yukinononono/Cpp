#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Account {
    public: //Access Specifier
    string name;
    int id;
    double balance;

    Account() {}
    Account (string n, int accnum, double bal) {
        name = n;
        id = accnum;
        balance = bal;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposit $" << amount << ". New balance : $" << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient Funds." << endl;
        } else {
            balance -= amount;
            cout << "Withdrew $" << amount << ". New balance: $" << balance << endl;
        }
    }

    void display() {
        cout << "Account #: " << id << " | Name: " << name << " | Balance: " << balance << endl;
    }

    void saveToFile(ofstream &outFile) {
        outFile << id << " " << name << " " << balance << endl;
    }

    void loadFromFile(ifstream &inFile) {
        inFile >> id >> name >> balance;
    }
};

// Function that loads accounts from a file.
void loadAccounts(vector<Account> &accounts, const string &filename) {
    ifstream inFile(filename);
    if (!inFile) return; //File might not exist yet.

    Account temp;
    while (!inFile.eof()) {
        temp.loadFromFile(inFile);
        if (inFile) accounts.push_back(temp);
    }
    inFile.close();
}

// Function to save accounts to a file.
void saveAccounts(vector<Account> &accounts, const string &filename) {
    ofstream outFile(filename);
    for (auto &acc : accounts) acc.saveToFile(outFile);
    outFile.close();
}

// Find account by ID.
Account* findAccount(vector<Account> &accounts, int id) {
    for (auto &acc : accounts) {
        if (acc.id == id) return &acc;
    }
    return nullptr;
}

int main() {
    vector<Account> accounts;
    const string filename = "accounts.txt";

    loadAccounts(accounts, filename);

    int choice;
    do {
        cout << "\n--- Banking System Menu ---\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Check Balance\n";
        cout << "5. Display All Accounts\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (choice == 1) {
            string name;
            int id;
            double balance;
            cout << "Enter name: "; cin >> name;
            cout << "Enter ID: "; cin >> id;
            cout << "Enter initial depost: "; cin >> balance;
            accounts.push_back(Account(name, id, balance));
            cout << "Account created succesfully!\n";
        }

        else if (choice == 2) {
            int id; double amount;
            cout << "Enter account ID: "; cin >> id;
            Account* acc = findAccount(accounts, id);
            if (acc) {
                cout << "Enter deposit amount: "; cin >> amount;
                acc->deposit(amount);
            } else cout << "Account not found!\n";
        }
        else if (choice == 3) {
            int id; double amount;
            cout << "Enter account ID: "; cin >> id;
            Account* acc = findAccount(accounts, id);
            if (acc) {
                cout << "Enter withdrawal amount: "; cin >> amount;
                acc->withdraw(amount);
            } else cout << "Account not found!\n";
        }
        else if (choice == 4) {
            int id;
            cout << "Enter account ID: "; cin >> id;
            Account* acc = findAccount(accounts, id);
            if (acc) acc->display();
            else cout << "Account not found!\n";
        }
        else if (choice == 5) {
            for (auto &acc : accounts) acc.display();
        }
    } while (choice != 0);

    saveAccounts(accounts, filename);
    cout << "Accounts saved. Goodbye!\n";

    return 0;
}