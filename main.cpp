/*

Name: Marcos Flores
Date: 2/15/2026
Purpose: It runs the bank account program
Assignment: Lab Activities: Advanced Objects and Classes II

*/


#include <iostream>
#include <vector>
#include <limits>
#include "BankAccount.h"

using namespace std;

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

int main() {
    vector<BankAccount> accounts;
    int userInput;


    // Main menu
    do {
        cout << "--> Bank Account Management <--" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Display All Accounts" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose a number: ";
        cin >> userInput;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');


        // Actions for each option chosen in menu
        switch (userInput) {
        case 1:
            accounts.push_back(BankAccount::createAccountFromInput());
            cout << "Account created successfully!" << endl;
            break;

        case 2: {
            string accNum;
            cout << "Enter account number to deposit into: ";
            getline(cin, accNum);

            bool found = false;
            for (auto& acc : accounts) {
                if (acc.getAccountNumber() == accNum) {
                    double amount = getValidatedAmount("Enter deposit amount: ");
                    acc += amount;
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
            for (auto& acc : accounts) {
                if (acc.getAccountNumber() == accNum) {
                    double amount = getValidatedAmount("Enter withdrawal amount: ");
                    acc -= amount;
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Account not found!" << endl;
            break;
        }

        case 4:
            if (accounts.empty()) {
                cout << "No accounts to display." << endl;
            } else {
                for (const auto& acc : accounts) {
                    BankAccount::printAccount(acc);
                    cout << "----------------------" << endl;
                }
            }
            break;

        case 5:
            cout << "Quitting the program. See you later!" << endl;
            break;

        default:
            cout << "Wrong choice. Try again." << endl;
        }
    } while (userInput != 5);

    return 0;
}
