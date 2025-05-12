#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    cout << "***********************" << endl;
    cout << "Program analizuje tekst " << endl;
    cout << "***********************" << endl << endl;

    //Tekst podany przez uzytkownika
    string input;
    cout << "Podaj tekst ktory bedzie zawieral slowo \"programowanie\" i \"C++\": ";
    getline(cin, input); 

    //Zliczanie liczby wystapien slowa "programowanie"
    string szukanyWyraz = "programowanie";

    //Konwersja na male litery
    string maleZadanie = input; 
    transform(maleZadanie.begin(), maleZadanie.end(), maleZadanie.begin(), tolower);

    //Szukanie slowa "programowanie"
    size_t i = 0;
    int count = 0;
    while ((i = maleZadanie.find(szukanyWyraz, i)) != string::npos) {
        count++;
        i += szukanyWyraz.size();
    }
    cout << "Liczba wystapien slowa \"programowanie\": " << count << endl;

    //Pierwszych 10 znakow z tekscie
    string pierwsze10znakow = input.substr(0, min(size_t(10), input.size()));
    cout << "Pierwsze 10 znakow tekstu: " << pierwsze10znakow << endl;

    //Zamiana slowa "C++" na "C++17"
    string CPlusPlus = "C++";
    string CPlusPlus17 = "C++17";
    i = 0;
    while ((i = input.find(CPlusPlus, i)) != string::npos) {
        input.replace(i, CPlusPlus.size(), CPlusPlus17);
        i += CPlusPlus17.size();
    }

    //Wyswietlenie zmodyfikowanego tekstu
    cout << "Zmodyfikowany tekst: " << input << endl << endl;

    cout << "Koniec programu." << endl;
    cout << "Ewelina Jurkiewicz, Gr. 5." << endl;

    return 0;
}
