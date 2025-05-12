#pragma once
#include <string>

class Aktywo {
protected:
    double ilosc;       // Liczba jednostek aktywa
    double nowaCena;    // Aktualna cena aktywa

public:
    // Konstruktor
    Aktywo(double liczba, double cena) : ilosc(liczba), nowaCena(cena) {}

    // Wirtualny destruktor
    virtual ~Aktywo() {}

    // Wirtualna metoda zwracajaca wartosc aktywa
    virtual double obliczWartosc() const = 0;

    // Wirtualna metoda zwracajaca opis aktywa
    virtual std::string opis() const = 0;

    // Getter dla nowej ceny
    virtual double getNowaCena() const {
        return nowaCena;
    }

    // Setter dla nowej ceny
    virtual void setNowaCena(double cena) {
        nowaCena = cena;
    }

    // Getter dla ilosci
    double getIlosc() const {
        return ilosc;
    }
};