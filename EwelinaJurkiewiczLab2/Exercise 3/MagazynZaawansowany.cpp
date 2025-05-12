#pragma once
#include <iostream>
#include "Magazyn.h"
#include "MagazynZaawansowany.h"
using namespace std;

void MagazynZaawansowany::operacjaNaProduktach() const
{
	wartoscZapasu();
	sortujPoCenie();
}

//Zwraca laczna wartosc zapasow w magazynie, sumujac cene jednostkowe pomnozone przez ilosc dla kazdego produktu
double MagazynZaawansowany::wartoscZapasu() const
{
	double wartosc = 0.0f;
	for (int i = 0;i < rozmiar;i++)
	{
		wartosc += produkty[i]->getCena() * produkty[i]->getIlosc();
	}

	cout << wartosc << endl;
	return wartosc;
}

//Sortuje produkty w magazynie wedlug ceny jednostkowej(od najwyzszej do najnizszej)
void MagazynZaawansowany::sortujPoCenie() const
{
	for (int i = 0;i < rozmiar - 1;i++)
	{
		for (int j = 0;j < rozmiar - i - 1;j++)
		{
			if (produkty[j]->getCena() < produkty[j + 1]->getCena())
			{
				Produkt* tymczasowy = produkty[j];
				produkty[j] = produkty[j + 1];
				produkty[j + 1] = tymczasowy;
			}
		}
	}
}
