#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    cout << "***************************************" << endl;
    cout << "Program liczy unikalne znaki w lancuchu " << endl;
    cout << "***************************************" << endl << endl;

    //Lancuch uzytkownika
    string input;
    cout << "Podaj dowlony tekst: ";
    getline(cin, input);

    //Mapowanie tekstu
    map <char, int> mapaZnakow;

    //Dodawanie elementow do mapy
    for (char litera : input) {
        char malaLitera = tolower(litera);
        mapaZnakow[malaLitera]++;
    }

    //Liczba unikalnych znakow
    cout << "Liczba unikalnych znakow: " << mapaZnakow.size() << endl;

    //Znaki w porzadku alfabetycznym
    cout << "Unikalne znaki w alfabetycznym porzadku: ";
    for (auto element : mapaZnakow) {
        cout << element.first << " ";
    }
    cout << endl << endl;

    cout << "Koniec programu." << endl;
    cout << "Ewelina Jurkiewicz, Gr. 5." << endl;

    return 0;
}