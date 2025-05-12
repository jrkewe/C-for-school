#pragma once
#include <iostream>
#include <random>
#include "Magazyn.h"
#include "MagazynZaawansowany.h"
#include "Produkt.h"
using namespace std;

//Tablica nazw
string nazwyMeta[3] = {"Meta Quest 3", "Meta Quest 2","Meta Quest Pro"};
string nazwyApple[3] = {"Apple Vision Pro", "Apple Vision Pro", "Apple Vision Pro"};
string nazwyPico[3] = {"Pico 4", "Pico 4 Pro", "Pico 4 Ultra"};
string nazwyHTC[3] = {"HTC Vive XR Elite", "HTC Vive Pro 2", "HTC Vive Cosmos Elite"};

//Rozmiary magazynow
const int rozmiarMagaznow = 3;

//Ilosc
int minIlosc = 0;
int maxIlosc = 2;

//Ceny Meta
float minCenaMeta = 1300;
float maxCenaMeta = 2200;
//Ceny Apple
float minCenaApple = 15400;
float maxCenaApple = 24000;
//Ceny Pico
float minCenaPico = 1930;
float maxCenaPico = 3270;
//Ceny HTC
float minCenaHTC = 4800;
float maxCenaHTC = 6800;

//Rozmiary magazynow
int rozmiarMagazynu = 3;

//Losowe wartosci
int losowaIloscProduktow;
float losowaCenaMeta;
float losowaCenaApple;
float losowaCenaPico;
float losowaCenaHTC;
int losowyIndex;

// Generator losowy
float generujLosowaLiczbe(float min, float max)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dist(min, max);
    return dist(gen);
}

int main() {

    cout << "***************************************************************" << endl;
    cout << "Program wylicza wartosc produktow w magazynach z produktami VR" << endl;
    cout << "***************************************************************" << endl << endl;

    MagazynZaawansowany* magazynMeta = new MagazynZaawansowany(rozmiarMagazynu);
    MagazynZaawansowany* magazynApple = new MagazynZaawansowany(rozmiarMagazynu);
    MagazynZaawansowany* magazynPico = new MagazynZaawansowany(rozmiarMagazynu);
    MagazynZaawansowany* magazynHTC = new MagazynZaawansowany(rozmiarMagazynu);

    //Rozpoczecie sekwencji losowania
    srand(static_cast<unsigned>(time(0)));

    //Dodawanie produktów
    for (int i = 0;i < rozmiarMagazynu;i++) 
    {
        //Losowe ceny
        losowaCenaMeta = generujLosowaLiczbe(minCenaMeta, maxCenaMeta);
        losowaCenaApple = generujLosowaLiczbe(minCenaApple, maxCenaApple);
        losowaCenaPico = generujLosowaLiczbe(minCenaPico, maxCenaPico);
        losowaCenaHTC = generujLosowaLiczbe(minCenaHTC, maxCenaHTC);
        
        //Meta
        losowaIloscProduktow = generujLosowaLiczbe(minIlosc, maxIlosc);
        magazynMeta->dodajProdukt(Produkt(nazwyMeta[i], losowaIloscProduktow, losowaCenaMeta));

        //Apple
        losowaIloscProduktow = generujLosowaLiczbe(minIlosc, maxIlosc);
        magazynApple->dodajProdukt(Produkt(nazwyApple[i], losowaIloscProduktow, losowaCenaApple));

        //Pico
        losowaIloscProduktow = generujLosowaLiczbe(minIlosc, maxIlosc);
        magazynPico->dodajProdukt(Produkt(nazwyPico[i], losowaIloscProduktow, losowaCenaPico));

        //HTC
        losowaIloscProduktow = generujLosowaLiczbe(minIlosc, maxIlosc);
        magazynHTC->dodajProdukt(Produkt(nazwyHTC[i], losowaIloscProduktow, losowaCenaHTC));
    }

    //Test przekroczenia pojemnosci magazynu HTC
    cout << "Test przekroczenia pojemnosci magazynu HTC: " << endl;
    magazynHTC->dodajProdukt(Produkt(nazwyHTC[1], 1, losowaCenaHTC));
    cout << "---------------------------------------------------------------" << endl;

    //Stan magazynow przed aktualizacja
    cout << "Stan magazynow:" << endl << endl;;

    //Obliczanie wartosci zapasu i sortowanie po cenie
    cout << "Wartosc magazyn Meta: ";
    magazynMeta->operacjaNaProduktach();
    magazynMeta->wyswietlProdukty();
    cout << endl;

    cout << "Wartosc magazyn Apple: ";
    magazynApple->operacjaNaProduktach();
    magazynApple->wyswietlProdukty();
    cout << endl;

    cout << "Wartosc magazyn Pico: ";
    magazynPico->operacjaNaProduktach();
    magazynPico->wyswietlProdukty();
    cout << endl;

    cout << "Wartosc magazyn HTC: ";
    magazynHTC->operacjaNaProduktach();
    magazynHTC->wyswietlProdukty();
    cout << endl;
    cout << "---------------------------------------------------------------" << endl;

    //Usuwanie obiektow z magazynow 
    cout << "Usuwanie produktow z magazynow:" << endl << endl;
    losowyIndex = losowaIloscProduktow = generujLosowaLiczbe(0, 2);
    magazynMeta->usunProdukt(nazwyMeta[losowyIndex]);
    magazynApple->usunProdukt(nazwyApple[losowyIndex]);
    magazynPico->usunProdukt(nazwyPico[losowyIndex]);
    magazynHTC->usunProdukt(nazwyHTC[losowyIndex]);
    cout << endl;

    cout << "---------------------------------------------------------------" << endl;

    //Stan magazynow po aktualizacji
    cout << "Stan magazynow po aktualizacji:" << endl <<endl;

    //Obliczanie wartosci zapasu i sortowanie po cenie
    cout << "Wartosc magazyn Meta: ";
    magazynMeta->operacjaNaProduktach();
    magazynMeta->wyswietlProdukty();
    cout << endl;

    cout << "Wartosc magazyn Apple: ";
    magazynApple->operacjaNaProduktach();
    magazynApple->wyswietlProdukty();
    cout << endl;

    cout << "Wartosc magazyn Pico: ";
    magazynPico->operacjaNaProduktach();
    magazynPico->wyswietlProdukty();
    cout << endl;

    cout << "Wartosc magazyn HTC: ";
    magazynHTC->operacjaNaProduktach();
    magazynHTC->wyswietlProdukty();
    cout << endl;

    //Dealokacja
    delete magazynMeta;
    delete magazynApple;
    delete magazynPico;
    delete magazynHTC;

    cout << "---------------------------------------------------------------" << endl;

    cout << "Koniec programu." << endl;
    cout << "Ewelina Jurkiewicz, Gr. 5." << endl;
    return 0;
}
