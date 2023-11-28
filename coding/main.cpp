#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <cmath>

#include "BankRekening.h"
#include "Transactie.h"
int main()
{
    bool isRunning = true;

    // BankRekening Rekening;
    Transactie Transactie;

    // Rekening.Run();
    while (isRunning)
    {
        float input;
        std::cout << "Enter your transaction amount: ";
        // std::getline(std::cin, input);
        while (!(std::cin >> input))
        {
            std::cout << "You entered tekst. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
        }

        double NewSaldo = Transactie.NieuweTransactie(input, 0);
        std::cout << "New saldo: " << std::ceil(NewSaldo * 100) / 100 << std::endl;
    }
    return 0;
}