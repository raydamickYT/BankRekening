#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>

#include "BankRekening.h"
#include "OperatorOverload.h"

BankRekening::BankRekening(const std::string &d, double amt, double bal)
    : date(d), amount(amt), balance(bal)
{
}

void BankRekening::DisplayBankingInfo()
{
    // std::stringstream ss;
    // ss << std::fixed << std::setprecision(2) << balance; // Set precision to 2 decimal places
    // std::string balanceStr = ss.str();

}