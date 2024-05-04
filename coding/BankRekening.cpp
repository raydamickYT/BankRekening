#include "BankRekening.h" 
#include <iostream>       

// Implement the addition operator to handle deposit transactions
BankRekening &BankRekening::operator+=(const Transactie &trans)
{
    balance += trans.amount; // Add the transaction amount to the balance
    return *this;            // Return the current object to allow chaining
}

// Implement the subtraction operator to handle withdrawal transactions
BankRekening &BankRekening::operator-=(const Transactie &trans)
{
    balance -= trans.amount; // Subtract the transaction amount from the balance
    return *this;            // Return the current object to allow chaining
}

