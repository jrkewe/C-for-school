#include "PortfelInwestycyjny.h"
#include "Akcja.h"
#include "Obligacja.h"

int main() {
    PortfelInwestycyjny portfel;

    // Dodanie aktywow do portfela
    portfel.dodajAktywo(new Akcja(5, 100));   // 5 akcji po 100 jednostek
    portfel.dodajAktywo(new Akcja(10, 50));   // 10 akcji po 50 jednostek
    portfel.dodajAktywo(new Obligacja(3, 200)); // 3 obligacje po 200 jednostek

    // Wyswietlenie aktywow
    std::cout << "Aktywa w portfelu:\n";
    portfel.wyswietlAktywa();

    // Obliczenie lacznej wartosci portfela
    std::cout << "\nLaczna wartosc portfela: " << portfel.obliczLacznaWartosc() << "\n";

    // Sortowanie aktywow
    portfel.sortujAktywaWedlugWartosci();
    std::cout << "\nAktywa po posortowaniu:\n";
    portfel.wyswietlAktywa();

    // Filtrowanie akcji
    std::cout << "\nFiltrowanie akcji z wzrostem ceny > 5%:\n";
    portfel.filtrowanieAkcji(5.0);

    return 0;
}
