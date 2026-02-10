/*

Name: Marcos Flores
Date: 2/4/2026
Purpose: Manages your bank account
Assignment: Lab Activities: Objects and Classes I

*/
#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    // The constructor
    BankAccount() : accountNumber("0000"), accountHolderName("Unknown"), balance(0.0) {}

    // Parameterized constructor
    BankAccount(string accNum, string accHolder, double bal)
        : accountNumber(accNum), accountHolderName(accHolder), balance(bal) {}

    // Accessors
    string getAccountNumber() const { return accountNumber; }
    string getAccountHolderName() const { return accountHolderName; }
    double getBalance() const { return balance; }

    // Mutator for the account holder name
    void setAccountHolderName(const string& name) { accountHolderName = name; }

    // Deposite
    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Your deposit amount must be positive." << endl;
            return;
        }
        balance += amount;
        cout << "Deposited $" << amount << " successfully." << endl;
    }

    // Withdraw
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Your withdrawal amount must be positive." << endl;
            return;
        }
        if (amount > balance) {
            cout << "Not sufficient funds! Withdrawal canceled." << endl;
            return;
        }
        balance -= amount;
        cout << "Withdrew $" << amount << " successfully." << endl;
    }

    // Shows details of accounts
    void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: $" << balance << endl;;
    }
};

// Helper function
double getValidatedAmount(const string& prompt) {
    double amount;
    while (true) {
        cout << prompt;
        if (cin >> amount) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return amount;
        } else {
            cout << "That's the wrong input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// The main menu options
int main() {
    vector<BankAccount> accounts;
    int userInput;

    do {
        cout << "--> Bank Account Management <--" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Display All Accounts" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose a number: " << endl;
        cin >> userInput;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (userInput) {
            case 1: {
                string accNum, name;
                double bal;
                cout << "Enter account number: ";
                getline(cin, accNum);
                cout << "Enter account holder name: ";
                getline(cin, name);
                bal = getValidatedAmount("Enter initial balance: ");
                accounts.push_back(BankAccount(accNum, name, bal));
                cout << "Account created successfully!" << endl;
                break;
            }
            case 2: {
                string accNum;
                cout << "Enter account number to deposit into: ";
                getline(cin, accNum);
                bool found = false;
                for (auto &acc : accounts) {
                    if (acc.getAccountNumber() == accNum) {
                        double amount = getValidatedAmount("Enter deposit amount: ");
                        acc.deposit(amount);
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Account not found!" << endl;
                break;
            }
            case 3: {
                string accNum;
                cout << "Enter account number to withdraw from: ";
                getline(cin, accNum);
                bool found = false;
                for (auto &acc : accounts) {
                    if (acc.getAccountNumber() == accNum) {
                        double amount = getValidatedAmount("Enter withdrawal amount: ");
                        acc.withdraw(amount);
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Account not found!" << endl;
                break;
            }
            case 4: {
                if (accounts.empty()) {
                    cout << "No accounts to display." << endl;
                } else {
                    for (const auto &acc : accounts) {
                        acc.display();
                        cout << "----------------------" << endl;
                    }
                }
                break;
            }
            case 5:
                cout << "Quitting the program. See you later!" << endl;
                break;
            default:
                cout << "Wrong choice. Try again." << endl;
        }
    } while (userInput != 5);

    return 0;
}
