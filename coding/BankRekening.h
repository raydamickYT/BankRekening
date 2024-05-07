#pragma once

#include <vector>
#include <chrono>
#include <iostream>
#include <cmath>
#include "Transactie.h"

class BankRekening
{
public:
    BankRekening(double initBalance = 0.0) : balance(initBalance) {}

    // Update account balance by adding the transaction amount and recording the transaction
    BankRekening &operator+=(const Transactie &trans);

    // Update account balance by subtracting the transaction amount and recording the transaction
    BankRekening &operator-=(const Transactie &trans);

    void updateBalance(double amt);
    double getBalance() const;
    std::vector<Transactie> getTransactionHistory() const;


private:
    double balance; // Balance should be private to protect data integrity
    std::vector<Transactie> transactionHistory;
};

// Definition of the friend function outside the class
inline std::ostream &operator<<(std::ostream &os, const BankRekening &rekening)
{
    os << "Current balance: " << std::ceil(rekening.getBalance() * 100) / 100;
    for (const auto &trans : rekening.getTransactionHistory())
    {
        os << "\nTransaction: " << trans; // Assuming Transactie has an overloaded << operator
    }
    return os;
}