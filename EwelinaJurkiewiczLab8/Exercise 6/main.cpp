#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    cout << "************************************" << endl;
    cout << "Program modyfikuje rozszerzenie plik" << endl;
    cout << "************************************" << endl << endl;

    //Lancuch uzytkownika
    string input;
    cout << "Podaj nazwe pliku z rozszerzeniem: ";
    getline(cin, input);

    string nazwaPliku;
    string rozszerzenie;

    //Podzial na nazwe i rozszerzenie
    int pozycjaKropki = 0;
    pozycjaKropki = input.find_last_of('.');

    nazwaPliku = input.substr(0, pozycjaKropki);        
    rozszerzenie = input.substr(pozycjaKropki + 1);

    //Wyswietlenie nazwy i rozszerzenia
    cout << "Nazwa pliku: " << nazwaPliku << endl;
    cout << "Rozszerzenie: " << rozszerzenie << endl;

    //Jesli rozszerzenie .cpp zamiana na .h
    if (rozszerzenie == "cpp") {
        rozszerzenie = "h";
        nazwaPliku = nazwaPliku + "." + rozszerzenie; 
        cout << "Zmodyfikowana nazwa pliku: " << nazwaPliku << endl << endl;
    }
    else {
        nazwaPliku = nazwaPliku + "." + rozszerzenie;
        cout << "Rozszerzenie pliku to nie .cpp. Brak zmian: " << nazwaPliku << endl << endl;
    }

    cout << "Koniec programu." << endl;
    cout << "Ewelina Jurkiewicz, Gr. 5." << endl;

    return 0;
}