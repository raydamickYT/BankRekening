#include "BankRekening.h"
#include <iostream>

// Implement the addition operator to handle deposit transactions
BankRekening &BankRekening::operator+=(const Transactie &trans)
{
    updateBalance(trans.getAmount()); // Assuming Transactie has getAmount() to return the transaction amount
    transactionHistory.push_back(trans);
    return *this;
}

// Implement the subtraction operator to handle withdrawal transactions
BankRekening &BankRekening::operator-=(const Transactie &trans)
{
    updateBalance(-trans.getAmount()); // Assuming Transactie has getAmount() to return the transaction amount
    transactionHistory.push_back(trans);
    return *this;
}

// Method to update the balance, ensuring encapsulation
void BankRekening::updateBalance(double amt)
{
    balance += amt;
}

// Method to get the current balance, ensures data integrity
double BankRekening::getBalance() const
{
    return balance;
}
// Optional: Method to get transaction history
std::vector<Transactie> BankRekening::getTransactionHistory() const
{
    return transactionHistory;
}
