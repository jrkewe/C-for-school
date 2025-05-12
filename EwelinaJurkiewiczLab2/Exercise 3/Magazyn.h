#pragma once
#include <iostream>
#include "Produkt.h"
#include "Magazyn.h"
using namespace std;

class Magazyn {
protected:
	Produkt** produkty;
	int rozmiar;
	int pojemnosc;

public:

	//Konstruktor, który przyjmuje rozmiar magazynu(pojemnosc) i tworzy tablice o odpowiedniej wielkosci
	Magazyn(int maxPojemnosc) : rozmiar(0), pojemnosc(maxPojemnosc)
	{
		produkty = new Produkt* [pojemnosc];
		for (int i = 0;i < pojemnosc;i++)
		{
			produkty[i] = nullptr;
		}
	}

	//Destruktor, który zwolni pamiec zaalokowana na tablicy produktow
	virtual ~Magazyn()
	{
		for (int i = 0;i < pojemnosc;i++)
		{
			delete produkty[i];
		}
		delete produkty;
	}

	//Dodaje nowy produkt do magazynu, zwiekszajac licznik produktow, ale tylko wtedy, gdy jest jeszcze miejsce w magazynie
	void dodajProdukt(const Produkt& produkt);

	//Usuwa produkt o podanej nazwie(jezli taki istnieje) i aktualizuje tablice produktow
	bool usunProdukt(const std::string& nazwa);

	//Zaimplementuje klasy pochodne (np.obliczanie wartosci zapasu lub sortowanie produktow)
	virtual void operacjaNaProduktach() const = 0;

	void wyswietlProdukty() const;
};

