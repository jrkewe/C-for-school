#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

//Funckja oblicza liczbe slow w tekscie
int liczSlowa(const string& tresc) {
    stringstream ss(tresc);
    string slowo;
    int licznik = 0;

    //Iteracja przez kazde slowo w strumieniu
    while (ss >> slowo) {
        licznik++;
    }

    return licznik;
}

//Funckja oblicza liczbe zdan w tekscie
int liczZdania(const string& tresc) {
    return count_if(tresc.begin(), tresc.end(), [](char znak) {
        return znak == '.' || znak == '!' || znak == '?';
        });
}

//Funkcja liczy srednia dlugosc slow w tekscie
float sredniaDlugoscSlowa(const string& tresc) {

    stringstream ss(tresc);
    string slowo;
    int liczbaSlow = 0;
    int sumaDlugosci = 0;

    //Iteracja przez kazde slowo w tekscie
    while (ss >> slowo) {
        sumaDlugosci += slowo.length();
        liczbaSlow++;
    }

    //Srednia dlugosc slowa
    return static_cast<float>(sumaDlugosci)/liczbaSlow;
}

//Funkcja mapujaca ilosc wystapien danego slowa
map<string,int> analizaCzestotliwosciSlow(const string& tresc) {
    map<string,int> czestotliwosc;
    stringstream ss(tresc);
    string slowo;

    while (ss >> slowo) {
        //Usuwanie znakow interpunkcyjnych
        slowo.erase(remove_if(slowo.begin(), slowo.end(), ::ispunct), slowo.end());

        //Konwersja na male litery
        transform(slowo.begin(), slowo.end(), slowo.begin(), ::tolower);

        //Zwiekszanie liczby wystapien slowa
        czestotliwosc[slowo]++;
    }

    return czestotliwosc;
}

//Funkcja wyswietla slowa wystepujace w tekscie czesciej niz zadany prog
void wystapieniaSlowPonadZadanyProg(const map<string, int>& czestotliwosc, int prog) {
    //Przeniesienie elementow mapy do wektora
    vector<pair<string, int>> sortedWords(czestotliwosc.begin(), czestotliwosc.end());

    //Sortowanie malejaco wg ilosci wystapien
    sort(sortedWords.begin(), sortedWords.end(), [](const auto& a, const auto& b) {
        return a.second > b.second; 
        });

    //Wyswietlenie elementow wystepujacych czesciej niz zadany prog
    cout << "Slowa wystepujace wiecej niz " << prog << " razy:" << endl;
    for_each(sortedWords.begin(), sortedWords.end(), [prog](const auto& element) {
        if (element.second > prog) {
            cout << element.first << ": " << element.second << endl;
        }
        });
}

int main() {
    cout << "***********************" << endl;
    cout << "Program analizuje tekst " << endl;
    cout << "***********************" << endl << endl;

    //Plik tekstowy z folderu projektu
    string sciezkaDostepowaPliku = "tekst do analizy.txt";

    //Sprawdzenie poprawnosci odczytu
    ifstream plikTekstowy(sciezkaDostepowaPliku);
    if (!plikTekstowy) {
        cout << "Nie mozna otworzyc pliku: " << sciezkaDostepowaPliku << endl;
        return 1;
    }
    
    //Zapisywanie tekstu
    string linia, tresc;
    while (getline(plikTekstowy, linia)) {
        tresc += linia + "\n"; 
    }
    plikTekstowy.close();

    cout << "Pobrany tekst:" << endl;
    cout << tresc << endl;

    //Przetwarzanie tekstu
    cout << "Liczba slow w tekscie: " << liczSlowa(tresc) << endl << endl;

    cout << "Liczba zdan w tekscie: " << liczZdania(tresc) << endl << endl;

    cout << "Srednia dlugosc slowa: " << sredniaDlugoscSlowa(tresc) << endl << endl;

    map<string, int> czestotliwosc = analizaCzestotliwosciSlow(tresc);

    cout << "Wyniki czestotliwosci wystepowania w kolejnosci malejacej: " << endl;
    wystapieniaSlowPonadZadanyProg(czestotliwosc, 3);
    cout << endl;
    
    cout << "Koniec programu." << endl;
    cout << "Ewelina Jurkiewicz, Gr. 5." << endl;
    return 0;
}

