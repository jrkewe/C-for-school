#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    cout << "******************************************" << endl;
    cout << "Program formatuje wielkosc liter w tekscie " << endl;
    cout << "******************************************" << endl << endl;

    //Lancuch uzytkownika
    string input;
    cout << "Podaj tekst ze zle sformatowana wielkoscia liter: ";
    getline(cin, input);

    //Mapowanie tekstu
    map <char, int> mapaZnakow;

    //Formatowanie wielkosci liter
    bool poczatekZdania = true;

    for (int i=0; i < input.size(); i++) {
        char& litera = input[i];

        if (poczatekZdania && isalpha(litera)) {
            litera = toupper(litera);
            poczatekZdania = false;
        }
        else {
            litera = tolower(litera);
        }

        //Nowe zdanie
        if (litera == '.' || litera == '!' || litera == '?') {
            poczatekZdania = true;
        }
    }

    //Wyswietlenie zmodyfikowanego tekstu
    cout << "Sformatowany tekst: " << endl;
    cout << input << endl << endl;

    cout << "Koniec programu." << endl;
    cout << "Ewelina Jurkiewicz, Gr. 5." << endl;

    return 0;
}