#pragma once
#include <iostream>
#include <string>
#include <chrono>

class Transactie
{
public:
    Transactie(float amt, bool type)
        : amount(amt), isDeposit(type), time(std::chrono::system_clock::now()) {}

    float getAmount() const
    {
        return amount;
    }

    std::chrono::system_clock::time_point getTime() const
    {
        return time;
    }

    friend std::ostream &operator<<(std::ostream &os, const Transactie &trans)
    {
        auto t_c = std::chrono::system_clock::to_time_t(trans.time);
        os << (trans.isDeposit ? "Deposit" : "Withdrawal") << " of $" << trans.amount
           << " on " << std::ctime(&t_c); // Convert time_point to time_t, then to readable form
        return os;
    }

private:
    float amount;
    bool isDeposit;
    std::chrono::system_clock::time_point time;
};
