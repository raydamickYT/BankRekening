#include "BankRekening.h"
#include <iostream>


BankRekening &BankRekening::operator+=(const Transactie &trans)
{
    updateBalance(trans.getAmount()); 
    transactionHistory.push_back(trans);
    return *this;
}

BankRekening &BankRekening::operator-=(const Transactie &trans)
{
    updateBalance(-trans.getAmount()); 
    transactionHistory.push_back(trans);
    return *this;
}

void BankRekening::updateBalance(double amt)
{
    balance += amt;
}

double BankRekening::getBalance() const
{
    return balance;
}

std::vector<Transactie> BankRekening::getTransactionHistory() const
{
    return transactionHistory;
}

std::ostream &operator<<(std::ostream &os, const BankRekening &rekening)
{
    os << "Current balance: " << std::ceil(rekening.getBalance() * 100) / 100;
    for (const auto &trans : rekening.getTransactionHistory())
    {
        os << "\nTransaction: " << trans;
    }
    return os;
}