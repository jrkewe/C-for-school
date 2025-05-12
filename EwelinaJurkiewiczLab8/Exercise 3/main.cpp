#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    cout << "****************************************************************" << endl;
    cout << "Program wypisuje zdania oddzielone kropka w odwrotnej kolejnosci " << endl;
    cout << "****************************************************************" << endl << endl;

    //Lancuch uzytkownika
    string input;
    cout << "Wprowadz tekst oddzielony kropkami: ";
    getline(cin, input);

    //Separacja zdan
    vector <string> zdania;
    size_t poczatekZdania = 0;
    size_t pozycjaKropki = 0;
    while ((pozycjaKropki = input.find('.', poczatekZdania)) != string::npos) {
        string zdanie = input.substr(poczatekZdania, pozycjaKropki - poczatekZdania + 1);
        zdania.push_back(zdanie);
        poczatekZdania = pozycjaKropki + 1;
    }

    //Odwrotne wyswietlenie
    cout << "Tekst w odwroconej kolejnosci: ";
    for (int i = zdania.size() - 1;i >= 0;i--) {
        cout << zdania[i];
    }
    cout << endl << endl;

    cout << "Koniec programu." << endl;
    cout << "Ewelina Jurkiewicz, Gr. 5." << endl;

    return 0;
}