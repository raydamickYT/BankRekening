#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>

#include "BankRekening.h"

BankRekening::BankRekening()
{
}

void BankRekening::Run()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game & Watch Parachute");

    while (window.isOpen())
    {
        std::cout << "test" << std::endl;
    }
}