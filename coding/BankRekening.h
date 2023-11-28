#pragma once
#include <SFML/Graphics.hpp>
#include <list>

class BankRekening
{
public:
BankRekening() : date(""), amount(0.0), balance(0.0){}
    BankRekening(const std::string &d, double amt, double bal);
    
    void DisplayBankingInfo();
    std::list<int> TransactieGeschiedenis;
    double balance, amount;
    std::vector<BankRekening> RekeningInfo;
    std::string date;
    
private:
};
