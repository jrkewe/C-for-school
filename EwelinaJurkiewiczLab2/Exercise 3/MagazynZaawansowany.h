#pragma once
#include <iostream>
#include "Magazyn.h"
using namespace std;

class MagazynZaawansowany : public Magazyn
{
public:
	// Konstruktor
	MagazynZaawansowany(int maksPojemnosc) : Magazyn(maksPojemnosc) {}

	void operacjaNaProduktach() const override;

	//Zwraca laczna wartosc zapasow w magazynie, sumujac cene jednostkowe pomnozone przez ilosc dla kazdego produktu
	double wartoscZapasu() const;

	//Sortuje produkty w magazynie wedlug ceny jednostkowej(od najwyzszej do najnizszej)
	void sortujPoCenie() const;
};
