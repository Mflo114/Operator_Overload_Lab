/*

Name: Marcos Flores
Date: 2/15/2026
Purpose: Manages the bank account functions
Assignment: Lab Activities: Advanced Objects and Classes II

*/



#include "BankAccount.h"
#include <iostream>
#include <limits>

// Constructor setups
BankAccount::BankAccount()
    : accountNumber("0000"), balance(0.0) {
    accountHolderName = new string("Unknown");
}

BankAccount::BankAccount(string accNum, string accHolder, double bal)
    : accountNumber(accNum), balance(bal) {
    accountHolderName = new string(accHolder);
}

// The Rule of Three
BankAccount::BankAccount(const BankAccount& other) {
    accountNumber = other.accountNumber;
    balance = other.balance;
    accountHolderName = new string(*other.accountHolderName);
}

BankAccount& BankAccount::operator=(const BankAccount& other) {
    if (this != &other) {
        delete accountHolderName;
        accountNumber = other.accountNumber;
        balance = other.balance;
        accountHolderName = new string(*other.accountHolderName);
    }
    return *this;
}

BankAccount::~BankAccount() {
    delete accountHolderName;
}

// Accessors
string BankAccount::getAccountNumber() const {
    return accountNumber;
}

string BankAccount::getAccountHolderName() const {
    return *accountHolderName;
}

double BankAccount::getBalance() const {
    return balance;
}

// Operator overloads setup
BankAccount& BankAccount::operator+=(double amount) {
    if (amount > 0) {
        balance += amount;
    }
    return *this;
}

BankAccount& BankAccount::operator-=(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
    }
    return *this;
}

// Comparisons
bool BankAccount::operator==(const BankAccount& other) const {
    return accountNumber == other.accountNumber;
}

bool BankAccount::operator<(const BankAccount& other) const {
    return balance < other.balance;
}

bool BankAccount::operator>(const BankAccount& other) const {
    return balance > other.balance;
}

// Static utility functions
void BankAccount::printAccount(const BankAccount& account) {
    cout << "Account Number: " << account.accountNumber << endl;
    cout << "Account Holder: " << *account.accountHolderName << endl;
    cout << "Balance: $" << account.balance << endl;
}

BankAccount BankAccount::createAccountFromInput() {
    string accNum, name;
    double bal;

    cout << "Enter account number: ";
    getline(cin, accNum);

    cout << "Enter account holder name: ";
    getline(cin, name);

    cout << "Enter initial balance: ";
    cin >> bal;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return BankAccount(accNum, name, bal);
}
