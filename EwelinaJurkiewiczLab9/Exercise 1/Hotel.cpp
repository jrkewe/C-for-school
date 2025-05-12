#pragma once
#include <iostream>
#include <algorithm>
#include "Hotel.h"
#include "Pokoj.h"
#include "Apartament.h"
using namespace std;

//Metoda dodajaca nowa rezerwacje
void Hotel::tworzenieRezerwacji(Pokoj* pokoj){

    //Nowy klucz rezerwacji
    int nowyKlucz = 0;
    if (!rezerwacje.empty()) {
        nowyKlucz = rezerwacje.rbegin()->first + 1;
    }

    //Dodawanie rezerwacji
    rezerwacje[nowyKlucz] = pokoj;
}

//Metoda usuwajaca rezerwacje na podstawie numeru
void Hotel::usuwanieRezerwacjiPoNumerze(int numer) {

    //Usuniecie rezerwacji pokoju
    auto i = rezerwacje.find(numer);
    if (i != rezerwacje.end()) {
        // Jesli istnieje, usuwamy ja
        rezerwacje.erase(i);
        cout << "Rezerwacja o kluczu " << numer << " zostala usunieta." << endl;
    }
    else {
        // Jesli nie istnieje, wyswietlamy komunikat
        cout << "Rezerwacja o kluczu " << numer << " nie istnieje." << endl;
    }

}

//Metoda wyswietlajaca wszystkie rezerwacje
void Hotel::wyswietlenieWszystkichRezerwacji() {
    cout << "Rezerwacje: " << endl;

    if (rezerwacje.empty()) {
        cout << "Brak rezerwacji." << endl;
        return;
    }

    for (const auto& element : rezerwacje) { 
        cout << "Rezerwacja: " << element.first << endl;
        element.second->opis(); 
    }
}

//Metoda zwracajaca liczbe zarezerwowanych apartamentow
int Hotel::getApartmentsCount() {

    return static_cast<int>(count_if(rezerwacje.begin(), rezerwacje.end(),
        [](const auto& element) {
            return dynamic_cast<Apartament*>(element.second) != nullptr;
        }));
}

//Metoda zwracajaca najtanszy dostepny pokoj
Pokoj* Hotel::getNajtanszyPokoj() {

    if (rezerwacje.empty()) {
        cout << "Brak rezerwacji." << endl;
    }

    //Przechodzenie przez wszystkie rezerwacje
    auto najtanszy = min_element(rezerwacje.begin(), rezerwacje.end(),
        [](const auto& a, const auto& b) {
            return a.second->getCena() < b.second->getCena();
        });

    cout << najtanszy->second->opis();
    return najtanszy->second;
}