#pragma once
#include <iostream>
#include <random>
#include "TablicaSzablonowa.h"
#include "GeneratorLiczb.h"
using namespace std;

//Funkcja znajdujaca maksymalny element
template <typename T>
const T maksymalnyElement(const TablicaSzablonowa<T>& array, int rozmiar) 
{
    T* tablica = array.getArray();

    if (rozmiar == 0) {
        cout << "Tablica jest pusta.";
    }

    //Sortowanie
    T maksymalny = tablica[0];
    for (int i = 1; i < rozmiar; i++) 
    {
        if (tablica[i] > maksymalny) 
        {
            maksymalny = tablica[i];
        }
    }
    return maksymalny;
}

//Losowe wartosci
int randomTyp;
int randomSize;

int main() {
    cout << "***********************************************" << endl;
    cout << "Program demonstruje uzycie funkcji szablonowych" << endl;
    cout << "***********************************************" << endl << endl;

    //Losowa liczba dla typu: 0-int ,1-float ,2-bool ,3-char ,4-string
    randomTyp = generujLosowaWartosc(0,4);
    //Losowa liczba dla rozmiaru
    randomSize = generujLosowaWartosc(5, 10);


    //Tworzenie tablicy o losowym typie i rozmiarze
    switch (randomTyp) {
        case 0: 
        {
            cout << "Wylosowany typ tablicy: int" << endl << endl;
            TablicaSzablonowa<int> tablica(randomSize);
            tablica.specializedMethodUzupelnienie();
            tablica.wyswietl();
            cout << "Funkcja szablonowa przyjmuje jako argument tablice dowolnego" << endl;
            cout << "typu i rozmiaru, a nastepnie zwraca jej element maksymalny." << endl << endl;

            cout << "Maksymalny element: " << maksymalnyElement(tablica, tablica.getSize()) << endl;
            break;
        }
        case 1: 
        {
            cout << "Wylosowany typ tablicy: float" << endl << endl;
            TablicaSzablonowa<float> tablica(randomSize);
            tablica.specializedMethodUzupelnienie();
            tablica.wyswietl();
            cout << "Funkcja szablonowa przyjmuje jako argument tablice dowolnego" << endl;
            cout << "typu i rozmiaru, a nastepnie zwraca jej element maksymalny." << endl << endl;

            cout << "Maksymalny element: " << maksymalnyElement(tablica, tablica.getSize()) << endl;
            break;
        }
        case 2: 
        {
            cout << "Wylosowany typ tablicy: bool" << endl << endl;
            TablicaSzablonowa<bool> tablica(randomSize);
            tablica.specializedMethodUzupelnienie();
            tablica.wyswietl();
            cout << "Funkcja szablonowa przyjmuje jako argument tablice dowolnego" << endl;
            cout << "typu i rozmiaru, a nastepnie zwraca jej element maksymalny." << endl << endl;

            cout << "Maksymalny element: " << maksymalnyElement(tablica, tablica.getSize()) << endl;
            break;
        }
        case 3: 
        {
            cout << "Wylosowany typ tablicy: char" << endl << endl;
            TablicaSzablonowa<char> tablica(randomSize);
            tablica.specializedMethodUzupelnienie();
            tablica.wyswietl();
            cout << "Funkcja szablonowa przyjmuje jako argument tablice dowolnego" << endl;
            cout << "typu i rozmiaru, a nastepnie zwraca jej element maksymalny." << endl << endl;

            cout << "Maksymalny element: " << maksymalnyElement(tablica, tablica.getSize()) << endl;
            break;
        }
        case 4: 
        {
            cout << "Wylosowany typ tablicy: string" << endl << endl;
            TablicaSzablonowa<string> tablica(randomSize);
            tablica.specializedMethodUzupelnienie();
            tablica.wyswietl();
            cout << "Funkcja szablonowa przyjmuje jako argument tablice dowolnego" << endl;
            cout << "typu i rozmiaru, a nastepnie zwraca jej element maksymalny." << endl << endl;

            cout << "Maksymalny element: " << maksymalnyElement(tablica, tablica.getSize()) << endl;
            break;
        }
        default:
            cout << "Nieprawidlowy typ!" << endl;
            break;
    }

    cout << endl << "Koniec programu." << endl;
    cout << "Ewelina Jurkiewicz, Gr. 5." << endl;

    return 0;
}
