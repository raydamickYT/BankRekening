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

    friend std::ostream &operator<<(std::ostream &os, const BankRekening &rekening);

private:
    double balance;
    std::vector<Transactie> transactionHistory;
};
