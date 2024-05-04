#pragma once
#include <SFML/Graphics.hpp>

class Transactie
{
public:
    Transactie();
    float amount; // Amount of the transaction
    bool isDeposit; // True if deposit, false if withdrawal
    Transactie(float amt, bool type) : amount(amt), isDeposit(type) {}};
