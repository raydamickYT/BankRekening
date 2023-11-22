#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>

#include "BankRekening.h"

int main()
{
    bool isRunning = true;
    // BankRekening Rekening;

    // Rekening.Run();
    while (isRunning)
    {
        std::string input;
        std::cout << "Enter your text: ";
        std::getline(std::cin, input);
        std::cout << "You entered: " << input << std::endl;
    }
    return 0;
}