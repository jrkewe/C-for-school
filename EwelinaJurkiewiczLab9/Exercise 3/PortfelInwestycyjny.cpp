#include "PortfelInwestycyjny.h"
#include "Akcja.h"
#include "Obligacja.h"


// Destruktor
PortfelInwestycyjny::~PortfelInwestycyjny() {
    for (auto aktywo : aktywa) {
        delete aktywo;
    }
}

// Dodanie aktywa do portfela
void PortfelInwestycyjny::dodajAktywo(Aktywo* aktywo) {
    aktywa.push_back(aktywo);
}

// Obliczenie lacznej wartosci portfela
double PortfelInwestycyjny::obliczLacznaWartosc() const {
    double suma = 0;
    for (const auto& aktywo : aktywa) {
        suma += aktywo->obliczWartosc();
    }
    return suma;
}

// Sortowanie aktywow wedlug wartosci
void PortfelInwestycyjny::sortujAktywaWedlugWartosci() {
    std::sort(aktywa.begin(), aktywa.end(), [](const Aktywo* a, const Aktywo* b) {
        return a->obliczWartosc() > b->obliczWartosc();
        });
}

// Filtrowanie aktywow wedlug wzrostu ceny
void PortfelInwestycyjny::filtrowanieAkcji(double procentWzrostu) const {
    std::cout << "Aktywa, ktorych cena wzrosla o wiecej niz " << procentWzrostu << "%:\n";
    for (const auto& aktywo : aktywa) {
        if (auto* akcja = dynamic_cast<const Akcja*>(aktywo)) {
            double wzrost = (akcja->getNowaCena() - akcja->getNowaCena() / 1.1) * 100; // Przykladowy wzrost
            if (wzrost > procentWzrostu) {
                std::cout << akcja->opis() << std::endl;
            }
        }
    }
}


// Wyswietlenie wszystkich aktywow
void PortfelInwestycyjny::wyswietlAktywa() const {
    for (const auto& aktywo : aktywa) {
        std::cout << aktywo->opis() << std::endl;
    }
}
