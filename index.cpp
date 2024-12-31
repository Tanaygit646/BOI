#include <iostream>
#include <string>
using namespace std;

class Bank {
private:
    string name;
    int accNumber;
    double balance;

public:
    void getDetails(const string &customerName, int customerAccNo, double customerBalance) {
        name = customerName;
        accNumber = customerAccNo;
        balance = customerBalance;
    }

    void setDetails() const {
        cout << "Name: " << name << "\nAccount Number: " << accNumber << "\nBalance: " << balance << "\n\n";
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Successfully deposited " << amount << ". New balance: " << balance << "\n";
        } else {
            cout << "Deposit amount must be positive.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Successfully withdrew " << amount << ". Remaining balance: " << balance << "\n";
        } else if (amount > 0) {
            cout << "Insufficient balance.\n";
        } else {
            cout << "Enter a valid amount.\n";
        }
    }

    double getBalance() const {
        return balance;
    }

    int getAccNumber() const {
        return accNumber;
    }
};

int findAccount(Bank customers[], int count, int accNo) {
    for (int i = 0; i < count; i++) {
        if (customers[i].getAccNumber() == accNo) {
            return i;
        }
    }
    return -1; 
}

int main() {
    Bank customers[100];
    int accNo = 1001;
    int count = 0;
    int choice;

    do {
        cout << "1. Create new account\n2. Deposit money\n3. Withdraw money\n4. Show all details\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            if (count >= 100) {
                cout << "Account creation limit reached.\n";
                break;
            }
            string name;
            double balance;
            cout << "Enter your name: ";
            getline(cin, name);
            cout << "Enter your initial balance: ";
            cin >> balance;

            if (balance < 0) {
                cout << "Initial balance must be non-negative.\n";
                break;
            }

            customers[count].getDetails(name, accNo, balance);
            cout << "Account created successfully. Your account number is " << accNo << ".\n";
            accNo++;
            count++;
            break;
        }
        case 2: {
            int depositAccNo;
            double amount;
            cout << "Enter your account number: ";
            cin >> depositAccNo;

            int index = findAccount(customers, count, depositAccNo);
            if (index != -1) {
                cout << "Enter deposit amount: ";
                cin >> amount;
                customers[index].deposit(amount);
            } else {
                cout << "Account number not found.\n";
            }
            break;
        }
        case 3: {
            int withdrawAccNo;
            double amount;
            cout << "Enter your account number: ";
            cin >> withdrawAccNo;

            int index = findAccount(customers, count, withdrawAccNo);
            if (index != -1) {
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                customers[index].withdraw(amount);
            } else {
                cout << "Account number not found.\n";
            }
            break;
        }
        case 4: {
            if (count == 0) {
                cout << "No accounts to display.\n";
                break;
            }
            cout << "\n--- All Account Details ---\n";
            for (int i = 0; i < count; i++) {
                customers[i].setDetails();
            }
            break;
        }
        case 5:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
