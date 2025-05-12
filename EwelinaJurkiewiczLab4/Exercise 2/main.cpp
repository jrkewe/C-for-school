#pragma once
#include <iostream>
#include <random>
#include "GeneratorLiczb.h"
using namespace std;

//Losowe wartosci
int randomLiczba;
int randomSize;

int main() {
    cout << "***********************************************************" << endl;
    cout << "Program losuje i segreguje liczby na parzyste i nieparzyste" << endl;
    cout << "***********************************************************" << endl << endl;

    //Obiekt wektora
    vector <int> wektor;

    //Generowanie wektora
    for (int i = 0 ; i<10 ; i++) 
    {
        randomLiczba = generujLosowaWartosc(-50, 50);

        //Segregacja
        if (randomLiczba % 2)
        {
            wektor.push_back(randomLiczba);
        }
        else
        {
            wektor.insert(wektor.begin(), randomLiczba);
        }
    }

    //Wyswietl wektor
    for (int i=0;i<wektor.size();i++) 
    {
        cout << wektor[i] << " ";
    }
    cout << endl;


    cout << endl << "Koniec programu." << endl;
    cout << "Ewelina Jurkiewicz, Gr. 5." << endl;

    return 0;
}