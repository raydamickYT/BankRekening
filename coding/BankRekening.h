#pragma once

#include <iostream>
#include <cmath>
#include "Transactie.h"

class BankRekening {
public:
    BankRekening(double initBalance = 0.0) : balance(initBalance) {}

    // Update account balance by adding the transaction amount
    BankRekening &operator+=(const Transactie &trans);

    // Update account balance by subtracting the transaction amount
    BankRekening &operator-=(const Transactie &trans);


    // Method to update the balance, ensuring encapsulation
    void updateBalance(double amt) {
        balance += amt;
    }

    // Method to get the current balance, ensures data integrity
    double getBalance() const {
        return balance;
    }

private:
    double balance; // Balance should be private to protect data integrity
};

// Definition of the friend function outside the class
inline std::ostream &operator<<(std::ostream &os, const BankRekening &rekening) {
    os << "Current balance: " << std::ceil(rekening.getBalance() * 100) / 100;
    return os;
}