#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include "Aktywo.h"


class PortfelInwestycyjny {
private:
    std::vector<Aktywo*> aktywa;

public:
    // Konstruktor i destruktor
    PortfelInwestycyjny() = default;
    ~PortfelInwestycyjny();

    // Dodanie aktywa do portfela
    void dodajAktywo(Aktywo* aktywo);

    // Obliczenie lacznej wartosci portfela
    double obliczLacznaWartosc() const;

    // Sortowanie aktywow wedlug wartosci
    void sortujAktywaWedlugWartosci();

    // Filtrowanie aktywow wedlug wzrostu ceny (np. > 5%)
    void filtrowanieAkcji(double procentWzrostu) const;

    // Wyswietlenie wszystkich aktywow
    void wyswietlAktywa() const;
};
