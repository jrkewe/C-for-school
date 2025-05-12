#pragma once
#include <iostream>
#include "Magazyn.h"
using namespace std;

//Dodaje nowy produkt do magazynu, zwiekszajac licznik produktow,
//ale tylko wtedy, gdy jest jeszcze miejsce w magazynie
void Magazyn::dodajProdukt(const Produkt& produkt)
{
	if (rozmiar < pojemnosc)
	{
		produkty[rozmiar] = new Produkt(produkt);
		rozmiar++;
	}
	else
	{
		cout << "Magazyn jest pelny" << endl;
	}
}

//Usuwa produkt o podanej nazwie(jezli taki istnieje) i aktualizuje tablice produktow
bool Magazyn::usunProdukt(const string& nazwa)
{
	for (int i = 0;i < rozmiar;i++)
	{
		if (produkty[i]->getNazwa() == nazwa)
		{
			cout << "Usunieto produkt: " << produkty[i]->getNazwa() << endl;
			delete produkty[i];
			//Aktualizacja - przesuniecie
			produkty[i] = produkty[rozmiar - 1];
			produkty[rozmiar - 1] = nullptr;
			rozmiar--;
			return true;
		}
	}
	cout << "Produkt nie istnieje" << endl;
	return false;
}

void Magazyn::wyswietlProdukty() const 
{
	for (int i = 0; i < rozmiar; i++) 
	{
		if (produkty[i]->getIlosc() != 0) 
		{
			produkty[i]->wyswietl();
			cout << endl;
		}
	}
}
