#pragma once
#include "Aktywo.h"
#include <string>
#include <cmath>

class Obligacja : public Aktywo {
public:
    // Konstruktor
    Obligacja(double liczba, double cena) : Aktywo(liczba, cena) {}

    // Implementacja obliczania wartosci
    double obliczWartosc() const override {
        return ilosc * nowaCena;
    }

    // Implementacja opisu obligacje
    std::string opis() const override {

        //ilosc
        double iloscZaokraglona = round(ilosc * 100) / 100;
        string iloscString = to_string(iloscZaokraglona);

        //Znajdz pozycje kropki i przytnij ciag do dwoch miejsc po przecinku
        size_t dotPos = iloscString.find('.');
        if (dotPos != string::npos) {
            iloscString = iloscString.substr(0, dotPos + 3);
        }

        //nowacena
        double nowaCenaZaokraglona = round(nowaCena * 100) / 100;
        string nowaCenaString = to_string(nowaCenaZaokraglona);

        //Znajdz pozycje kropki i przytnij ciag do dwoch miejsc po przecinku
        dotPos = nowaCenaString.find('.');
        if (dotPos != string::npos) {
            nowaCenaString = nowaCenaString.substr(0, dotPos + 3);
        }

        //wartosc
        double wartosc = obliczWartosc();
        double wartoscZaokraglona = round(wartosc * 100) / 100;
        string wartoscString = to_string(wartoscZaokraglona);

        //Znajdz pozycje kropki i przytnij ciag do dwoch miejsc po przecinku
        dotPos = wartoscString.find('.');
        if (dotPos != string::npos) {
            wartoscString = wartoscString.substr(0, dotPos + 3);
        }



        return "Obligacja: liczba jednostek = " + iloscString +
            ", cena jednostkowa = " + nowaCenaString +
            ", wartosc = " + wartoscString;
    }
};