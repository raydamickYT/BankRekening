#pragma once
#include <SFML/Graphics.hpp>

#include "BankRekening.h"

class Transactie
{
public:
    Transactie();
    float TransactieHoeveelheid;
    float NieuweTransactie(float Input, float BankRekeningWaarde);

private:
    BankRekening rekening;
};
