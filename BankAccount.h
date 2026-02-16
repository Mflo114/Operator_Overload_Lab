/*

Name: Marcos Flores
Date: 2/15/2026
Purpose: This defines the BankAccount class structure
Assignment: Lab Activities: Advanced Objects and Classes II

*/


#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string* accountHolderName;   // The Dynamic Rule of Three
    double balance;

public:
    BankAccount();
    BankAccount(string accNum, string accHolder, double bal);

    // The Rule of Three
    BankAccount(const BankAccount& other);
    BankAccount& operator=(const BankAccount& other);
    ~BankAccount();

    // Accessors setup
    string getAccountNumber() const;
    string getAccountHolderName() const;
    double getBalance() const;

    // Operator overloads
    BankAccount& operator+=(double amount);
    BankAccount& operator-=(double amount);

    // Comparisons
    bool operator==(const BankAccount& other) const;
    bool operator<(const BankAccount& other) const;
    bool operator>(const BankAccount& other) const;

    // Static utility functions
    static void printAccount(const BankAccount& account);
    static BankAccount createAccountFromInput();
};

#endif
