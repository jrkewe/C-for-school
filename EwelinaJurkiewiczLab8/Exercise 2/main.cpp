#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    cout << "*******************************************" << endl;
    cout << "Program sprawdza czy wyraz jest palindromem " << endl;
    cout << "*******************************************" << endl << endl;

    //Lancuch uzytkownika
    string input;
    cout << "Wprowadz palindrom: ";
    getline(cin, input);

    //Konwersja na male litery
    string malyInput = input;
    transform(malyInput.begin(), malyInput.end(), malyInput.begin(), tolower);

    //Sprawdzanie czy ciag jest palindromem
    string reversed = malyInput;
    reverse(reversed.begin(), reversed.end()); 

    if (malyInput == reversed) {
        cout << "Podany wyraz jest palindromem." << endl << endl;
    }
    else {
        cout << "Podany wyraz nie jest palindromem." << endl << endl;
    }

    cout << "Koniec programu." << endl;
    cout << "Ewelina Jurkiewicz, Gr. 5." << endl;

    return 0;
}