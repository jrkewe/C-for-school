#pragma once
#include <iostream>
#include <random>
#include "GeneratorLiczb.h"
using namespace std;

//Klasa szablonowa tablic
template <typename T>
class TablicaSzablonowa {
    T* tablica;
    int rozmiar;

public:
    //Konstruktor
    TablicaSzablonowa(int wielkosc) : rozmiar(wielkosc) {
        tablica = new T[rozmiar];
    }

    //Funkcja wypelniajaca tablice
    void specializedMethodUzupelnienie() {
        for (int i = 0; i < rozmiar; i++) {
            tablica[i] = static_cast<T>(i);
        }
    }

    //Getter dla rozmiaru
    int getSize() const {
        return rozmiar;
    }

    //Getter dla tablicy
    T* getArray() const {
        return tablica;
    }

    //Wyswietlenie tablicy
    void wyswietl() const {

        cout << "Wygenerowane elementy tablicy:" << endl << endl;
        for (int i = 0; i < rozmiar; i++)
        {
            cout << "Element[" << i << "]:  " << tablica[i] << endl;
        }
        cout << endl;
    }
};

//Specjalizacja metody specializedMethodUzupelnienie() dla typu int
template <>
void TablicaSzablonowa <int>::specializedMethodUzupelnienie() 
{
    for (int i = 0; i < rozmiar; i++)
    {
        int element = generujLosowaWartosc(0, 100);
        tablica[i] = element;
    }
}

//Specjalizacja metody specializedMethodUzupelnienie() dla typu float
template <>
void TablicaSzablonowa <float>::specializedMethodUzupelnienie() 
{
    for (int i = 0; i < rozmiar; i++)
    {
        float element = generujLosowaWartosc(0.0f, 100.0f);
        tablica[i] = element;
    }
}

//Specjalizacja metody specializedMethodUzupelnienie() dla typu bool
template <>
void TablicaSzablonowa <bool>::specializedMethodUzupelnienie() 
{
    for (int i = 0; i < rozmiar; i++)
    {
        int element = generujLosowaWartosc(0, 1);
        tablica[i] = element;
    }
}

//Specjalizacja metody specializedMethodUzupelnienie() dla typu char
template <>
void TablicaSzablonowa <char>::specializedMethodUzupelnienie() 
{
    for (int i = 0; i < rozmiar; i++) 
    {
        char element = generujLosowaWartosc('a', 'z');
        tablica[i] = element;
    }
}

//Specjalizacja metody dla typu string
template <>
void TablicaSzablonowa <string>::specializedMethodUzupelnienie() 
{
    for (int i = 0; i < rozmiar; i++)
    {
        string element = generujLosowaWartosc<string>("", "");
        tablica[i] = element;
    }
}
