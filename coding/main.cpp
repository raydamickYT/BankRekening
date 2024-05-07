#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include <chrono>

#include "BankRekening.h"
#include "Transactie.h"

int main()
{
    BankRekening rekening;
    std::string type;
    bool continueTransaction = true;
    std::string input;

    while (continueTransaction)
    {
        std::cout << "Is this a deposit or a withdrawal? (d/w): ";
        std::cin >> type;
        while (type != "d" && type != "w")
        {
            std::cout << "Invalid input. Please enter 'd' for deposit or 'w' for withdrawal: ";
            std::cin >> type;
        }

        std::cout << "Enter your transaction amount: ";
        float amount;
        while (!(std::cin >> amount) || amount < 0)
        {
            std::cout << "Invalid amount. Please enter a positive number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        bool isDeposit = (type == "d");
        Transactie transaction(amount, isDeposit);

        if (isDeposit)
            rekening += transaction;  // Use the += operator for deposits
        else
            rekening -= transaction;  // Use the -= operator for withdrawals


        std::cout << rekening << std::endl; // printing the full transaction + transaction history

        std::cout << "Do you want to perform another transaction? (yes/no): ";
        std::cin >> input;
        continueTransaction = (input == "yes");
    }

    std::cout << "Final balance: " << rekening << std::endl;
    return 0;
}
