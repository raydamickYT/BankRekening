#include <iostream>
#include <random>
#include <chrono>
#include <sstream>
#include <SFML/Graphics.hpp>

#include "Transactie.h"
Transactie::Transactie()
{
}

float Transactie::NieuweTransactie(float Input, float BankRekeningWaarde)
{
    //bewaar de oude balance en maak alvast een nieuw balans
    double NewSaldo = rekening.balance + Input;

    //tijd
    auto now = std::chrono::system_clock::now();

    std::time_t readable_Time = std::chrono::system_clock::to_time_t(now);
    
    //toevoegen aan mn lijst van transacties.
    rekening.RekeningInfo.emplace_back(std::ctime(&readable_Time), Input, NewSaldo);
   
    const auto& mostRecentTransaction = rekening.RekeningInfo.back();

    std::stringstream AccountInfo;
    AccountInfo << "\nRecent Transaction: \n" << "Date: " << mostRecentTransaction.date  << std::endl
    << "Balance before transaction: " << rekening.balance << std::endl
    << "Balance after transaction: " << mostRecentTransaction.balance << std::endl
    << "Transaction amount: " << mostRecentTransaction.amount << std::endl;

    std::cout << AccountInfo.str() << std::endl;

    rekening.balance += Input;
    return NewSaldo;
}